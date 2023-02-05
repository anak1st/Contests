$testlibDir = "C:\Users\Anak1st\Repos\C++\testlib"
$rootDir = ".\private\vtuber"
$std = "$rootDir\std.cpp"
$gen = "$rootDir\gen.cpp"

g++ $gen -o .\build\data.exe -O2 -std=c++20 -I $testlibDir 
g++ $std -o .\build\main.exe -O2 -std=c++20

for ($i = 6; $i -le 10; $i++) {
    $in  = ("$rootDir\data\{0}.in"  -f $i)
    $out = ("$rootDir\data\{0}.out" -f $i)
    if (-not(Test-Path $in)) {
        New-Item $in -ItemType File
    }
    if (-not(Test-Path $out)) {
        New-Item $out -ItemType File
    }
    # .\build\data.exe 1000 1000 $i > $in
    .\build\data.exe > $in
    Get-Content $in | .\build\main.exe > $out
    Write-Output("Finished generate test {0}" -f $i)
}
