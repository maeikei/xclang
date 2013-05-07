---------------------------------------------------------
-- global setting of xclang envirment.
---------------------------------------------------------
if nil == globalXClangHome then
	globalXClangHome = "C:/xclang-dev/xclang-obj/InstallRoot"
end
binutils_prefix = globalXClangHome.."/binutils/i386-linux-gnu/bin"
platform_prefix = globalXClangHome.."/platform/i386-linux-gnu"




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
	archcflags =
	{
        "-fuse-init-array",
        "-c -integrated-as ",
        "-target i386-pc-linux-gnu",
        "-B"..binutils_prefix,
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
        "-I "..platform_prefix.."/usr/include",
        "-I "..platform_prefix.."/usr/include/i386-linux-gnu",
        "-I "..platform_prefix.."/usr/lib/gcc/i686-linux-gnu/4.7/include/",
        "-I "..platform_prefix.."/xclang/include",
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
         "-z relro --hash-style=gnu --build-id --eh-frame-hdr -m elf_i386 -dynamic-linker /lib/ld-linux.so.2",
    },
	beginobject =
	{
        platform_prefix.."/usr/lib/i386-linux-gnu/crt1.o",
        platform_prefix.."/usr/lib/i386-linux-gnu/crti.o",
        platform_prefix.."/usr/lib/gcc/i686-linux-gnu/4.7/crtbegin.o",
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
        "-L"..platform_prefix.."/lib/i386-linux-gnu",
        "-L"..platform_prefix.."/usr/lib/i386-linux-gnu",
		"-L"..platform_prefix.."/usr/lib/gcc/i686-linux-gnu/4.7",
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
        platform_prefix.."/usr/lib/gcc/i686-linux-gnu/4.7/crtend.o",
        platform_prefix.."/usr/lib/i386-linux-gnu/crtn.o",
	},
}
---------------------------------------------------
-- link time options of executable with -static.
---------------------------------------------------    
link_exe_s = {
    arch =
    {
         "-z relro --hash-style=gnu --build-id --eh-frame-hdr -m elf_i386 -dynamic-linker /lib/ld-linux.so.2",
    },
	beginobject =
	{
        platform_prefix.."/usr/lib/i386-linux-gnu/crt1.o",
        platform_prefix.."/usr/lib/gcc/i686-linux-gnu/4.7/crtbegin.o",
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
        "-L"..platform_prefix.."/lib/i386-linux-gnu",
        "-L"..platform_prefix.."/usr/lib/i386-linux-gnu",
		"-L"..platform_prefix.."/usr/lib/gcc/i686-linux-gnu/4.7",
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
        platform_prefix.."/usr/lib/gcc/i686-linux-gnu/4.7/crtend.o",
        platform_prefix.."/usr/lib/i386-linux-gnu/crtn.o",
	},
}

---------------------------------------------------
-- link time options of shared library.
---------------------------------------------------
link_shared = {
    arch =
    {
         "-z relro --hash-style=gnu --build-id --eh-frame-hdr -m elf_i386 -shared",
    },
	beginobject =
	{
        platform_prefix.."/usr/lib/i386-linux-gnu/crti.o",
        platform_prefix.."/usr/lib/gcc/i686-linux-gnu/4.7/crtbeginS.o",
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
        "-L"..platform_prefix.."/lib/i386-linux-gnu",
        "-L"..platform_prefix.."/usr/lib/i386-linux-gnu",
		"-L"..platform_prefix.."/usr/lib/gcc/i686-linux-gnu/4.7",
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
        platform_prefix.."/usr/lib/gcc/i686-linux-gnu/4.7/crtendS.o",
        platform_prefix.."/usr/lib/i386-linux-gnu/crtn.o",
	},
}

---------------------------------------------------
-- link time options of shared library with -static.
---------------------------------------------------
link_shared_s = {
    arch =
    {
         "-z relro --hash-style=gnu --build-id --eh-frame-hdr -m elf_i386 -shared",
    },
	beginobject =
	{
        platform_prefix.."/usr/lib/i386-linux-gnu/crti.o",
        platform_prefix.."/usr/lib/gcc/i686-linux-gnu/4.7/crtbeginS.o",
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
        "-L"..platform_prefix.."/lib/i386-linux-gnu",
        "-L"..platform_prefix.."/usr/lib/i386-linux-gnu",
		"-L"..platform_prefix.."/usr/lib/gcc/i686-linux-gnu/4.7",
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
        platform_prefix.."/usr/lib/gcc/i686-linux-gnu/4.7/crtendS.o",
        platform_prefix.."/usr/lib/i386-linux-gnu/crtn.o",
	},
}


