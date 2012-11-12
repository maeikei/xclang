# parse help text.
$all_options = []
def parsetext(help)
    one_opt = []
    startsave = false
    help.each do |line|
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

p $all_options

