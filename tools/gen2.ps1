$rootDir = ".\private\C--"
$std = "$rootDir\std.cpp"

g++ $std -o .\build\main.exe -O2 -std=c++20

for ($i = 1; $i -le 4; $i++) {
    $in  = ("$rootDir\data\{0}.in"  -f $i)
    $out = ("$rootDir\data\{0}.out" -f $i)
    Get-Content $in | .\build\main.exe > $out
    Write-Output("Finished generate test {0}" -f $i)
}
