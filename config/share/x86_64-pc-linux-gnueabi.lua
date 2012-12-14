---------------------------------------------------------
-- global setting of xclang envirment.
---------------------------------------------------------
if nil == globalXClangHome then
	globalXClangHome = "C:/xclang-dev/xclang-obj/InstallRoot"
end
binutils_prefix = globalXClangHome.."/binutils/x86_64-pc-linux-gnueabi/bin"
platform_prefix = globalXClangHome.."/platform/x86_64-pc-linux-gnueabi"




---------------------------------------------------
-- options for complication only (cc1).
---------------------------------------------------
xclang =
{
	props =
	{
		triple		    = "x86_64-pc-linux-gnueabi",
		objext		    = ".obj",
		asmext		    = ".s",
		defaultexe		= "a.exe",
	},
	archcflags =
	{
		"-D __MINGW__",
		"-D __MINGW64__",
        "-D gnu_printf=printf",
        "-D gnu_scanf=scanf",
	},
	archcxxflags =
	{
	},
	stdinc =
	{
        "-isysroot "..platform_prefix,
        "-isystem "..platform_prefix,
        "-I "..platform_prefix.."/x86_64-pc-linux-gnueabi/include",
	},
	stdincxx =
	{
        "-I "..platform_prefix.."/x86_64-pc-linux-gnueabi/include/c++/4.8.0",
        "-I "..platform_prefix.."/x86_64-pc-linux-gnueabi/include/c++/4.8.0/x86_64-pc-linux-gnueabi",
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
        "-m i386pep",
        "-Bdynamic",
    },
	beginobject =
	{
        platform_prefix.."/x86_64-pc-linux-gnueabi/lib/crt2.o",
        platform_prefix.."/x86_64-pc-linux-gnueabi/lib/crtbegin.o",
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
		"-L"..platform_prefix.."/lib/gcc/x86_64-pc-linux-gnueabi/4.8.0",
		"-L"..platform_prefix.."/x86_64-pc-linux-gnueabi/lib",
	},
    stdlibs =
	{
		"-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex",
        "-lmsvcrt -ladvapi32 -lshell32 -luser32 -lkernel32",
        "-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex -lmsvcrt",
	},
	endobject =
	{
        platform_prefix.."/x86_64-pc-linux-gnueabi/lib/crtend.o",
	},
}
---------------------------------------------------
-- link time options of executable with -static.
---------------------------------------------------    
link_exe_s = {
    arch =
    {
        "-m i386pep",
        "-Bstatic",
    },
	beginobject =
	{
        platform_prefix.."/x86_64-pc-linux-gnueabi/lib/crt2.o",
        platform_prefix.."/x86_64-pc-linux-gnueabi/lib/crtbegin.o",
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
		"-L"..platform_prefix.."/lib/gcc/x86_64-pc-linux-gnueabi/4.8.0",
		"-L"..platform_prefix.."/x86_64-pc-linux-gnueabi/lib",
	},
    stdlibs =
	{
		"-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex",
        "-lmsvcrt -ladvapi32 -lshell32 -luser32 -lkernel32",
        "-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex -lmsvcrt",
	},
	endobject =
	{
        platform_prefix.."/x86_64-pc-linux-gnueabi/lib/crtend.o",
	},
}

---------------------------------------------------
-- link time options of shared library.
---------------------------------------------------
link_shared = {
    arch =
    {
        "-m i386pep",
        "--shared",
        "-Bdynamic",
        "-e DllMainCRTStartup",
        "--enable-auto-image-base",
    },
	beginobject =
	{
        platform_prefix.."/x86_64-pc-linux-gnueabi/lib/dllcrt2.o",
        platform_prefix.."/x86_64-pc-linux-gnueabi/lib/crtbegin.o",
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
		"-L"..platform_prefix.."/lib/gcc/x86_64-pc-linux-gnueabi/4.8.0",
		"-L"..platform_prefix.."/x86_64-pc-linux-gnueabi/lib",
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
        "-m i386pep",
        "--shared",
        "-Bstatic",
        "-e DllMainCRTStartup",
        "--enable-auto-image-base",
    },
	beginobject =
	{
        platform_prefix.."/x86_64-pc-linux-gnueabi/lib/dllcrt2.o",
        platform_prefix.."/x86_64-pc-linux-gnueabi/lib/crtbegin.o",
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
		"-L"..platform_prefix.."/lib/gcc/x86_64-pc-linux-gnueabi/4.8.0",
		"-L"..platform_prefix.."/x86_64-pc-linux-gnueabi/lib",
	},
    stdlibs =
	{
		"-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex",
        "-lmsvcrt -ladvapi32 -lshell32 -luser32 -lkernel32",
        "-lmingw32 -lgcc_eh -lgcc -lmoldname -lmingwex -lmsvcrt",
	},
	endobject =
	{
        platform_prefix.."/x86_64-pc-linux-gnueabi/lib/crtend.o",
	},
}


