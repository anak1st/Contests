$mingwDir = "C:\msys2\ucrt64\"
$header = "$mingwDir\include\c++\12.2.0\x86_64-w64-mingw32\bits\stdc++.h"
g++ $header -std=c++20 -O2
Copy-Item $header .\build\stdc++.h
g++ .\build\stdc++.h -std=c++20 -g