$TAB="    "

def parsetext(help,opt_array)
    one_opt = []
    startsave = false
    help.split(/\n/).each do |line|
        if line =~ /^  -/ then
            if startsave then
                opt_array << one_opt
            end
            startsave = true
            one_opt = []
            one_opt << line
        else
            if not startsave then
                next
            end
            one_opt << line
        end
    end    
end

$clang_options = []
$clang_cc_options = []
# parse help text.
parsetext(`clang --help`,$clang_options)
parsetext(`clang -cc1 --help`,$clang_cc_options)


def get_real_opt(opt)
    opt.gsub(/=<[\w]+>/,"").gsub(/,<[\w]+>/,"").gsub(/-<[\w]+>/,"").gsub(/<[\w]+>/,"")
end


def arrange_options(opt,arranged)
    opt.each do |opt|
        # option names.
        optname = opt[0].split(/\s/)[2]
        type = "iConstOptionTypeNone"
        type_r = []
        if optname =~ /=<[\w]+>/ then
            type = "iConstOptionTypeEQValue | #{type}"
            type_r <<'=<>'
        end
        if optname =~ /,<[\w]+>/ then
            type = "iConstOptionTypeCommaValue | #{type}"
            type_r <<',<>'
        end
        if optname =~ /-<[\w]+>/ then
            type = "iConstOptionTypeBarValue | #{type}"
            type_r <<'-<>'
        end
        if optname =~ /<[\w]+>/ then
            type = "iConstOptionTypeValue| #{type}"
            type_r <<'<>'
        end
        if opt[0].split(/\s/)[3..10].to_s =~ /<[\w]+>/ then
            type = "iConstOptionTypeNextValue| #{type}"
            type_r <<' <>'
        end
        if not type =~ /Value/ then
            type = "iConstOptionTypeAlone| #{type}"
        end
        real_opt = get_real_opt(optname)
        arranged[real_opt] = []
        arranged[real_opt] << type
        arranged[real_opt] << real_opt.gsub(/-/,"_").gsub(/###/,"spspsp").gsub(/\+\+/,"plusplus")
        arranged[real_opt] << type_r
    end
end
$clang_options_arranged = {}
$clang_cc_options_arranged = {}

arrange_options($clang_options,$clang_options_arranged)
arrange_options($clang_cc_options,$clang_cc_options_arranged)

def gen_initialize_list(opts,out)
    opts.sort.each do |key,type|
        out << "#{$TAB}(\"#{key}\",#{type[0]})\n"
    end
end

$out_clang_options = ""
$out_clang_cc1_options = ""
gen_initialize_list($clang_options_arranged,$out_clang_options)
gen_initialize_list($clang_cc_options_arranged,$out_clang_cc1_options)

#p $clang_options_arranged
#p $clang_cc_options_arranged
#p $all_options_arranged


$out_header_members = ""
$out_header_methods = ""
$out_intialize = ""
$out_parse_args = ""
def gen_member_list(opts)
    opts.sort.each do |key,type|
        if type[2].empty? then
            $out_header_members << "#{$TAB}#{$TAB}bool m#{type[1]};\n"

            $out_intialize << ",m#{type[1]}(false)\n"
                                                          
            $out_parse_args << "#{$TAB}it = m_real_options.find(\"#{key}\");\n"
            $out_parse_args << "#{$TAB}if( m_real_options.end() != it) {\n"
            $out_parse_args << "#{$TAB}#{$TAB}m#{type[1]} = true;\n"
            $out_parse_args << "#{$TAB}}\n"
                                                          
            $out_header_methods << "#{$TAB}#{$TAB}bool has#{type[1]}(void) const {\n"
            $out_header_methods << "#{$TAB}#{$TAB}#{$TAB}return m#{type[1]};\n"
            $out_header_methods << "#{$TAB}#{$TAB}}\n"
        else
            $out_header_members << "#{$TAB}#{$TAB}string m#{type[1]};\n"

            $out_intialize << ",m#{type[1]}(\"\")\n"
                                                          
            $out_parse_args << "#{$TAB}it = m_real_options.find(\"#{key}\");\n"
            $out_parse_args << "#{$TAB}if( m_real_options.end() != it) {\n"
            $out_parse_args << "#{$TAB}#{$TAB}m#{type[1]} = it->second;\n"
            $out_parse_args << "#{$TAB}}\n"
                               
            $out_header_methods << "#{$TAB}#{$TAB}bool has#{type[1]}(void) const {\n"
            $out_header_methods << "#{$TAB}#{$TAB}#{$TAB}return m#{type[1]}.empty();\n"
            $out_header_methods << "#{$TAB}#{$TAB}}\n"
            $out_header_methods << "#{$TAB}#{$TAB}string get#{type[1]}(void) const {\n"
            $out_header_methods << "#{$TAB}#{$TAB}#{$TAB}return m#{type[1]};\n"
            $out_header_methods << "#{$TAB}#{$TAB}}\n"
        end
    end
end


gen_member_list($clang_options_arranged.merge($clang_cc_options_arranged))


$header_file = ""
File.open("options_autogen_orig.hpp").each do |line|
    if line =~ /replace_header_members/ then
        $header_file << $out_header_members
    elsif line =~ /replace_header_methods/ then
        $header_file << $out_header_methods
    elsif line =~ /replace_header_clang_options/ then
        $header_file << $out_header_clang_options
    elsif line =~ /replace_header_clang_cc1_options/ then
        $header_file << $out_header_clang_cc1_options
    else
        $header_file << line
    end
end
File.open("options.hpp", 'w') do|f|
    f.write($header_file)
end
                                                          
$src_file = ""
File.open("options_autogen_orig.cpp").each do |line|
    if line =~ /replace_clang_options/ then
        $src_file << $out_clang_options
    elsif line =~ /replace_clang_cc1_options/ then
        $src_file << $out_clang_cc1_options
    elsif line =~ /replace_intialize/ then
        $src_file << $out_intialize
    elsif line =~ /replace_parse_args/ then
        $src_file << $out_parse_args
    else
        $src_file << line
    end
end

File.open("optionsautogen.cpp", 'w') do|f|
    f.write($src_file)
end



