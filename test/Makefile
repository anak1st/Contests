SOURCE = main.cpp
TARGET = ..\build\main.exe
FLAGS = -std=c++23 -O2

run: build_clang
	@build\main.exe

build_gcc:
	@g++ $(FLAGS) $(SOURCE) -o $(TARGET)

build_clang:
	@clang++ --target=x86_64-w64-windows-gnu $(FLAGS) $(SOURCE) -o $(TARGET)
