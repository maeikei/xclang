---------------------------------------------------------
-- global setting of xclang envirment.
---------------------------------------------------------
if nil == globalXClangHome then
	globalXClangHome = "C:/xclang-dev/xclang-obj/InstallRoot"
end
binutils_prefix = globalXClangHome.."/binutils/arm-linux-gnueabihf/bin"
platform_prefix = globalXClangHome.."/platform/arm-linux-gnueabihf"




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

        "-mcpu=cortex-a9",
        "-mfloat-abi=hard",
        "-mfpu=vfpv3-d16",
        "-mthumb",
        "-target armv7a-pc-linux-gnueabihf",


        "-D __arm__",
        "-D __ARM_EABI_UNWINDER__",
		"-D __linux__",
		"-D __Linux__",
        "-fexceptions",
        "-integrated-as ",
	},
	archcflags =
	{

        "-mcpu=cortex-a9",
        "-mfloat-abi=hard",
        "-mfpu=vfpv3-d16",
        "-mthumb",
        "-target armv7a-pc-linux-gnueabihf",

        "-D __arm__",
        "-D __ARM_EABI_UNWINDER__",
        "-fuse-init-array",
        "-c -integrated-as ",
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
        "-I "..platform_prefix.."/usr/arm-linux-gnueabihf/include",
        "-I "..platform_prefix.."/usr/lib/gcc-cross/arm-linux-gnueabihf/4.7/include",
        "-I "..platform_prefix.."/usr/lib/gcc-cross/arm-linux-gnueabihf/4.7/include-fixed",
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
        "-z relro -X --hash-style=gnu --build-id --eh-frame-hdr ",
        "--as-needed -m armelf_linux_eabi -dynamic-linker /lib/ld-linux-armhf.so.3",
--        "-mcpu=cortex-a9",
--        "-mfloat-abi=hard",
    },
	beginobject =
	{
        platform_prefix.."/usr/arm-linux-gnueabihf/lib/crt1.o",
        platform_prefix.."/usr/arm-linux-gnueabihf/lib//crti.o",
        platform_prefix.."/usr/lib/gcc-cross/arm-linux-gnueabihf/4.7/crtbegin.o",
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
        "-L"..platform_prefix.."/usr/arm-linux-gnueabihf/lib",
        "-L"..platform_prefix.."/usr/lib/gcc-cross/arm-linux-gnueabihf/4.7",
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
        platform_prefix.."/usr/lib/gcc-cross/arm-linux-gnueabihf/4.7/crtend.o",
        platform_prefix.."/usr/arm-linux-gnueabihf/lib/crtn.o",
	},
}
---------------------------------------------------
-- link time options of executable with -static.
---------------------------------------------------    
link_exe_s = {
    arch =
    {
        "-z relro -X --hash-style=gnu --build-id --eh-frame-hdr ",
        "--as-needed -m armelf_linux_eabi -dynamic-linker /lib/ld-linux-armhf.so.3",
--        "-mfloat-abi=hard",
    },
	beginobject =
	{
        platform_prefix.."/usr/arm-linux-gnueabihf/lib/crt1.o",
        platform_prefix.."/usr/lib/gcc-cross/arm-linux-gnueabihf/4.7/crtbegin.o",
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
        "-L"..platform_prefix.."/usr/arm-linux-gnueabihf/lib",
        "-L"..platform_prefix.."/usr/lib/gcc-cross/arm-linux-gnueabihf/4.7",
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
        platform_prefix.."usr/lib/gcc-cross/arm-linux-gnueabihf/4.7/crtend.o",
        platform_prefix.."/usr/arm-linux-gnueabihf/lib/crtn.o",
	},
}

---------------------------------------------------
-- link time options of shared library.
---------------------------------------------------
link_shared = {
    arch =
    {
        "-z relro -X --hash-style=gnu --build-id --eh-frame-hdr ",
        "--as-needed -m armelf_linux_eabi -shared -dynamic-linker /lib/ld-linux-armhf.so.3",
--        "-mfloat-abi=hard",
    },
	beginobject =
	{
        platform_prefix.."/usr/arm-linux-gnueabihf/lib/crti.o",
        platform_prefix.."/usr/lib/gcc-cross/arm-linux-gnueabihf/4.7/crtbeginS.o",
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
        "-L"..platform_prefix.."/usr/arm-linux-gnueabihf/lib",
        "-L"..platform_prefix.."/usr/lib/gcc-cross/arm-linux-gnueabihf/4.7",
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
        platform_prefix.."/usr/lib/gcc-cross/arm-linux-gnueabihf/4.7/crtendS.o",
        platform_prefix.."/usr/arm-linux-gnueabihf/lib/crtn.o",
	},
}

---------------------------------------------------
-- link time options of shared library with -static.
---------------------------------------------------
link_shared_s = {
    arch =
    {
        "-z relro -X --hash-style=gnu --build-id --eh-frame-hdr ",
        "--as-needed -m armelf_linux_eabi -shared -dynamic-linker /lib/ld-linux-armhf.so.3",
--        "-mfloat-abi=hard",
    },
	beginobject =
	{
        platform_prefix.."/usr/arm-linux-gnueabihf/lib/crti.o",
        platform_prefix.."/usr/lib/gcc-cross/arm-linux-gnueabihf/4.7/crtbeginS.o",
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
        "-L"..platform_prefix.."/usr/arm-linux-gnueabihf/lib",
        "-L"..platform_prefix.."/usr/lib/gcc-cross/arm-linux-gnueabihf/4.7",
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
        platform_prefix.."/usr/lib/gcc-cross/arm-linux-gnueabihf/4.7/crtendS.o",
        platform_prefix.."/usr/arm-linux-gnueabihf/lib/crtn.o",
	},
}

