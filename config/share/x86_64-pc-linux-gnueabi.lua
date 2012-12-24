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
		objext		    = ".o",
		asmext		    = ".s",
		defaultexe		= "a.out",
	},
	archcflags =
	{
		"-D __Linux__",
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
-- link time options of executable with -static.
---------------------------------------------------    
link_exe_s = {
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


