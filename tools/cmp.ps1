g++ ./test/data.cpp -o ./build/data.exe -O2 -std=c++20 -I ./include
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

$tot = 50;
$tottime1 = 0
$tottime2 = 0
foreach ($i in 1..$tot) {
    ./build/data.exe > $txtdata
    $time1 = (Measure-Command -Expression { Start-Main }).Milliseconds
    $time2 = (Measure-Command -Expression { Start-Pass }).Milliseconds
    $tottime1 += $time1
    $tottime2 += $time2
    $str = ("test[{0}] MainTime:{1:n0}ms PassTime:{2:n0}ms" -f $i, $time1, $time2)
    Write-Progress -Activity "Search in Progress" -Status "$str" -PercentComplete ($i / $tot * 100)
    if (Compare-Object (Get-Content $txtmain) (Get-Content $txtpass)) {
        Write-Output "Wrong Answer"
        break
    }
}
$avgtime1 = $tottime1 / $tot
$avgtime2 = $tottime2 / $tot
Write-Output ("Accepted MainTime:{0:n0}ms PassTime:{1:n0}ms" -f $avgtime1, $avgtime2)