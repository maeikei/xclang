$LUA_SCRIPT_HOME='../share'

`find #{$LUA_SCRIPT_HOME} -type f -name *.lua`.split(/\n/).each do |arch|
	prefix = File::basename(arch,'.lua')
	if 'xclang-llvm' == prefix
		next
	end
	
run_shell = <<EOS
#!/bin/bash
xclang_path=<echo dollar0 | sed -e "s/#{prefix}-//">
dollar(xclang_path) --xclang-target #{prefix} "dollar@"
EOS
	run_shell.gsub!(/</,"`")
	run_shell.gsub!(/>/,"`")
	run_shell.gsub!(/\(/,"{")
	run_shell.gsub!(/\)/,"}")
	run_shell.gsub!(/dollar/,"$")
	open("shell/#{prefix}-xclang","w") { |f| f.write run_shell }
	open("shell/#{prefix}-xclang++","w") { |f| f.write run_shell }

run_bat = <<EOS
@set pwd_path=%~dp0
@set xclang_path=%pwd_path%xclang.exe
@"%xclang_path%" --xclang-target x86_64-pc-linux-gnueabi "%@"
EOS
        open("bat/#{prefix}-xclang.bat","w") { |f| f.write run_bat }
        open("bat/#{prefix}-xclang++.bat","w") { |f| f.write run_bat }



end
