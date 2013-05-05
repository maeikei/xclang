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
		triple		    = "i386-linux-gnu",
		objext		    = ".o",
		asmext		    = ".s",
		defaultexe		= "a.out",
	},
	archcflags =
	{
		"-D __Linux__",
	},
	archcxxflags =
	{
	},
	stdinc =
	{
        "-isysroot "..platform_prefix,
        "-isystem "..platform_prefix,
        "-I "..platform_prefix.."/usr/include",
        "-I "..platform_prefix.."/usr/include/i386-linux-gnu",
        "-I "..platform_prefix.."/xclang/include",
	},
	stdincxx =
	{
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
    },
	beginobject =
	{
        platform_prefix.."/usr/lib/i386-linux-gnu/crti.o",
	},
    stdxxdirs =
	{
		"",
	},
    stdxxlibs =
	{
	},
    stddirs =
	{
        "-L"..platform_prefix.."/usr/lib",
	},
    stdlibs =
	{
        "-lc",
	},
	endobject =
	{
	},
}
---------------------------------------------------
-- link time options of executable with -static.
---------------------------------------------------    
link_exe_s = {
    arch =
    {
    },
	beginobject =
	{
        platform_prefix.."/usr/lib/crti.o",
	},
    stdxxdirs =
	{
		"",
	},
    stdxxlibs =
	{
	},
    stddirs =
	{
        "-L"..platform_prefix.."/usr/lib",
	},
    stdlibs =
	{
	},
	endobject =
	{
	},
}

---------------------------------------------------
-- link time options of shared library.
---------------------------------------------------
link_shared = {
    arch =
    {
    },
	beginobject =
	{
	},
    stdxxdirs =
	{
		"",
	},
    stdxxlibs =
	{
	},
    stddirs =
	{
	},
    stdlibs =
	{
	},
	endobject =
	{
	},
}

---------------------------------------------------
-- link time options of shared library with -static.
---------------------------------------------------
link_shared_s = {
    arch =
    {
    },
	beginobject =
	{
	},
    stdxxdirs =
	{
		"",
	},
    stdxxlibs =
	{
	},
    stddirs =
	{
	},
    stdlibs =
	{
	},
	endobject =
	{
	},
}


