$in="./data/log/in.txt"
$out="./data/log/out.txt"
$ok="./data/log/out.txt"

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
