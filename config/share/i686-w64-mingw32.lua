---------------------------------------------------------
-- global setting of xclang envirment.
---------------------------------------------------------
if nil == globalXClangHome then
	globalXClangHome = "C:/xclang-dev/xclang-obj/InstallRoot"
end
binutils_prefix = globalXClangHome.."/binutils/i686-w64-mingw32/bin"
platform_prefix = globalXClangHome.."/platform/i686-w64-mingw32"


---------------------------------------------------
-- options for complication only (cc1).
---------------------------------------------------
xclang =
{
	props =
	{
		objext		    = ".obj",
		asmext		    = ".s",
		defaultexe		= "a.exe",
	},
	archascppflags =
	{
        "-integrated-as ",
        "-target i686-w64-pc-mingw32",
	},
	archcflags =
	{
        "-fuse-init-array",
		"-D __MINGW__",
        "-c -integrated-as ",
        "-target i686-w64-pc-mingw32",
        "-B"..binutils_prefix,
        "-fexceptions",
		"-pthread",
        "-D gnu_printf=printf",
        "-D gnu_scanf=scanf",
	},
	archcxxflags =
	{
        "-fcxx-exceptions",
	},
	stdinc =
	{
        "-isysroot "..platform_prefix,
        "-isystem "..platform_prefix,
        "-I "..platform_prefix.."/i686-w64-mingw32/include",
	},
	stdincxx =
	{
        "-I "..platform_prefix.."/i686-w64-mingw32/include/c++/4.8.0",
        "-I "..platform_prefix.."/i686-w64-mingw32/include/c++/4.8.0/i686-w64-mingw32",
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
        "-m i386pe",
        "-Bdynamic",
    },
	beginobject =
	{
        platform_prefix.."/i686-w64-mingw32/lib/crt2.o",
        platform_prefix.."/i686-w64-mingw32/lib/crtbegin.o",
	},
    stdxxdirs =
	{
		"",
	},
    stdxxlibs =
	{
        "-lstdc++ -lmingw32 -lgcc_s -lgcc", 
        "-lmoldname -lmingwex -lmsvcrt -ladvapi32",
        "-lshell32 -luser32 -lkernel32 -lmingw32",
        "-lgcc_s -lgcc -lmoldname -lmingwex -lmsvcrt",
	},
    stddirs =
	{
		"-L"..platform_prefix.."/lib/x86_64",
		"-L"..platform_prefix.."/lib/gcc/i686-w64-mingw32/4.8.0",
		"-L"..platform_prefix.."/i686-w64-mingw32/lib",
	},
    stdlibs =
	{
		"-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex",
        "-lmsvcrt -ladvapi32 -lshell32 -luser32 -lkernel32",
        "-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex -lmsvcrt",
	},
	endobject =
	{
        platform_prefix.."/i686-w64-mingw32/lib/crtend.o",
	},
}
---------------------------------------------------
-- link time options of executable with -static.
---------------------------------------------------    
link_exe_s = {
    arch =
    {
        "-m i386pe",
        "-Bstatic",
    },
	beginobject =
	{
        platform_prefix.."/i686-w64-mingw32/lib/crt2.o",
        platform_prefix.."/i686-w64-mingw32/lib/crtbegin.o",
	},
    stdxxdirs =
	{
		"",
	},
    stdxxlibs =
	{
        "-lstdc++ -lmingw32 -lgcc_s -lgcc", 
        "-lmoldname -lmingwex -lmsvcrt -ladvapi32",
        "-lshell32 -luser32 -lkernel32 -lmingw32",
        "-lgcc_s -lgcc -lmoldname -lmingwex -lmsvcrt",
	},
    stddirs =
	{
		"-L"..platform_prefix.."/lib/x86_64",
		"-L"..platform_prefix.."/lib/gcc/i686-w64-mingw32/4.8.0",
		"-L"..platform_prefix.."/i686-w64-mingw32/lib",
	},
    stdlibs =
	{
		"-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex",
        "-lmsvcrt -ladvapi32 -lshell32 -luser32 -lkernel32",
        "-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex -lmsvcrt",
	},
	endobject =
	{
        platform_prefix.."/i686-w64-mingw32/lib/crtend.o",
	},
}

---------------------------------------------------
-- link time options of shared library.
---------------------------------------------------
link_shared = {
    arch =
    {
        "-m i386pe",
        "--shared",
        "-Bdynamic",
        "-e DllMainCRTStartup",
        "--enable-auto-image-base",
    },
	beginobject =
	{
        platform_prefix.."/i686-w64-mingw32/lib/dllcrt2.o",
        platform_prefix.."/i686-w64-mingw32/lib/crtbegin.o",
	},
    stdxxdirs =
	{
		"",
	},
    stdxxlibs =
	{
        "-lstdc++ -lmingw32 -lgcc_s -lgcc", 
        "-lmoldname -lmingwex -lmsvcrt -ladvapi32",
        "-lshell32 -luser32 -lkernel32 -lmingw32",
        "-lgcc_s -lgcc -lmoldname -lmingwex -lmsvcrt",
	},
    stddirs =
	{
		"-L"..platform_prefix.."/lib/x86_64",
		"-L"..platform_prefix.."/lib/gcc/i686-w64-mingw32/4.8.0",
		"-L"..platform_prefix.."/i686-w64-mingw32/lib",
	},
    stdlibs =
	{
		"-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex",
        "-lmsvcrt -ladvapi32 -lshell32 -luser32 -lkernel32",
        "-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex -lmsvcrt",
	},
	endobject =
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
        "-m i386pe",
        "--shared",
        "-Bstatic",
        "-e DllMainCRTStartup",
        "--enable-auto-image-base",
    },
	beginobject =
	{
        platform_prefix.."/i686-w64-mingw32/lib/dllcrt2.o",
        platform_prefix.."/i686-w64-mingw32/lib/crtbegin.o",
	},
    stdxxdirs =
	{
		"",
	},
    stdxxlibs =
	{
        "-lstdc++ -lmingw32 -lgcc_s -lgcc", 
        "-lmoldname -lmingwex -lmsvcrt -ladvapi32",
        "-lshell32 -luser32 -lkernel32 -lmingw32",
        "-lgcc_s -lgcc -lmoldname -lmingwex -lmsvcrt",
	},
    stddirs =
	{
		"-L"..platform_prefix.."/lib/x86_64",
		"-L"..platform_prefix.."/lib/gcc/i686-w64-mingw32/4.8.0",
		"-L"..platform_prefix.."/i686-w64-mingw32/lib",
	},
    stdlibs =
	{
		"-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex",
        "-lmsvcrt -ladvapi32 -lshell32 -luser32 -lkernel32",
        "-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex -lmsvcrt",
	},
	endobject =
	{
        platform_prefix.."/i686-w64-mingw32/lib/crtend.o",
	},
}

