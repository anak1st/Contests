#!/usr/bin/zsh

g++ ./src/temp/data.cpp -o ./build/data -O2 -std=c++23
g++ ./src/temp/main.cpp -o ./build/main -O2 -std=c++23
g++ ./src/temp/pass.cpp -o ./build/pass -O2 -std=c++23

for ((i=1; i<=100; i++))
do
	./build/data > ./log/data.txt
	./build/main < ./log/data.txt > ./log/main.txt
	./build/pass < ./log/data.txt > ./log/pass.txt
	if diff ./log/main.txt ./log/pass.txt; then
		printf "#$i Accepted\n"
	else
		printf "Wrong Answer\n"
		break
	fi
done