@echo off

g++ .\test\data.cpp -o .\build\data.exe -O2 -std=c++11
g++ .\test\main.cpp -o .\build\main.exe -O2 -std=c++11
g++ .\test\pass.cpp -o .\build\pass.exe -O2 -std=c++11

echo "Build Finished"

:loop
.\build\data.exe > .\temp\data.txt
.\build\main.exe < .\temp\data.txt > .\temp\main.txt
.\build\pass.exe < .\temp\data.txt > .\temp\pass.txt
fc .\temp\main.txt .\temp\pass.txt
if errorlevel 1 (
    echo "Wrong Answer"
    pause
)
goto loop