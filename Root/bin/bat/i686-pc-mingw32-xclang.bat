@set pwd_path=%~dp0
@set xclang_path=%pwd_path%xclang.exe
@"%xclang_path%" --xclang-triple=i686-pc-mingw32 %*
@pause
