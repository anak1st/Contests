#!/usr/bin/zsh

g++ ./src/test/test.cpp -o ./build/main -O2 -std=c++23
g++ ./src/test/data.cpp -o ./build/data -O2 -std=c++23
g++ ./src/test/ok.cpp   -o ./build/ok   -O2 -std=c++23

for ((i=1; i<=100; i++))
do
	./build/data > ./log/in.txt
	./build/main < ./log/in.txt > ./log/out.txt
	./build/ok   < ./log/in.txt > ./log/ok.txt
	if diff ./log/in.txt ./log/ok.txt; then
		printf "#$i Accepted\n"
	else
		printf "Wrong Answer\n"
		break
	fi
done