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
    opt.gsub(/^-/,"").gsub(/^-/,"").gsub(/=<[\w]+>/,"").gsub(/,<[\w]+>/,"").gsub(/-<[\w]+>/,"").gsub(/<[\w]+>/,"")
end


def arrange_options(opt,arranged)
opt.each do |opt|
    # option names.
    optname = opt[0].split(/ /)[2]
    real_opt_name = get_real_opt(optname)
    if arranged.has_key?(real_opt_name) then
        next
    end
    arranged[real_opt_name] = []
    attr =[]
    value_check = true
    if optname =~ /=<[\w]+>/ then
        attr << "=<>"
        value_check = false
    end
    if optname =~ /,<[\w]+>/ then
        attr << ",<>"
        value_check = false
    end
    if optname =~ /-<[\w]+>/ then
        attr << "-<>"
        value_check = false
    end
    if optname =~ /<[\w]+>/ and value_check then
        attr << "<>"
    end
    if optname =~ /^--/ then
        attr << "--"
    end
    arranged[real_opt_name] << optname
    arranged[real_opt_name] << real_opt_name
    arranged[real_opt_name] << attr
    
    remain = opt[0].gsub("#{optname}","")
    remain_values = remain.scan(/<[\w]+>/)
    if not remain_values.empty? then
        arranged[real_opt_name] << remain_values
        else
        arranged[real_opt_name] << ""
    end
    
    arranged[real_opt_name] << remain
    len = arranged.length
    arranged[real_opt_name] << opt[1..len]
end
end
#p $all_options_arranged
$clang_options_arranged = {}
$clang_cc_options_arranged = {}

arrange_options($clang_options,$clang_options_arranged)
arrange_options($clang_cc_options,$clang_cc_options_arranged)

#p $clang_options_arranged
#p $clang_cc_options_arranged

$all_options_arranged = {}
arrange_options($clang_options,$all_options_arranged)
arrange_options($clang_cc_options,$all_options_arranged)
#p $all_options_arranged

#p $clang_options_arranged.length
#p $clang_cc_options_arranged.length
#p $all_options_arranged.length

$all_options_arranged = $all_options_arranged.sort

$out_option_desc = ""
$out_vm_count = ""
$out_header_members = ""
$out_header_methods = ""
def add_options()
    $all_options_arranged.each do |key,opt|
        out_opt = ""
        #        p key
        #p opt
        if opt[2].include? '--' then
            out_opt <<"\"#{opt[1]},#{opt[1]}\""
        else
            out_opt <<"\",#{opt[1]}\""
        end
        # options
        $out_option_desc << "#{$TAB}#{$TAB}#{$TAB}(#{out_opt},"
        # values
        var_member = ""
        if opt[2].include? ',<>' then
            varname = opt[1].gsub(/-/,"_").gsub(/###/,"spspsp").gsub(/\+\+/,"plusplus")
            var_member << "string m_#{varname};"
            $out_option_desc << "po::value(&m_#{varname}),"           
        elsif opt[2].include? '=<>' then
            varname = opt[1].gsub(/-/,"_").gsub(/###/,"spspsp").gsub(/\+\+/,"plusplus")
            var_member << "string m_#{varname};"
            $out_option_desc << "po::value(&m_#{varname}),"
        elsif opt[2].include? '-<>' then
            varname = opt[1].gsub(/-/,"_").gsub(/###/,"spspsp").gsub(/\+\+/,"plusplus")
            var_member << "string m_#{varname};"
            $out_option_desc << "po::value(&m_#{varname}),"
        elsif opt[2].include? '<>' then
            varname = opt[1].gsub(/-/,"_").gsub(/###/,"spspsp").gsub(/\+\+/,"plusplus")
            var_member << "string m_#{varname};"
            $out_option_desc << "po::value(&m_#{varname}),"
        elsif not opt[3].empty? then
            varname = opt[1].gsub(/-/,"_").gsub(/###/,"spspsp").gsub(/\+\+/,"plusplus")
            var_member << "string m_#{varname};"
            $out_option_desc << "po::value(&m_#{varname}),"
        end
        if var_member.empty? then
            varname = opt[1].gsub(/-/,"_").gsub(/###/,"spspsp").gsub(/\+\+/,"plusplus")
            var_member << "bool m_#{varname};"
            $out_header_members << "#{$TAB}#{$TAB}#{var_member}\n"
            $out_header_methods << "#{$TAB}#{$TAB}bool has_#{varname}(void) const {\n"
            $out_header_methods << "#{$TAB}#{$TAB}#{$TAB}return m_#{varname};\n"
            $out_header_methods << "#{$TAB}#{$TAB}}\n"

            # check & get values
            $out_vm_count << "#{$TAB}#{$TAB}if(vm.count(\"#{opt[1]}\")){\n"
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
            $out_vm_count << "#{$TAB}#{$TAB}if(vm.count(\"#{opt[1]}\")){\n"
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


