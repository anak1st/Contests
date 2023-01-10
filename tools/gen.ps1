$testlibDir = "C:\Developer\Source\testlib\"
$std = ".\src\problems\Bones\std.cpp"
$gen = ".\src\problems\Bones\gen.cpp"

g++ $std -o .\build\main.exe -O2 -std=c++23
g++ $gen -o .\build\data.exe -O2 -std=c++23 -I $testlibDir

for ($i = 1; $i -le 10; $i++) {
    $in = ("./temp/private/{0}.in" -f $i)
    $out = ("./temp/private/{0}.out" -f $i)
    .\build\data.exe 1000 1000 $i > $in
    Get-Content $in | .\build\main.exe > $out
    Write-Output("Finished generate test {0}" -f $i)
}
