$mingwDir = "C:\msys2\ucrt64"
$header = "$mingwDir\include\c++\12.2.0\x86_64-w64-mingw32\bits\stdc++.h"
g++ $header -std=c++20 -O2
Copy-Item $header .\build\stdc++.h
g++ .\build\stdc++.h -std=c++20 -g

$binFolder = "$mingwDir\bin"
Copy-Item $binFolder\libstdc++-6.dll .\build\libstdc++-6.dll
Copy-Item $binFolder\libgcc_s_seh-1.dll .\build\libgcc_s_seh-1.dll
Copy-Item $binFolder\libwinpthread-1.dll .\build\libwinpthread-1.dll