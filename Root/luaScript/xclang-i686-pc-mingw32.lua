---------------------------------------------------------
-- global setting of xclang envirment.
---------------------------------------------------------
if nil == globalXClangHome then
	globalXClangHome = "C:/xclang-dev/xclang-obj/InstallRoot"
end
binutils_prefix = globalXClangHome.."/tools/binutils/i686-pc-mingw32/bin"
clang_prefix = globalXClangHome.."/tools/llvm/"
platform_prefix = globalXClangHome.."/platform/i686-pc-mingw32"
stdc_prefix = platform_prefix.."/mingwrt"
stdcxx_prefix = platform_prefix.."/mingwrt"

stdc_prefix_ext = platform_prefix.."/w32api"
stdcxx_prefix_ext = platform_prefix.."/w32api"


globalXClangDefaultOutPutName = "a.exe"
globalXClangOutputObjExtension = ".o"
globalXClangOutputAsmExtension = ".s"


xclang =
{
---------------------------------------------------
-- compile time options. 
---------------------------------------------------
	arch= "x86",
	triple= "i686-pc-mingw32",
	toolchain =
	{
		ar		= binutils_prefix.."/ar",
		as		= binutils_prefix.."/as",
		ld		= binutils_prefix.."/ld",
		nm		= binutils_prefix.."/nm",
		objcopy 	= binutils_prefix.."/objcopy",
		objdump 	= binutils_prefix.."/objdump",
		ranlib 		= binutils_prefix.."/ranlib",
		strip 		= binutils_prefix.."/strip",
		dlltool 	= binutils_prefix.."/dlltool",
	},
	cmdctype =
	{
	},
	cmdcxxtype =
	{
	},
	stdcoption =
	{
		"-triple i686-pc-mingw32",
	},
	stdcxxoption =
	{
		"-triple i686-pc-mingw32",
	},
	stdcflags =
	{
		"-D__MINGW32__",
	},
	stdcxxflags =
	{
		"-D__MINGW32__",
	},
	stdinc =
	{
		clang_prefix.."/lib/clang/3.0/include",
		stdc_prefix.."/include",
	},
	stdincxx =
	{
--		clang_prefix.."/lib/clang/3.0/include",
--		stdc_prefix.."/include",
	},
	archinc =
	{
	},
	archincxx =
	{
	},
---------------------------------------------------
-- link time options. 
---------------------------------------------------
	arch_begin_shared =
	{
		"--shared",
		"-Bdynamic -e _DllMainCRTStartup@12",
		"--enable-auto-image-base",
	},
	arch_end_shared =
	{
	},
	arch_begin_exe =
	{
		"-Bdynamic",
	},
	arch_end_exe =
	{
	},
	object_begin_shared =
	{
		stdc_prefix.."/lib/dllcrt2.o",
	},
	object_end_shared =
	{
		--stdc_prefix.."/lib/crtn.o",
	},
	object_begin_exe =
	{
		stdc_prefix.."/lib/crt2.o",
	},
	object_end_exe =
	{
		--stdc_prefix.."/lib/crtn.o",
	},

	stdcldflags_s1 =
	{
		"-L"..stdc_prefix.."/lib",
	},
	stdcldflags_s2 =
	{
		"-lmingw32 -lmoldname",
		"-lmingwex -lmsvcrt -luser32 -lkernel32",
		"-ladvapi32 -lshell32 -lmingw32",
		"-lmoldname -lmingwex -lmsvcrt",
	},
	stdcxxldflags_s1 =
	{
		"-L"..stdc_prefix.."/lib",
	},
	stdcxxldflags_s2 =
	{
		"-lstdc++ -lmingw32 -lmoldname",
		"-lmingwex -lmsvcrt -luser32 -lkernel32",
		"-ladvapi32 -lshell32 -lmingw32 ",
		"-lmoldname -lmingwex -lmsvcrt",
	},

	archcldflags_s1 =
	{
		"-L"..stdc_prefix_ext.."/lib",
	},
	archcldflags_s2 =
	{
		"-lkernel32 -luser32 -lgdi32 -lwinspool -lshell32",
		"-lole32 -loleaut32 -luuid -lcomdlg32 -ladvapi32",
		"-limagehlp -lpsapi",
	},
	archcxxldflags_s1 =
	{
		"-L"..stdc_prefix_ext.."/lib",
	},
	archcxxldflags_s2 =
	{
		"-lkernel32 -luser32 -lgdi32 -lwinspool -lshell32",
		"-lole32 -loleaut32 -luuid -lcomdlg32 -ladvapi32",
		"-limagehlp -lpsapi",
	},
}

