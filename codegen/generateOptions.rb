# parse help text.
$all_options = []
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

$all_options_arranged = []
$all_options.uniq!()
$all_options.each do |opt|
    # option names.
    arranged = []
    optname = opt[0].split(/ /)[2]
    arranged << optname
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
p $all_options_arranged
