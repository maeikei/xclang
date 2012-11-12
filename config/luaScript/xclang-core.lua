---------------------------------------------------
-- be careful to modify this file. 
---------------------------------------------------
if nil ~= globalXClangDebugEnv then
	for i,v in pairs(xclang.toolchain) do
		print(i,v)
	end
	for i,v in pairs(xclang.stdinc) do
		print(i,v)
	end
	for i,v in pairs(xclang.stdincxx) do
		print(i,v)
	end
end
---------------------------------------------------
-- add log file to command lines. 
---------------------------------------------------
function xclang_common_append_log(logs,overwrite)
	local flags=">>"
	if overwrite then
		flags=">"
	end
	local cmd = " 1"..flags..logs
	if XCLANG_WIN then
		cmd = cmd.." 2"..flags.."&1"
	else
		cmd = cmd.." 2"..flags..logs
	end
	return cmd
end

---------------------------------------------------
-- out put orignal log command. 
-- 
---------------------------------------------------
function xclang_cmd_log(cmd)
	if nil ~= globalXClangDebug then
		print(cmd)
	end
	local fLog = io.open(globalXClangHome.."/command.lua.log","a")
	if fLog then
		fLog:write(cmd.."\n")
		fLog:flush()
		fLog:close()
	end
end

---------------------------------------------------
-- run command. 
-- 
---------------------------------------------------
function xclang_common_exec(cmd)
	globalExeCmd = globalExeCmd..cmd.."\n"
	if nil ~= globalXClangDebug then
		print(globalExeCmd)
	end
	local fLog = io.open(globalXClangHome.."/command.lua.log","a")
	if fLog then
		fLog:write(globalExeCmd.."\n")
		fLog:flush()
		fLog:close()
	end
	local ret = os.execute(cmd)
	globalExeRet = ret
	return ret
end


---------------------------------------------------
-- show parames. 
-- 
---------------------------------------------------
function show_papamer(src,obj,ldflag,nostartfiles,nostdlib,nodefaultlibs)
	local fLog = io.open(globalXClangHome.."/command.lua.log","a")
	if fLog then
		fLog:write("src-------------->"..tostring(src).."\n")
		fLog:write("obj-------------->"..tostring(obj).."\n")
		fLog:write("ldflag----------->"..tostring(ldflag).."\n")
		fLog:write("nostartfiles----->"..tostring(nostartfiles).."\n")
		fLog:write("nostdlib--------->"..tostring(nostdlib).."\n")
		fLog:write("nodefaultlibs---->"..tostring(nodefaultlibs).."\n")
		fLog:flush()
		fLog:close()
	end
end


---------------------------------------------------
-- clang binutils prefix command. 
---------------------------------------------------
function xclang_bin_prefix(prog)
	globalExeCmd = ""
	local cmd = xclang.toolchain[prog].." "
	print(cmd)
end


---------------------------------------------------
-- clang version show command. 
---------------------------------------------------
function xclang_version()
	globalExeCmd = ""
	local cmd = clang.llvm.cc.." "
	cmd = cmd.." --version "
	ret = xclang_common_exec(cmd)
	if 0 ~= ret then
		return
	end
end




---------------------------------------------------
-- clang dll command. 
---------------------------------------------------
function xclang_dll(src,obj)
	globalExeCmd = ""
	local cmd = xclang.toolchain.dlltool.." "
	cmd = cmd.."--input-def "
	cmd = cmd.." "..src.." "
	cmd = cmd.." --output-exp "
	cmd = cmd..obj.." "
	ret = xclang_common_exec(cmd)
	if 0 ~= ret then
		return
	end
end




---------------------------------------------------
-- clang cc1 as command. 
---------------------------------------------------
function xclang_cc1as(src,obj,cflag,action,nostdinc,nostdincxx)
	globalExeCmd = ""
	local cmd = clang.llvm.cc1as.." "
	cmd = cmd.."-triple "
	cmd = cmd..xclang.triple.." "
	cmd = cmd.."-filetype obj "
	cmd = cmd.." -o "
	cmd = cmd..obj.." "
	cmd = cmd..cflag.." "
	cmd = cmd.." "..src.." "
	ret = xclang_common_exec(cmd)
	if 0 ~= ret then
		return
	end
end


