---------------------------------------------------------
---be careful to modify this file.
---------------------------------------------------------
if nil == globalXClangHome then
	globalXClangHome = "/Volumes/DataHD/workspace/xclang-dev/obj/InstallRoot"
end
local clang_prefix = globalXClangHome.."/llvm/bin"
---------------------------------------------------------
---global setting of xclang envirment.
---------------------------------------------------------
clang =
{
	llvm =
	{
		cc1as	    = clang_prefix.."/clang -cc1as",
		cc		    = clang_prefix.."/clang",
		cxx		    = clang_prefix.."/clang++",
		opt		    = clang_prefix.."/opt",
		llc		    = clang_prefix.."/llc",
		lli		    = clang_prefix.."/lli",
		link	    = clang_prefix.."/llvm-link",
		mc		    = clang_prefix.."/llvm-mc",
		ld		    = clang_prefix.."/llvm-ld",
		nm		    = clang_prefix.."/llvm-nm",
		as		    = clang_prefix.."/llvm-as",
		config		= clang_prefix.."/llvm-config",
		dis		    = clang_prefix.."/llvm-dis",
		bcanalyzer	= clang_prefix.."/llvm-bcanalyzer",
		ar		    = clang_prefix.."/llvm-ar",
		prof		= clang_prefix.."/llvm-prof",
		ranlib		= clang_prefix.."/llvm-ranlib",
		extract		= clang_prefix.."/llvm-extract",
		stub		= clang_prefix.."/llvm-stub",
		diff		= clang_prefix.."/llvm-diff",
	},
	defaultasmcppcflags =
	{
		"-E -masm-verbose -x assembler-with-cpp",
		"-nostdinc",
	},
	defaultcflags =
	{
		"-x c",
		"-nostdinc",
	},
	defaultcxxflags =
	{
		"-x c++",
		"-nostdinc++",
	},
}

