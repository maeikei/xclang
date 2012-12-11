---------------------------------------------------------
-- global setting of xclang envirment.
---------------------------------------------------------
if nil == globalXClangHome then
	globalXClangHome = "C:/xclang-dev/xclang-obj/InstallRoot"
end
binutils_prefix = globalXClangHome.."/binutils/x86_64-w64-mingw32/bin"
platform_prefix = globalXClangHome.."/platform/x86_64-w64-mingw32"


---------------------------------------------------
-- options for complication only (cc1).
---------------------------------------------------
xclang =
{
	master =
	{
		triple		    = "x86_64-w64-mingw32",
	},
	archcflags =
	{
		"-D __MINGW__",
		"-D __MINGW64__",
        "-D _STDIO_DEFINED",
	},
	archcxxflags =
	{
	},
	stdinc =
	{
        "-isysroot "..platform_prefix,
        "-isystem "..platform_prefix,
        "-I "..platform_prefix.."/include",
	},
	stdincxx =
	{
        "-I "..platform_prefix.."/include/c++/4.8.0",
        "-I "..platform_prefix.."/include/c++/4.8.0/x86_64-w64-mingw32",
	},
}

---------------------------------------------------
-- tool chain commands.
---------------------------------------------------
toolchain = {
	progs =
	{
		ld		    = binutils_prefix.."/ld",
		ar		    = binutils_prefix.."/ar",
		as		    = binutils_prefix.."/as",
		nm		    = binutils_prefix.."/nm",
		objcopy 	= binutils_prefix.."/objcopy",
		objdump 	= binutils_prefix.."/objdump",
		ranlib 		= binutils_prefix.."/ranlib",
		strip 		= binutils_prefix.."/strip",
		dlltool 	= binutils_prefix.."/dlltool",
	},
}
---------------------------------------------------
-- link time options of executable.
---------------------------------------------------    
link_exe = {
    arch =
    {
        "--sysroot="..platform_prefix,
        "-m i386pep",
        "-Bdynamic",
    },
	begin_object =
	{
        platform_prefix.."/lib/crt2.o",
        platform_prefix.."/lib/crtbegin.o",
	},
    stdxxlddir =
	{
		"",
	},
    stdxxlibs =
	{
		"-lstdc++",
	},
    stdlddir =
	{
		"-L"..platform_prefix.."/lib",
	},
    stdlibs =
	{
		"-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex",
        "-lmsvcrt -ladvapi32 -lshell32 -luser32 -lkernel32",
        "-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex -lmsvcrt",
	},
	end_object =
	{
        platform_prefix.."/lib/crtend.o",
	},
}
---------------------------------------------------
-- link time options of executable with -static.
---------------------------------------------------    
link_exe_s = {
    arch =
    {
        "--sysroot="..platform_prefix,
        "-m i386pep",
        "-Bstatic",
    },
	begin_object =
	{
        platform_prefix.."/lib/crt2.o",
        platform_prefix.."/lib/crtbegin.o",
	},
    stdxxlddir =
	{
		"",
	},
    stdxxlibs =
	{
		"-lstdc++",
	},
    stdlddir =
	{
		"-L"..platform_prefix.."/lib",
	},
    stdlibs =
	{
		"-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex",
        "-lmsvcrt -ladvapi32 -lshell32 -luser32 -lkernel32",
        "-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex -lmsvcrt",
	},
	end_object =
	{
        platform_prefix.."/lib/crtend.o",
	},
}

---------------------------------------------------
-- link time options of shared library.
---------------------------------------------------
link_shared = {
    arch =
    {
        "--sysroot="..platform_prefix,
        "-m i386pep",
        "--shared",
        "-Bdynamic",
        "-e DllMainCRTStartup",
        "--enable-auto-image-base",
    },
	begin_object =
	{
        platform_prefix.."/lib/dllcrt2.o",
        platform_prefix.."/lib/crtbegin.o",
	},
    stdxxlddir =
	{
		"",
	},
    stdxxlibs =
	{
		"-lstdc++",
	},
    stdlddir =
	{
		"-L"..platform_prefix.."/lib",
	},
    stdlibs =
	{
		"-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex",
        "-lmsvcrt -ladvapi32 -lshell32 -luser32 -lkernel32",
        "-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex -lmsvcrt",
	},
	end_object =
	{
        platform_prefix.."/lib/crtend.o",
	},
}

---------------------------------------------------
-- link time options of shared library with -static.
---------------------------------------------------
link_shared_s = {
    arch =
    {
        "--sysroot="..platform_prefix,
        "-m i386pep",
        "--shared",
        "-Bstatic",
        "-e DllMainCRTStartup",
        "--enable-auto-image-base",
    },
	begin_object =
	{
        platform_prefix.."/lib/dllcrt2.o",
        platform_prefix.."/lib/crtbegin.o",
	},
    stdxxlddir =
	{
		"",
	},
    stdxxlibs =
	{
		"-lstdc++",
	},
    stdlddir =
	{
		"-L"..platform_prefix.."/lib",
	},
    stdlibs =
	{
		"-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex",
        "-lmsvcrt -ladvapi32 -lshell32 -luser32 -lkernel32",
        "-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex -lmsvcrt",
	},
	end_object =
	{
        platform_prefix.."/lib/crtend.o",
	},
}

