for($i=1; $i -le 100; $i++) {
    ./build/data.exe > ./log/in.txt
    Get-Content ./log/in.txt | ./build/main.exe > ./log/out.txt
    Get-Content ./log/in.txt | ./build/ok.exe   > ./log/ok.txt
    if (Compare-Object (Get-Content ./log/out.txt) (Get-Content ./log/ok.txt)) {
        Write-Output "Wrong Answer"
        break
    }
    Write-Output ("#{0} Accepted" -f $i)
}
