$mingwDir = "C:\Development\msys64\ucrt64"

$header    = "$mingwDir\include\c++\13.1.0\x86_64-w64-mingw32\bits\stdc++.h"
$gchFolder = "$mingwDir\include\c++\13.1.0\x86_64-w64-mingw32\bits\stdc++.h.gch"

g++ $header -std=c++20 -O2 -o $gchFolder\stdc++.h.release.gch
g++ $header -std=c++20 -g  -o $gchFolder\stdc++.h.debug.gch

$binFolder = "$mingwDir\bin"
Copy-Item $binFolder\libstdc++-6.dll     .\build\libstdc++-6.dll
Copy-Item $binFolder\libgcc_s_seh-1.dll  .\build\libgcc_s_seh-1.dll
Copy-Item $binFolder\libwinpthread-1.dll .\build\libwinpthread-1.dll
