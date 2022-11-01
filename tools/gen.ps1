$std=".\src\problems\Bones\std.cpp"
$gen=".\src\problems\Bones\gen.cpp"

g++ $std -o ./build/main.exe -O2 -std=c++23
g++ $gen -o ./build/data.exe -O2 -std=c++23 -I C:\Users\xiafa\Repos\C++\testlib\

for($i=1; $i -le 10; $i++) {
    ./build/data.exe 1000 10000 $i > ("./data/private/{0}.in" -f $i)
    Get-Content ("./data/private/{0}.in" -f $i) | ./build/main.exe > ("./data/private/{0}.out" -f $i)
}
