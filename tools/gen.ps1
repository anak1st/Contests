for($i = 5; $i -le 10; $i++) {
    ./build/gen.exe 1000 10000 $i > ("./data/{0}.in" -f $i)
    Get-Content ("./data/{0}.in" -f $i) | ./build/std.exe > ("./data/{0}.out" -f $i)
}
