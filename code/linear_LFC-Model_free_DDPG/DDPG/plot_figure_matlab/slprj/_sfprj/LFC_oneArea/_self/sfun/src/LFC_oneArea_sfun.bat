@echo off
set COMPILER=C:\ProgramData\MATLAB\SupportPackages\R2021b_1\3P.instrset\mingw_w64.instrset\bin\gcc
                set CXXCOMPILER=C:\ProgramData\MATLAB\SupportPackages\R2021b_1\3P.instrset\mingw_w64.instrset\bin\g++
                set COMPFLAGS=-c -fexceptions -fno-omit-frame-pointer -m64 -DMATLAB_MEX_FILE  -DMATLAB_MEX_FILE 
                set CXXCOMPFLAGS=-c -fexceptions -fno-omit-frame-pointer -std=c++11 -m64 -DMATLAB_MEX_FILE  -DMATLAB_MEX_FILE 
                set OPTIMFLAGS=-O2 -fwrapv -DNDEBUG
                set DEBUGFLAGS=-g
                set LINKER=C:\ProgramData\MATLAB\SupportPackages\R2021b_1\3P.instrset\mingw_w64.instrset\bin\gcc
                set CXXLINKER=C:\ProgramData\MATLAB\SupportPackages\R2021b_1\3P.instrset\mingw_w64.instrset\bin\g++
                set LINKFLAGS=-m64 -Wl,--no-undefined -shared -static -L"D:\appInstall\MATLAB\R2021b\extern\lib\win64\mingw64" -llibmx -llibmex -llibmat -lm -llibmwlapack -llibmwblas -llibMatlabDataArray -llibMatlabEngine -Wl,"D:\appInstall\MATLAB\R2021b/extern/lib/win64/mingw64/mexFunction.def"
                set LINKDEBUGFLAGS=-g
                set NAME_OUTPUT= -o "%OUTDIR%%MEX_NAME%%MEX_EXT%"
set PATH=C:\ProgramData\MATLAB\SupportPackages\R2021b_1\3P.instrset\mingw_w64.instrset\bin;D:\appInstall\MATLAB\R2021b\extern\include\win64;D:\appInstall\MATLAB\R2021b\extern\include;D:\appInstall\MATLAB\R2021b\simulink\include;D:\appInstall\MATLAB\R2021b\lib\win64;%MATLAB_BIN%;%PATH%
set INCLUDE=C:\ProgramData\MATLAB\SupportPackages\R2021b_1\3P.instrset\mingw_w64.instrset\include;C:\ProgramData\MATLAB\SupportPackages\R2021b_1\3P.instrset\mingw_w64.instrset\lib\gcc\x86_64-w64-mingw32\6.3.0\include\c++;C:\ProgramData\MATLAB\SupportPackages\R2021b_1\3P.instrset\mingw_w64.instrset\lib\gcc\x86_64-w64-mingw32\6.3.0\include;C:\ProgramData\MATLAB\SupportPackages\R2021b_1\3P.instrset\mingw_w64.instrset\lib\gcc\x86_64-w64-mingw32\6.3.0\include\c++\x86_64-w64-mingw32;C:\ProgramData\MATLAB\SupportPackages\R2021b_1\3P.instrset\mingw_w64.instrset\lib\gcc\x86_64-w64-mingw32\6.3.0\include\c++\backward;C:\ProgramData\MATLAB\SupportPackages\R2021b_1\3P.instrset\mingw_w64.instrset\x86_64-w64-mingw32\include;%INCLUDE%
set LIB=C:\ProgramData\MATLAB\SupportPackages\R2021b_1\3P.instrset\mingw_w64.instrset\lib;;%LIB%
set LIBPATH=D:\appInstall\MATLAB\R2021b\extern\lib\win64;%LIBPATH%

gmake SHELL="cmd" -f LFC_oneArea_sfun.gmk
