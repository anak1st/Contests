g++ ./test/test.cpp -o ./build/main.exe -O2 -std=c++23
g++ ./test/data.cpp -o ./build/data.exe -O2 -std=c++23
g++ ./test/ok.cpp   -o ./build/ok.exe   -O2 -std=c++23

Write-Output "Finish Compile"

for($i=1; $i -le 200; $i++) {
    ./build/data.exe > ./log/in.txt
    Get-Content ./log/in.txt | ./build/main.exe > ./log/out.txt
    Get-Content ./log/in.txt | ./build/ok.exe   > ./log/ok.txt
    if (Compare-Object (Get-Content ./log/out.txt) (Get-Content ./log/ok.txt)) {
        Write-Output "Wrong Answer"
        break
    }
    Write-Output ("#{0} Accepted" -f $i)
}
