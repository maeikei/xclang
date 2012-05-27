---------------------------------------------------------
-- global setting of xclang envirment.
---------------------------------------------------------
if nil == globalXClangHome then
	globalXClangHome = "C:/xclang-dev/xclang-obj/InstallRoot"
end
clang_prefix = globalXClangHome.."/tools/llvm/"
binutils_prefix = globalXClangHome.."/tools/binutils/x86_64-pc-linux-gnu/bin"
platform_prefix = globalXClangHome.."/platform/x86_64-pc-linux-gnu"


stdc_prefix = platform_prefix.."/usr"
stdcxx_prefix = platform_prefix.."/usr"

stdc_prefix_ext = platform_prefix.."/"
stdcxx_prefix_ext = platform_prefix.."/"


globalXClangDefaultOutPutName = "a.out"
globalXClangOutputObjExtension = ".o"
globalXClangOutputAsmExtension = ".s"


xclang =
{
---------------------------------------------------
-- compile time options. 
---------------------------------------------------
	arch= "x86_64",
	triple= "x86_64-pc-linux",
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
		"-triple x86_64-pc-linux",
	},
	stdcxxoption =
	{
		"-triple x86_64-pc-linux",
	},
	stdcflags =
	{
		"-D__LINUX__",
	},
	stdcxxflags =
	{
		"-D__LINUX__",
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
		"--build-id",
		"--eh-frame-hdr",
		"-m elf_i686",
		"--hash-style=gnu",
		"-shared",
		" -z relro",
	},
	arch_end_shared =
	{
	},
	arch_begin_exe =
	{
		"--build-id",
		"--eh-frame-hdr",
		"-m elf_i686",
		"--hash-style=gnu",
		"-dynamic-linker /lib/ld-linux.so.2",
		"-z relro",
	},
	arch_end_exe =
	{
	},
	object_begin_shared =
	{
		stdc_prefix.."/lib/crti.o",
		stdc_prefix.."/lib/crtbeginS.o",
	},
	object_end_shared =
	{
		stdc_prefix.."/lib/crtendS.o",
		stdc_prefix.."/lib/crtn.o",
	},
	object_begin_exe =
	{
		stdc_prefix.."/lib/crt1.o",
		stdc_prefix.."/lib/crti.o",
		stdc_prefix.."/lib/crtbegin.o",
	},
	object_end_exe =
	{
		stdc_prefix.."/lib/crtend.o",
		stdc_prefix.."/lib/crtn.o",
	},

	stdcldflags_s1 =
	{
		"-L"..stdc_prefix.."/lib",
		"-L"..stdc_prefix_ext.."/lib",
	},
	stdcldflags_s2 =
	{
		"-lgcc --as-needed -lgcc_s --no-as-needed -lc -lgcc --as-needed -lgcc_s",
	},
	stdcxxldflags_s1 =
	{
		"-L"..stdc_prefix.."/lib",
		"-L"..stdc_prefix_ext.."/lib",
	},
	stdcxxldflags_s2 =
	{
		"-lstdc++ -lm -lgcc_s -lc -lgcc_s",
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

