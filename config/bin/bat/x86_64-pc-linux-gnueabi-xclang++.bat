@set pwd_path=%~dp0
@set xclang_path=%pwd_path%xclang++.exe
@"%xclang_path%" --xclang-target x86_64-pc-linux-gnueabi %*
