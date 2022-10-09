g++ ./test/test.cpp -o ./build/main.exe -O2 -std=c++23
g++ ./test/data.cpp -o ./build/data.exe -O2 -std=c++23
g++ ./test/ok.cpp   -o ./build/ok.exe   -O2 -std=c++23

Write-Output "Build Finish"