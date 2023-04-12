@echo off
if not exist build mkdir build
pushd build
clang ../src/*.c -o main.exe  -Wall -Wextra -march=native -Wpedantic -fno-exceptions -Wconversion
popd 
echo Build Success

