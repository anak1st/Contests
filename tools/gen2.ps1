$rootDir = ".\src\problems\xor"
$std = "$rootDir\std.cpp"

g++ $std -o .\build\main.exe -std=c++20 -O2 -static

for ($i = 1; $i -le 10; $i++) {
    $in  = ("$rootDir\data\{0}.in"  -f $i)
    $out = ("$rootDir\data\{0}.out" -f $i)
    $time = (Measure-Command -Expression { Get-Content $in | .\build\main.exe > $out }).Milliseconds
    Write-Output("Finished test {0} PassTime:{1:n0}ms" -f $i, $time)
}
