g++ ./src/test/test.cpp -o ./build/main.exe -O2 -std=c++23
g++ ./src/test/data.cpp -o ./build/data.exe -O2 -std=c++23
g++ ./src/test/ok.cpp   -o ./build/ok.exe   -O2 -std=c++23

Write-Output "Build Finish"