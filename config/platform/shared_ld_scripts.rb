$PLATFORM_HOME='/Users/maeikei/workspace/xclang-dev/obj/InstallRoot/platform'
$g_ld_script_files = []
`find #{$PLATFORM_HOME} -type f -name *.so`.split(/\n/).each do |sofile|
    `file #{sofile} | grep "ASCII c program text"`.each do |ld_script|
        $g_ld_script_files << ld_script.split(/:/)[0]
    end
end

def changeGroup(ld_script,line)
    result = line
    #p "---**--------"
    #p ld_script
    line.split(/ /).each do |lib|
        if lib =~ /.so/ or lib =~ /.a/
            distlib = `find #{$PLATFORM_HOME} | grep #{lib}`.gsub(/\n/,'').gsub(/\r/,'')
            result.gsub!(lib,distlib)
        end
    end
    #p "---@@--------"
    result
end

$g_ld_script_files.each do |ld_script|
    outp_result = ""
    File.open(ld_script).each do |line|
        if line =~ /GROUP \( / then
            outp_result << changeGroup(ld_script,line)
        else
            outp_result << line
        end
    end
    File.open(ld_script,'w') do |f|
        f.write(outp_result)
    end
end
