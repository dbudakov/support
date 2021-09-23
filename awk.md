Суммируем 3-й столбец из лог файла.  
```
cat logfile| awk '{s += $3} END {print s}'
```
Передача переменных
```sh
echo -e "1\n2\n3\n4\n5" >> /tmp/1
a=3
cat /tmp/1| awk -v b=${a}  '/'$a'/ {print $b}'

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

создание объектрого массива, условия певрого, последнего элементов
```
echo "one two three" |
awk '{
  for(i=1;i<=NF;i++){
    if (NF == 1)
	printf "[%s]", $i;
    else if ($i == $1)
      printf "[%s, ", $i;
    else if ($i == $NF)
      printf "%s]", $i;
    else
      printf "%s, ", $i}
}'
 ```