---------------------------------------------------
-- clang assembler-with-cpp command. 
---------------------------------------------------
local defaultasmcppcflags = table.concat(clang.defaultasmcppcflags," ")
local stdcoption = table.concat(xclang.stdcoption," ")
local cmdctype = table.concat(xclang.cmdctype," ")
local stdinc = table.concat(xclang.stdinc," -I ")
stdinc = "-I "..stdinc
local stdcflags = table.concat(xclang.stdcflags," ")
function xclang_asm_cpp(src,obj,cflag,action,nostdinc,nostdincxx)
	globalExeCmd = ""
	local cmd = clang.llvm.cc.." "
	cmd = cmd..stdcoption.." "
	cmd = cmd..action.." "
	cmd = cmd..defaultasmcppcflags.." "
	if not nostdinc then
		cmd = cmd..stdinc.." "
	end
	cmd = cmd..stdcflags.." "
	cmd = cmd..cflag.." "
	cmd = cmd.." -o "
	cmd = cmd..obj.." "
	cmd = cmd..cmdctype
	cmd = cmd.." "..src.." "
	ret = xclang_common_exec(cmd)
	if 0 ~= ret then
		return
	end
end


---------------------------------------------------
-- clang cc1 c command. 
---------------------------------------------------
local defaultcflags = table.concat(clang.defaultcflags," ")
local stdcoption = table.concat(xclang.stdcoption," ")
local cmdctype = table.concat(xclang.cmdctype," ")
local stdinc = table.concat(xclang.stdinc," -I ")
stdinc = "-I "..stdinc
local stdcflags = table.concat(xclang.stdcflags," ")
function xclang_cc1(src,obj,cflag,action,nostdinc,nostdincxx)
	globalExeCmd = ""
	local cmd = clang.llvm.cc.." "
	cmd = cmd..stdcoption.." "
	cmd = cmd..action.." "
	cmd = cmd..defaultcflags.." "
	if not nostdinc then
		cmd = cmd..stdinc.." "
	end
	cmd = cmd..stdcflags.." "
	cmd = cmd..cflag.." "
	cmd = cmd.." -o "
	cmd = cmd..obj.." "
	cmd = cmd..cmdctype
	cmd = cmd.." "..src.." "
	ret = xclang_common_exec(cmd)
	if 0 ~= ret then
		return
	end
end



---------------------------------------------------
-- clang cc1 c++ command.
---------------------------------------------------
local defaultcxxflags = table.concat(clang.defaultcxxflags," ")
local stdcxxoption = table.concat(xclang.stdcxxoption," ")
local cmdcxxtype = table.concat(xclang.cmdcxxtype," ")
local stdincxx = table.concat(xclang.stdincxx," -I ")
stdincxx = "-I "..stdincxx
local stdcxxflags = table.concat(xclang.stdcxxflags," ")
function xclang_cc1xx(src,obj,cxxflag,action,nostdinc,nostdincxx)
	globalExeCmd = ""
	local cmd = clang.llvm.cxx.." "
	cmd = cmd..stdcxxoption.." "
	cmd = cmd..action.." "
	cmd = cmd..defaultcxxflags.." "
	if not nostdinc then
		cmd = cmd..stdinc.." "
	end
	if not nostdincxx then
		cmd = cmd..stdincxx.." "
	end
	cmd = cmd..stdcxxflags.." "
	cmd = cmd..cxxflag.." "
	cmd = cmd.." -o "
	cmd = cmd..obj.." "
	cmd = cmd..cmdcxxtype
	cmd = cmd.." "..src.." "
	ret = xclang_common_exec(cmd)
	if 0 ~= ret then
		return
	end
end



---------------------------------------------------
-- archive static library. 
---------------------------------------------------
function xclang_ar(src,obj,arflag)
	globalExeCmd = ""
	local basefilename = obj.."_tmp"
	local cmd = xclang.toolchain.ar
	cmd = cmd.." cr"
	cmd = cmd.." "..obj
	cmd = cmd.." "..arflag
	cmd = cmd.." "..src
	ret = xclang_common_exec(cmd)
	if 0 ~= ret then
		return
	end
end




---------------------------------------------------
-- link options. 
---------------------------------------------------
local arch_begin_shared = table.concat(xclang.arch_begin_shared," ")
local arch_end_shared = table.concat(xclang.arch_end_shared," ")
local object_begin_shared = table.concat(xclang.object_begin_shared," ")
local object_end_shared = table.concat(xclang.object_end_shared," ")


local arch_begin_exe = table.concat(xclang.arch_begin_exe," ")
local arch_end_exe = table.concat(xclang.arch_end_exe," ")
local object_begin_exe = table.concat(xclang.object_begin_exe," ")
local object_end_exe = table.concat(xclang.object_end_exe," ")

local stdcldflags_s1 = table.concat(xclang.stdcldflags_s1," ")
local stdcldflags_s2 = table.concat(xclang.stdcldflags_s2," ")
local stdcxxldflags_s1 = table.concat(xclang.stdcxxldflags_s1," ")
local stdcxxldflags_s2 = table.concat(xclang.stdcxxldflags_s2," ")
local archcldflags_s1 = table.concat(xclang.archcldflags_s1," ")
local archcldflags_s2 = table.concat(xclang.archcldflags_s2," ")
local archcxxldflags_s1 = table.concat(xclang.archcxxldflags_s1," ")
local archcxxldflags_s2 = table.concat(xclang.archcxxldflags_s2," ")


