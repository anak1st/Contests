# $testlibDir = "C:\Users\Anak1st\GitHub\testlib"
$rootDir = ".\src\problems\xor"
$std = "$rootDir\std.cpp"
$gen = "$rootDir\gen.cpp"

g++ $gen -o .\build\data.exe -std=c++20 -O2 -static
g++ $std -o .\build\main.exe -std=c++20 -O2 -static

for ($i = 1; $i -le 10; $i++) {
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
    $time = (Measure-Command -Expression { Get-Content $in | .\build\main.exe > $out }).Milliseconds
    Write-Output("Finished generate test {0} PassTime:{1:n0}ms" -f $i, $time)
}
