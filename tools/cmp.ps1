g++ ./test/data.cpp -o ./build/data.exe -O2 -std=c++20 -I C:/Users/Anak1st/Repos/Contests/include
g++ ./test/main.cpp -o ./build/main.exe -O2 -std=c++20
g++ ./test/pass.cpp -o ./build/pass.exe -O2 -std=c++20

Write-Output "Build Finish"

$txtdata = "./temp/data.txt"
$txtmain = "./temp/main.txt"
$txtpass = "./temp/pass.txt"

function Start-Main {
    Get-Content $txtdata | ./build/main.exe > $txtmain
}
function Start-Pass {
    Get-Content $txtdata | ./build/pass.exe > $txtpass
}

for ($i = 1; $i -le 200; $i++) {
    ./build/data.exe > $txtdata
    Write-Output ("# Test case {0}" -f $i)
    $t1 = (Measure-Command -Expression { Start-Main }).TotalSeconds
    $t2 = (Measure-Command -Expression { Start-Pass }).TotalSeconds
    Write-Output ("Main Time: {0:n4} Pass Time: {0:n4}" -f $t1 -f $t2)
    if (Compare-Object (Get-Content $txtmain) (Get-Content $txtpass)) {
        Write-Output "Wrong Answer"
        break
    }
    Write-Output ("Accepted" -f $i)
}
