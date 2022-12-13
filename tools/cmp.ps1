g++ ./src/test/test.cpp -o ./build/main.exe -O2 -std=c++23
g++ ./src/test/data.cpp -o ./build/data.exe -O2 -std=c++23
g++ ./src/test/ok.cpp   -o ./build/ok.exe   -O2 -std=c++23

Write-Output "Build Finish"

$in="./temp/log/in.txt"
$out="./temp/log/out.txt"
$ok="./temp/log/ok.txt"

for($i=1; $i -le 100; $i++) {
    ./build/data.exe > $in
    Get-Content $in | ./build/main.exe > $out
    Get-Content $in | ./build/ok.exe   > $ok
    if (Compare-Object (Get-Content $out) (Get-Content $ok)) {
        Write-Output "Wrong Answer"
        break
    }
    Write-Output ("#{0} Accepted" -f $i)
}
