$TAB="    "

# parse help text.
$all_options = []
$all_options_arranged = []


def parsetext(help)
    one_opt = []
    startsave = false
    help.split(/\n/).each do |line|
        if line =~ /^  -/ then
            if startsave then
                $all_options << one_opt
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

parsetext(`clang --help`)
parsetext(`clang -cc1 --help`)


def get_real_opt(opt)
    opt.gsub(/^-/,"").gsub(/^-/,"").gsub(/=<[\w]+>/,"").gsub(/,<[\w]+>/,"").gsub(/-<[\w]+>/,"").gsub(/<[\w]+>/,"")
end

$all_options.uniq!()
$all_options.each do |opt|
    # option names.
    arranged = []
    optname = opt[0].split(/ /)[2]
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
    arranged << optname
    arranged << get_real_opt(optname)
    arranged << attr
    
    remain = opt[0].gsub("#{optname}","")
    remain_values = remain.scan(/<[\w]+>/)
    if not remain_values.empty? then
        arranged << remain_values
        else
        arranged << ""
    end
    
    arranged << remain
    len = arranged.length
    arranged << opt[1..len]
    $all_options_arranged << arranged
end
#p $all_options_arranged


$out_option_desc = ""
$out_vm_count = ""
$out_header_members = ""
$out_header_methods = ""
def add_options()
    $all_options_arranged.each do |opt|
        out_opt = ""
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
            varname = opt[1].gsub(/-/,"_")
            var_member << "string m_#{varname};"
            $out_option_desc << "value(&m_#{varname}),"           
        elsif opt[2].include? '=<>' then
            varname = opt[1].gsub(/-/,"_")
            var_member << "string m_#{varname};"
            $out_option_desc << "value(&m_#{varname}),"
        elsif opt[2].include? '-<>' then
            varname = opt[1].gsub(/-/,"_")
            var_member << "string m_#{varname};"
            $out_option_desc << "value(&m_#{varname}),"
        elsif opt[2].include? '<>' then
            varname = opt[1].gsub(/-/,"_")
            var_member << "string m_#{varname};"
            $out_option_desc << "value(&m_#{varname}),"
        elsif not opt[3].empty? then
            varname = opt[1].gsub(/-/,"_")
            var_member << "string m_#{varname};"
            $out_option_desc << "value(&m_#{varname}),"
        end
        if var_member.empty? then
            varname = opt[1].gsub(/-/,"_")
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
            $out_header_methods << "#{$TAB}#{$TAB}#{$TAB}return m_#{varname}.empty();\n"
            $out_header_methods << "#{$TAB}#{$TAB}}\n"

            # check & get values
            $out_vm_count << "#{$TAB}#{$TAB}if(vm.count(\"#{opt[1]}\")){\n"
            $out_vm_count << "#{$TAB}#{$TAB}#{$TAB}m_#{varname} = vm[\"#{opt[1]}\"].as<string>();\n"
            $out_vm_count << "#{$TAB}#{$TAB}}\n"
        end
        
        # help text
        $out_option_desc << "\"#{opt[4]}#{opt[5].to_s}\""
        $out_option_desc << ")\n"
        
        
    end
end

add_options

print $out_option_desc
print $out_vm_count
print $out_header_members
print $out_header_methods
