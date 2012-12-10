---------------------------------------------------------
-- global setting of xclang envirment.
---------------------------------------------------------
if nil == globalXClangHome then
	globalXClangHome = "C:/xclang-dev/xclang-obj/InstallRoot"
end
binutils_prefix = globalXClangHome.."/binutils/x86_64-w64-mingw32/bin"
platform_prefix = globalXClangHome.."/platform/x86_64-w64-mingw32"


stdc_prefix = platform_prefix.."/usr"
stdcxx_prefix = platform_prefix.."/usr"

stdc_prefix_ext = platform_prefix.."/"
stdcxx_prefix_ext = platform_prefix.."/"


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
		ar		    = binutils_prefix.."/ar",
		as		    = binutils_prefix.."/as",
		ld		    = binutils_prefix.."/ld",
		ldxx		= binutils_prefix.."/ld",
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
	arch_begin_exe =
	{
		"--build-id",
		"--eh-frame-hdr",
		"--hash-style=gnu",
		"-dynamic-linker /lib/ld-linux.so.2",
		"-z relro",
	},
	arch_end_exe =
	{
	},
    object_begin_exe_static =
	{
		stdc_prefix.."/lib/crtbegin_static.o",
	},
	object_begin_exe =
	{
		stdc_prefix.."/lib/crtbegin_dynamic.o",
	},
	object_end_exe =
	{
		stdc_prefix.."/lib/crtend.o",
	},
}
---------------------------------------------------
-- link time options of shared library.
---------------------------------------------------
link_shared = {
	arch_begin_shared =
	{
		"--build-id",
		"--eh-frame-hdr",
		"--hash-style=gnu",
		"-shared",
		" -z relro",
	},
	arch_end_shared =
	{
	},
	object_begin_shared =
	{
		stdc_prefix.."/lib/crtbegin_so.o",
	},
	object_end_shared =
	{
		stdc_prefix.."/lib/crtend_so.o",
	},

	stdcldflags_s1_static =
	{
		"-L"..stdc_prefix.."/lib",
		"-L"..stdc_prefix_ext.."/lib",
	},
	stdcldflags_s2_static =
	{
		stdc_prefix.."/lib/libxclang-c-static.a",
		stdc_prefix.."/lib/libxclang-m-static.a",
		stdc_prefix.."/lib/libxclang-dl-static.a",
		stdc_prefix.."/lib/libCompilerRT-Generic.a",
	},
	stdcldflags_s1 =
	{
		"-L"..stdc_prefix.."/lib",
		"-L"..stdc_prefix_ext.."/lib",
	},
	stdcldflags_s2 =
	{
		"-lxclang-c -lCompilerRT-Generic ",
	},
	stdcxxldflags_s1_static =
	{
		"-L"..stdc_prefix.."/lib",
		"-L"..stdc_prefix_ext.."/lib",
	},
	stdcxxldflags_s2_static =
	{
		stdc_prefix.."/lib/libstdcxx-static.a",
		stdc_prefix.."/lib/libxclang-c-static.a",
		stdc_prefix.."/lib/libxclang-m-static.a",
		stdc_prefix.."/lib/libxclang-dl-static.a",
		stdc_prefix.."/lib/libCompilerRT-Generic.a",
	},
	stdcxxldflags_s1 =
	{
		"-L"..stdc_prefix.."/lib",
		"-L"..stdc_prefix_ext.."/lib",
	},
	stdcxxldflags_s2 =
	{
		"-lstdcxx -lxclang-c -lCompilerRT-Generic ",
	},

	archcldflags_s1 =
	{
	},
	archcldflags_s2 =
	{
	},

	archcxxldflags_s1 =
	{
	},
	archcxxldflags_s2 =
	{
	},
}

