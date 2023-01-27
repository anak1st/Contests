g++ ./src/temp/data.cpp -o ./build/data.exe -O2 -std=c++23 -I C:/Users/Anak1st/Contests/include
g++ ./src/temp/main.cpp -o ./build/main.exe -O2 -std=c++23
g++ ./src/temp/pass.cpp -o ./build/pass.exe -O2 -std=c++23

Write-Output "Build Finish"

$logdata = "./temp/log/data.txt"
$logmain = "./temp/log/main.txt"
$logpass = "./temp/log/pass.txt"

function Start-Main {
    Get-Content $logdata | ./build/main.exe > $logmain
}
function Start-Pass {
    Get-Content $logdata | ./build/pass.exe > $logpass
}

for ($i = 1; $i -le 10; $i++) {
    ./build/data.exe > $logdata
    Write-Output ("# Test case {0}" -f $i)
    $t1 = (Measure-Command -Expression { Start-Main }).TotalSeconds
    Write-Output ("    Main Time: {0}" -f $t1)
    $t2 = (Measure-Command -Expression { Start-Pass }).TotalSeconds
    Write-Output ("    Pass Time: {0}" -f $t2)
    if (Compare-Object (Get-Content $logmain) (Get-Content $logpass)) {
        Write-Output "Wrong Answer"
        break
    }
    Write-Output ("    Accepted" -f $i)
}
