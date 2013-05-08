---------------------------------------------------------
-- global setting of xclang envirment.
---------------------------------------------------------
if nil == globalXClangHome then
	globalXClangHome = "C:/xclang-dev/xclang-obj/InstallRoot"
end
binutils_prefix = globalXClangHome.."/binutils/x86_64-linux-gnu/bin"
platform_prefix = globalXClangHome.."/platform/x86_64-linux-gnu"




---------------------------------------------------
-- options for complication only (cc1).
---------------------------------------------------
xclang =
{
	props =
	{
		objext		    = ".o",
		asmext		    = ".s",
		defaultexe		= "a.out",
	},
	archascppflags =
	{
		"-D __linux__",
		"-D __Linux__",
        "-fexceptions",
        "-integrated-as ",
        "-target x86_64-pc-linux-gnu",
	},
	archcflags =
	{
        "-fuse-init-array",
        "-c -integrated-as ",
        "-target x86_64-pc-linux-gnu",
        "-B"..binutils_prefix,
		"-D __linux__",
		"-D __Linux__",
        "-fexceptions",
		"-pthread",
	},
	archcxxflags =
	{
        "-fcxx-exceptions",
	},
	stdinc =
	{
        "-isysroot "..platform_prefix,
        "-isystem "..platform_prefix,
        "-I "..platform_prefix.."/xclang/include",
        "-I "..platform_prefix.."/usr/include",
        "-I "..platform_prefix.."/usr/include/x86_64-linux-gnu",
        "-I "..platform_prefix.."/usr/lib/gcc/x86_64-linux-gnu/4.7/include/",
        "-I "..platform_prefix.."/usr/lib/gcc/x86_64-linux-gnu/4.7/include-fixed",
	},
	stdincxx =
	{
        "-I "..platform_prefix.."/cxx/include/c++/v1",
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
         "-z relro --hash-style=gnu --build-id --eh-frame-hdr ",
         "-m elf_x86_64 -dynamic-linker /lib64/ld-linux-x86-64.so.2",
    },
	beginobject =
	{
        platform_prefix.."/usr/lib/x86_64-linux-gnu/crt1.o",
        platform_prefix.."/usr/lib/x86_64-linux-gnu/crti.o",
        platform_prefix.."/usr/lib/gcc/x86_64-linux-gnu/4.7/crtbegin.o",
	},
    stdxxdirs =
	{
		"-L"..platform_prefix.."/cxx/lib",
	},
    stdxxlibs =
	{
        "-lc++",
        "-lc++abi",
 	},
    stddirs =
	{
        "-L"..platform_prefix.."/lib",
        "-L"..platform_prefix.."/lib/x86_64-linux-gnu",
        "-L"..platform_prefix.."/usr/lib/x86_64-linux-gnu",
		"-L"..platform_prefix.."/usr/lib/gcc/x86_64-linux-gnu/4.7",
	},
    stdlibs =
	{
        "-lpthread",
        "-lm",
        "-lc",
        "-lrt",
        "-lgcc_s",
	},
	endobject =
	{
        platform_prefix.."/usr/lib/gcc/x86_64-linux-gnu/4.7/crtend.o",
        platform_prefix.."/usr/lib/x86_64-linux-gnu/crtn.o",
	},
}
---------------------------------------------------
-- link time options of executable with -static.
---------------------------------------------------    
link_exe_s = {
    arch =
    {
         "-z relro --hash-style=gnu --build-id --eh-frame-hdr ",
         "-m elf_x86_64 -dynamic-linker /lib64/ld-linux-x86-64.so.2",
    },
	beginobject =
	{
        platform_prefix.."/usr/lib/x86_64-linux-gnu/crt1.o",
        platform_prefix.."/usr/lib/gcc/x86_64-linux-gnu/4.7/crtbegin.o",
	},
    stdxxdirs =
	{
		"-L"..platform_prefix.."/cxx/lib",
	},
    stdxxlibs =
	{
        "-lc++",
        "-lc++abi",
	},
    stddirs =
	{
        "-L"..platform_prefix.."/lib",
        "-L"..platform_prefix.."/lib/x86_64-linux-gnu",
        "-L"..platform_prefix.."/usr/lib/x86_64-linux-gnu",
		"-L"..platform_prefix.."/usr/lib/gcc/x86_64-linux-gnu/4.7",
	},
    stdlibs =
	{
        "-lpthread",
        "-lm",
        "-lc",
        "-lrt",
        "-lgcc_s",
	},
	endobject =
	{
        platform_prefix.."/usr/lib/gcc/x86_64-linux-gnu/4.7/crtend.o",
        platform_prefix.."/usr/lib/x86_64-linux-gnu/crtn.o",
	},
}

---------------------------------------------------
-- link time options of shared library.
---------------------------------------------------
link_shared = {
    arch =
    {
         "-z relro --hash-style=gnu --build-id --eh-frame-hdr -m elf_x86_64 -shared",
    },
	beginobject =
	{
        platform_prefix.."/usr/lib/x86_64-linux-gnu/crti.o",
        platform_prefix.."/usr/lib/gcc/x86_64-linux-gnu/4.7/crtbeginS.o",
	},
    stdxxdirs =
	{
		"-L"..platform_prefix.."/cxx/lib",
	},
    stdxxlibs =
	{
	},
    stddirs =
	{
        "-L"..platform_prefix.."/lib",
        "-L"..platform_prefix.."/lib/x86_64-linux-gnu",
        "-L"..platform_prefix.."/usr/lib/x86_64-linux-gnu",
		"-L"..platform_prefix.."/usr/lib/gcc/x86_64-linux-gnu/4.7",
	},
    stdlibs =
	{
        "-lpthread",
        "-lm",
        "-lc",
        "-lrt",
        "-lgcc_s",
	},
	endobject =
	{
        platform_prefix.."/usr/lib/gcc/x86_64-linux-gnu/4.7/crtendS.o",
        platform_prefix.."/usr/lib/x86_64-linux-gnu/crtn.o",
	},
}

---------------------------------------------------
-- link time options of shared library with -static.
---------------------------------------------------
link_shared_s = {
    arch =
    {
         "-z relro --hash-style=gnu --build-id --eh-frame-hdr -m elf_x86_64 -shared",
    },
	beginobject =
	{
        platform_prefix.."/usr/lib/x86_64-linux-gnu/crti.o",
        platform_prefix.."/usr/lib/gcc/x86_64-linux-gnu/4.7/crtbeginS.o",
	},
    stdxxdirs =
	{
		"-L"..platform_prefix.."/cxx/lib",
	},
    stdxxlibs =
	{
	},
    stddirs =
	{
        "-L"..platform_prefix.."/lib",
        "-L"..platform_prefix.."/lib/x86_64-linux-gnu",
        "-L"..platform_prefix.."/usr/lib/x86_64-linux-gnu",
		"-L"..platform_prefix.."/usr/lib/gcc/x86_64-linux-gnu/4.7",
	},
    stdlibs =
	{
        "-lpthread",
        "-lm",
        "-lc",
        "-lrt",
        "-lgcc_s",
	},
	endobject =
	{
        platform_prefix.."/usr/lib/gcc/x86_64-linux-gnu/4.7/crtendS.o",
        platform_prefix.."/usr/lib/x86_64-linux-gnu/crtn.o",
	},
}
