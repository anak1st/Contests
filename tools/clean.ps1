$latexdir=".\assets\docs\"

Remove-Item .\build\cph\*
Remove-Item $latexdir\*.aux
Remove-Item $latexdir\*.fdb_latexmk
Remove-Item $latexdir\*.fls
Remove-Item $latexdir\*.log
Remove-Item $latexdir\*.out
Remove-Item $latexdir\*.synctex.gz
Remove-Item $latexdir\*.xdv

Get-ChildItem * -Include *.exe -Recurse | Remove-Item