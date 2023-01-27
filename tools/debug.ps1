$mingwdir = "C:\Users\Anak1st\msys2\mingw64\bin\"
$targetdir = ".\build"

Copy-Item $mingwdir\libgcc_s_seh-1.dll  $targetdir
Copy-Item $mingwdir\libstdc++-6.dll     $targetdir
Copy-Item $mingwdir\libwinpthread-1.dll $targetdir
