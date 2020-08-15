Суммируем 3-й столбец из лог файла.  
```
cat logfile| awk '{s += $3} END {print s}'
```
