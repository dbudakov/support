Суммируем 3-й столбец из лог файла.  
```
cat logfile| awk '{s += $3} END {print s}'
```
Передача переменных
```sh
echo -e "1\n2\n3\n4\n5" >> /tmp/1
a=3
cat /tmp/1| awk '/'$a'/{print $a}'

# Уточнить эти моменты
# a=8
# awk 'b=$a'
# awk -v b=$a
```

Вывод номера строки:
```
awk '(NR == 26)' /path/to/file
```

Суммируем 3-й столбец из лог файла.
```
cat logfile| awk '{s += $3} END {print s}'
```
