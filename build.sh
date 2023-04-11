mkdir -p build; 
cd build;
clang ../src/*.c -o main.exe  -Wall -Wextra -march=native -Wpedantic -fno-exceptions -Wcast-align -Wold-style-cast;
cd ..;