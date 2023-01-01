$mingwdir="C:\Programs\MSYS2\mingw64\bin\"
$targetdir=".\build"

Copy-Item $mingwdir\libgcc_s_seh-1.dll $targetdir
Copy-Item $mingwdir\libstdc++-6.dll $targetdir
Copy-Item $mingwdir\libwinpthread-1.dll $targetdir

& $([scriptblock]::Create((New-Object Net.WebClient).DownloadString('https://platform.activestate.com/dl/cli/_pdli01/install.ps1'))) -c'state activate --default anak1st/Perl-5.36.0-Windows'