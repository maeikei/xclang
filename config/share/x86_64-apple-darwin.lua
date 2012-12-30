---------------------------------------------------------
-- global setting of xclang envirment.
---------------------------------------------------------
if nil == globalXClangHome then
	globalXClangHome = "C:/xclang-dev/xclang-obj/InstallRoot"
end
binutils_prefix = globalXClangHome.."/binutils/x86_64-apple-darwin/bin"
platform_prefix = globalXClangHome.."/platform/MacOSX10.8.sdk"


---------------------------------------------------
-- options for complication only (cc1).
---------------------------------------------------
xclang =
{
	props =
	{
		triple		    = "x86_64-apple-darwin",
		objext		    = ".o",
		asmext		    = ".s",
		defaultexe		= "a.out",
	},
	archcflags =
	{
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
        "-I "..platform_prefix.."/usr/include",
	},
	stdincxx =
	{
        "-I "..platform_prefix.."/usr/include/c++/4.2.1",
	},
}

---------------------------------------------------
-- tool chain commands.
---------------------------------------------------
toolchain = {
	progs =
	{
		ld		    = "/usr/bin/ld",
		ar		    = binutils_prefix.."/ar",
		as		    = binutils_prefix.."/as",
		nm		    = binutils_prefix.."/nm",
		objcopy 	= binutils_prefix.."/objcopy",
		objdump 	= binutils_prefix.."/objdump",
		ranlib 		= binutils_prefix.."/ranlib",
		strip 		= binutils_prefix.."/strip",
	},
}
---------------------------------------------------
-- link time options of executable.
---------------------------------------------------    
link_exe = {
    arch =
    {
        "-demangle",
        "-dynamic",
        "-arch x86_64 -macosx_version_min 10.8.0",
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
        "-lstdc++",
        "-lSystem",
	},
    stddirs =
	{
	},
    stdlibs =
	{
        "-lSystem",
	},
	endobject =
	{
        "/usr/lib/clang/4.0/lib/darwin/libclang_rt.osx.a",
	},
}
---------------------------------------------------
-- link time options of executable with -static.
---------------------------------------------------    
link_exe_s = {
    arch =
    {
        "-demangle",
        "-static",
        "-arch x86_64 -macosx_version_min 10.8.0",
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
        "-lstdc++",
        "-lSystem",
	},
    stddirs =
	{
	},
    stdlibs =
	{
        "-lSystem",
	},
	endobject =
	{
        "/usr/lib/clang/4.0/lib/darwin/libclang_rt.osx.a",
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
        "-lstdc++",
        "-lSystem",
	},
    stddirs =
	{
	},
    stdlibs =
	{
        "-lSystem",
	},
	endobject =
	{
        "/usr/lib/clang/4.0/lib/darwin/libclang_rt.osx.a",
	},
}

---------------------------------------------------
-- link time options of shared library with -static.
---------------------------------------------------
link_shared_s = {
    arch =
    {
        "-demangle",
        "-dylib",
        "-static",
        "-arch x86_64 -macosx_version_min 10.8.0",
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
        "-lstdc++",
        "-lSystem",
	},
    stddirs =
	{
	},
    stdlibs =
	{
        "-lSystem",
	},
	endobject =
	{
        "/usr/lib/clang/4.0/lib/darwin/libclang_rt.osx.a",
	},
}

