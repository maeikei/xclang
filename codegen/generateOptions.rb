$TAB="    "

# parse help text.
$all_options = []
$output_source_code = ""
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
    opt.gsub(/^-/,"").gsub(/^-/,"").gsub(/=<[\w]+>/,"").gsub(/,<[\w]+>/,"").gsub(/-<[\w]+>/,"")
end

$all_options.uniq!()
$all_options.each do |opt|
    # option names.
    arranged = []
    optname = opt[0].split(/ /)[2]
    remain = opt[0].gsub("#{optname}","")
    remain_values = remain.scan(/<[\w]+>/)
    if not remain_values.empty? then
        arranged << remain_values
    else
        arranged << ""
    end
    attr =[]
    if optname =~ /=<[\w]+>/ then
        attr << "=<>"
    end
    if optname =~ /,<[\w]+>/ then
        attr << ",<>"
    end
    if optname =~ /-<[\w]+>/ then
        attr << "-<>"
    end
    if optname =~ /^--/ then
        attr << "--"
    end
    arranged << optname
    arranged << get_real_opt(optname)
    arranged << attr
    
    arranged << remain
    len = arranged.length
    arranged << opt[1..len]
    $all_options_arranged << arranged
end
p $all_options_arranged


def add_options(out)
    out << "#{$TAB}try {\n"
    out << "#{$TAB}#{$TAB}po::options_description desc(\"Allowed options\");\n"
    out << "#{$TAB}#{$TAB}desc.add_options()\n"
    out << "#{$TAB}#{$TAB}(\"xclang-target\",value(&m_xclang_target) ,\"xclang target \")\n"
    $all_options_arranged.each do |opt|
        short_opt = opt[0].gsub(/^-/,"").gsub(/\n/,"")
        real_opt = get_real_opt(short_opt)
        out_opt = ""
        out_opt <<"#{real_opt}\""
        out << "#{$TAB}#{$TAB}(#{out_opt})\n"
    end
    out << "#{$TAB}#{$TAB};\n"
end

$output_source_code << "#include <options.hpp>\n"
$output_source_code << "using namespace xclang;\n"
$output_source_code << "#include <boost/program_options.hpp>\n"
$output_source_code << "namespace po = boost::program_options;\n"
$output_source_code << "#include <iostream>\n"
$output_source_code << "#include <iterator>\n"
$output_source_code << "using namespace std;\n"
$output_source_code << "void XClangOptions::parseArgs(void)\n"
$output_source_code << "{\n"

add_options($output_source_code)

$output_source_code << "#{$TAB}catch(exception& e) {\n"
$output_source_code << "#{$TAB}#{$TAB}cerr << \"error: \" << e.what() << \"\\n\";\n"
$output_source_code << "#{$TAB}}\n"
$output_source_code << "#{$TAB}catch(...) {\n"
$output_source_code << "#{$TAB}#{$TAB}cerr << \"Exception of unknown type!\\n\";\n"
$output_source_code << "#{$TAB}}\n"
$output_source_code << "}\n"

print $output_source_code
