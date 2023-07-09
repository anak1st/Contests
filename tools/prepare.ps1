$mingwDir = "C:\msys2\ucrt64"

$binFolder = "$mingwDir\bin"
Copy-Item $binFolder\libstdc++-6.dll     .\build\libstdc++-6.dll
Copy-Item $binFolder\libgcc_s_seh-1.dll  .\build\libgcc_s_seh-1.dll
Copy-Item $binFolder\libwinpthread-1.dll .\build\libwinpthread-1.dll

$allHeader = "$mingwDir\include\c++\13.1.0\x86_64-w64-mingw32\bits\stdc++.h"
g++ $AllHeader -std=c++20 -O2 -static
# Copy-Item $AllHeader .\build\stdc++.h
# g++ .\build\stdc++.h -std=c++20 -g -static