---------------------------------------------------
-- link c shared library. 
---------------------------------------------------
function xclang_so(src,obj,ldflag,nostartfiles,nostdlib,nodefaultlibs)
	show_papamer(src,obj,ldflag,nostartfiles,nostdlib,nodefaultlibs)
	globalExeCmd = ""
	local cmd = xclang.toolchain.ld
	cmd = cmd.." "..arch_begin_shared
	cmd = cmd.." -o "..obj
	
	if not nostartfiles then
		cmd = cmd.." "..object_begin_shared
	end
	
	if not nostdlib then
		cmd = cmd.." "..stdcldflags_s1
	end
	cmd = cmd.." "..archcldflags_s1

	cmd = cmd.." "..src
	if not nostdlib then
		cmd = cmd.." "..stdcldflags_s2
	end
	cmd = cmd.." "..ldflag
	cmd = cmd.." "..archcldflags_s2
	
	if not nostartfiles then
		cmd = cmd.." "..object_end_shared
	end
	
	cmd = cmd.." "..arch_end_shared
	
	ret = xclang_common_exec(cmd)
	if 0 ~= ret then
		return
	end
end
---------------------------------------------------
-- link c++ shared library. 
---------------------------------------------------
function xclang_soxx(src,obj,ldflag,nostartfiles,nostdlib,nodefaultlibs)
	globalExeCmd = ""
	local cmd = xclang.toolchain.ld
	cmd = cmd.." "..arch_begin_shared
	cmd = cmd.." -o "..obj
	
	if not nostartfiles then
		cmd = cmd.." "..object_begin_shared
	end
	
	if not nostdlib then
		cmd = cmd.." "..stdcxxldflags_s1
	end
	cmd = cmd.." "..archcxxldflags_s1

	cmd = cmd.." "..src
	if not nostdlib then
		cmd = cmd.." "..stdcxxldflags_s2
	end
	cmd = cmd.." "..ldflag
	cmd = cmd.." "..archcxxldflags_s2
	
	if not nostartfiles then
		cmd = cmd.." "..object_end_shared
	end
	
	cmd = cmd.." "..arch_end_shared
	
	ret = xclang_common_exec(cmd)
	if 0 ~= ret then
		return
	end
end
---------------------------------------------------
-- link c execute. 
---------------------------------------------------
function xclang_exe(src,obj,ldflag,nostartfiles,nostdlib,nodefaultlibs)
	globalExeCmd = ""
	local cmd = xclang.toolchain.ld
	cmd = cmd.." "..arch_begin_exe
	cmd = cmd.." -o "..obj
	
	if not nostartfiles then
		cmd = cmd.." "..object_begin_exe
	end
	
	if not nostdlib then
		cmd = cmd.." "..stdcldflags_s1
	end
	cmd = cmd.." "..archcldflags_s1

	cmd = cmd.." "..src
	if not nostdlib then
		cmd = cmd.." "..stdcldflags_s2
	end
	cmd = cmd.." "..ldflag
	cmd = cmd.." "..archcldflags_s2
	
	if not nostartfiles then
		cmd = cmd.." "..object_end_exe
	end
	
	cmd = cmd.." "..arch_end_exe
	
	ret = xclang_common_exec(cmd)
	if 0 ~= ret then
		return
	end
end
---------------------------------------------------
-- link c++ execute. 
---------------------------------------------------
function xclang_exexx(src,obj,ldflag)
	globalExeCmd = ""
	local cmd = xclang.toolchain.ld
	cmd = cmd.." "..arch_begin_exe
	cmd = cmd.." -o "..obj
	
	if not nostartfiles then
		cmd = cmd.." "..object_begin_exe
	end
	
	if not nostdlib then
		cmd = cmd.." "..stdcxxldflags_s1
	end
	cmd = cmd.." "..archcxxldflags_s1

	cmd = cmd.." "..src
	if not nostdlib then
		cmd = cmd.." "..stdcxxldflags_s2
	end
	cmd = cmd.." "..ldflag
	cmd = cmd.." "..archcxxldflags_s2
	
	if not nostartfiles then
		cmd = cmd.." "..archcxxldflags
	end
	
	cmd = cmd.." "..arch_end_exe
	
	ret = xclang_common_exec(cmd)
	if 0 ~= ret then
		return
	end
end
---------------------------------------------------
-- custerm commond. 
---------------------------------------------------
function xclang_cust(cmd)
	globalExeCmd = cmd
	ret = xclang_common_exec(cmd)
	if 0 ~= ret then
		return
	end
end

