g++ ./src/test/test.cpp -o ./build/main.exe -O2 -std=c++23
g++ ./src/test/data.cpp -o ./build/data.exe -O2 -std=c++23
g++ ./src/test/ok.cpp   -o ./build/ok.exe   -O2 -std=c++23

Write-Output "Build Finish"

$in  = "./temp/log/in.txt"
$out = "./temp/log/out.txt"
$ok  = "./temp/log/ok.txt"

function Start-Test {
    Get-Content $in | ./build/main.exe > $out
}
function Start-STD {
    Get-Content $in | ./build/ok.exe   > $ok
}

for ($i = 1; $i -le 100; $i++) {
    ./build/data.exe > $in
    Write-Output ("# Test case {0}" -f $i)
    $t1 = (Measure-Command -Expression { Start-Test }).TotalSeconds
    Write-Output ("    Test Time: {0}" -f $t1)
    $t2 = (Measure-Command -Expression { Start-STD  }).TotalSeconds
    Write-Output ("    STD  Time: {0}" -f $t2)
    if (Compare-Object (Get-Content $out) (Get-Content $ok)) {
        Write-Output "Wrong Answer"
        break
    }
    Write-Output ("    Accepted" -f $i)
}
