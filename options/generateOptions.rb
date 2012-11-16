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
        type = "iConstOptionTypeAlone"
        if optname =~ /=<[\w]+>/ then
            type = "iConstOptionTypeEQValue | #{type}"
        end
        if optname =~ /,<[\w]+>/ then
            type = "iConstOptionTypeCommaValue | #{type}"
        end
        if optname =~ /-<[\w]+>/ then
            type = "iConstOptionTypeBarValue | #{type}"
        end
        if optname =~ /<[\w]+>/ then
            type = "iConstOptionTypeValue| #{type}"
        end
        if opt[0].split(/\s/)[3..10].to_s =~ /<[\w]+>/ then
            type = "iConstOptionTypeNextValue| #{type}"
        end
        real_opt = get_real_opt(optname)
        arranged[real_opt] = type
    end
end
$clang_options_arranged = {}
$clang_cc_options_arranged = {}

arrange_options($clang_options,$clang_options_arranged)
arrange_options($clang_cc_options,$clang_cc_options_arranged)

def gen_initialize_list(opts,out)
    opts.each do |key,type|
        out << "{\"#{key}\",#{type}}",
    end
end

$out_header_clang_options = ""
$out_header_clang_cc1_options = ""
gen_initialize_list($clang_options_arranged,$out_header_clang_options)
gen_initialize_list($clang_cc_options_arranged,$out_header_clang_cc1_options)

#p $clang_options_arranged
#p $clang_cc_options_arranged

#p $all_options_arranged

#p $clang_options_arranged.length
#p $clang_cc_options_arranged.length
#p $all_options_arranged.length


$out_option_desc = ""
$out_vm_count = ""
$out_header_members = ""
$out_header_methods = ""
def add_options()
    $all_options_arranged.each do |key,opt|
        out_opt = ""
        #        p key
        #p opt
        last_opt_name = ""
        if opt[2].include? '--' then
            last_opt_name = "\"#{opt[1]}\""
        else
            last_opt_name <<"\"#{opt[1]}\""
        end
        out_opt << last_opt_name
        # options
        $out_option_desc << "#{$TAB}#{$TAB}#{$TAB}(#{out_opt},"
        # values
        var_member = ""
        if opt[2].include? ',<>' then
            varname = opt[1].gsub(/-/,"_").gsub(/###/,"spspsp").gsub(/\+\+/,"plusplus")
            var_member << "string m_#{varname};"
            $out_option_desc << "po::value<string>(),"
        elsif opt[2].include? '=<>' then
            varname = opt[1].gsub(/-/,"_").gsub(/###/,"spspsp").gsub(/\+\+/,"plusplus")
            var_member << "string m_#{varname};"
            $out_option_desc << "po::value<string>(),"
        elsif opt[2].include? '-<>' then
            varname = opt[1].gsub(/-/,"_").gsub(/###/,"spspsp").gsub(/\+\+/,"plusplus")
            var_member << "string m_#{varname};"
            $out_option_desc << "po::value<string>(),"
        elsif opt[2].include? '<>' then
            varname = opt[1].gsub(/-/,"_").gsub(/###/,"spspsp").gsub(/\+\+/,"plusplus")
            var_member << "string m_#{varname};"
            $out_option_desc << "po::value<string>(),"
        elsif not opt[3].empty? then
            varname = opt[1].gsub(/-/,"_").gsub(/###/,"spspsp").gsub(/\+\+/,"plusplus")
            var_member << "string m_#{varname};"
            $out_option_desc << "po::value<string>(),"
        end
        if var_member.empty? then
            varname = opt[1].gsub(/-/,"_").gsub(/###/,"spspsp").gsub(/\+\+/,"plusplus")
            var_member << "bool m_#{varname};"
            $out_header_members << "#{$TAB}#{$TAB}#{var_member}\n"
            $out_header_methods << "#{$TAB}#{$TAB}bool has_#{varname}(void) const {\n"
            $out_header_methods << "#{$TAB}#{$TAB}#{$TAB}return m_#{varname};\n"
            $out_header_methods << "#{$TAB}#{$TAB}}\n"

            # check & get values
            $out_vm_count << "#{$TAB}#{$TAB}if(vm.count(#{last_opt_name})){\n"
            $out_vm_count << "#{$TAB}#{$TAB}#{$TAB}m_#{varname} = true;\n"
            $out_vm_count << "#{$TAB}#{$TAB}}\n"

        else
            $out_header_members << "#{$TAB}#{$TAB}#{var_member}\n"
            $out_header_methods << "#{$TAB}#{$TAB}bool has_#{varname}(void) const {\n"
            $out_header_methods << "#{$TAB}#{$TAB}#{$TAB}return m_#{varname}.empty();\n"
            $out_header_methods << "#{$TAB}#{$TAB}}\n"
            $out_header_methods << "#{$TAB}#{$TAB}string get_#{varname}(void) const {\n"
            $out_header_methods << "#{$TAB}#{$TAB}#{$TAB}return m_#{varname};\n"
            $out_header_methods << "#{$TAB}#{$TAB}}\n"

            # check & get values
            $out_vm_count << "#{$TAB}#{$TAB}if(vm.count(#{last_opt_name})){\n"
            $out_vm_count << "#{$TAB}#{$TAB}#{$TAB}m_#{varname} = vm[\"#{opt[1]}\"].as<string>();\n"
            $out_vm_count << "#{$TAB}#{$TAB}}\n"
        end
        
        # help text
        helptext = "#{opt[4]}#{opt[5].to_s}".gsub(/\"/,"\\\"")
        $out_option_desc << "\"#{helptext}\""
        $out_option_desc << ")\n"
        
        
    end
end

add_options

#print $out_option_desc
#print $out_vm_count
#print $out_header_members
#print $out_header_methods



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

$source_file = ""
File.open("options_autogen_orig.cpp").each do |line|
    if line =~ /repleace_option_desc/ then
        $source_file << $out_option_desc
    elsif line =~ /repleace_vm_count/ then
        $source_file << $out_vm_count
    else
        $source_file << line
    end
end
File.open("optionsautogen.cpp", 'w') do|f|
    f.write($source_file)
end


