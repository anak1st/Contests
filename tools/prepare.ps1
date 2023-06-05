$mingwDir = "C:\Users\Anak1st\scoop\apps\mingw\current"

$binFolder = "$mingwDir\bin"
Copy-Item $binFolder\libstdc++-6.dll     .\build\libstdc++-6.dll
Copy-Item $binFolder\libgcc_s_seh-1.dll  .\build\libgcc_s_seh-1.dll
Copy-Item $binFolder\libwinpthread-1.dll .\build\libwinpthread-1.dll
