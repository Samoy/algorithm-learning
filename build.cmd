chcp 65001
@echo off
set include=%~dp0include
set subdir=%~dp0%1
@REM Compile include
g++ -c %include%\node.cpp -o  %include%\node.o
@REM Compile subdir
g++ %subdir%\main.cpp -o %subdir%\main.exe -I %include% %include%\node.o
@REM Execute
if %ERRORLEVEL% EQU 0 (
    echo Compilation successful.
    %subdir%\main.exe
) else (
    echo Compilation failed.
)