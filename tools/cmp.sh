#!/usr/bin/zsh

g++ ./test/data.cpp -o ./build/data -O2 -std=c++20
g++ ./test/main.cpp -o ./build/main -O2 -std=c++20
g++ ./test/pass.cpp -o ./build/pass -O2 -std=c++20

for ((i=1; i<=100; i++))
do
	./build/data > ./temp/data.txt
	./build/main < ./temp/data.txt > ./temp/main.txt
	./build/pass < ./temp/data.txt > ./temp/pass.txt
	if diff ./temp/main.txt ./temp/pass.txt; then
		printf "#$i Accepted\n"
	else
		printf "Wrong Answer\n"
		break
	fi
done