# Using sed to Replace a Multi-Line String

<https://www.baeldung.com/linux/sed-replace-multi-line-string>

## Two-Level pattern

```sh
echo 'Name: Alex
Department: Tech
Name: Richard
Department: Finance
Name: Alex
Department: Analytics' > emp-db.txt
```

Меняет 'Tech'  на 'Product' для 'Alex', обрабатывая две строки
Описание: sed забирает строку с шаблоном 'Alex' печатает её(p;), переходит к новой строке(n;), в новой строке забирает строку с шаблоном 'Tech' , выполняет подстановку, распечатывает ее(p;) и прерывает обработку(d;), эта строка уже не печатается, остальные строки печатаются на последней команде(p;)

```sh
sed -n -e '/Alex/ {p;n; /Tech/ {s/Tech/Product/;p;d;}};p;' emp-db.txt
sed -n -f nested-read.string.sed emp-db.txt

# p; печатать текущую строку
# n; взять в обработку новую строку
# d; выйти из обработки и перезапустить цикл чтения
```

## out of order

```sh
echo 'Name: Alex
Department: Tech
EmpId: 100
Name: George
Department: HR
EmpId: 500' > emp-db.txt
```

Меняет 'HR' на 'Finance' для 'EmpID: 500'

```sh
sed -E -n -e 'N;N;s/(.*\n)(.*: ).*(\n.*: 500)/\1\2Finance\3/;p;d;' emp-db.txt
sed -E -n -f emp.sed emp-db.txt

# N; - добавляется новую строке к обработке, вместро "string1" будет "sting1\nstring2"
# (.*\n), (.*: ), (\n.*: 500) - шаблоны \1,\2,\3
# d; - прерывает обработке, делает шаг на количество обработаннных строк
```

## Overlapping Records, buffer

```sh
echo 'Day-1:0
Day-2:1
Day-3:1
Day-4:1
Day-5:0
Day-6:1
Day-7:1' > workshop_calendar.txt
```

Будет вывод дней, за которыми следует день со значением один, то есть две единицы подряд

```sh
sed -E -n -e 'N; /.*:1\n.*:1/ {h; s/(.*):1(\n.*:1)/\1/p; g;}; D' workshop_calendar.txt
sed -E -n -f workshop.sed workshop_calendar.txt

# N; - добавляет к шаблону новую строку
# p; - печатает обрабатываемую строку
# h; - сохранить пространстро шаблона в буфер
# g; - восстановить пространство шаблона из буфера
# D; - удаляет первую строку из шаблона
```

## Gobbling, обработка всего файла, реверс файла

```sh
echo 'e9
e2
e3
e4
e8
e6
e7
e1
e5' > employees.txt
```

, забирает первую строку на удержание, далее обрабатывает каждую строку со 2 по последнюю, берет строку и добавляет к ней удержание и обновляет область удержания(буфер), получается
2+1 	> buff,
3+2+1	> buff,
4+3+2+1	> buff;
В вывод идет только последняя строка, иначе будет в вывод попадают все шаги обновления буфера

```sh
sed -n -e '1 {h;};2,$ {G;h;};$p;' employees.txt
sed -n -f reverse.sed employees.txt

# h; - удерживает первую строку
# G; - берет строку и добавляет удержание(буфер)
# h; - обновляет удержание уже с двумя строками
# $p; - вывод только результирующей склейки
```

## 6. Mapping Data Between Two Files

```sh
echo 'p1
p2
p3' > projects.txt
```

Делит участников по 3-ое и назначает каждой группе проект, работает с двумя файлами

```sh
sed -E -n -e '/^p[0-9]+/ {1h;2,$H;$d;}; /^e[0-9]+/ {N;N;s/\n/,/g;s/.*/(&)/;P;x;P;s/^[^\n]*\n//;x;D;}' projects.txt employees.txt
sed -E -n -f mapping.sed projects.txt employees.txt

# шаблон - то что обрабатывается, удержание - то что в буфере
# N command -
# P command - Печатает первую строку из области шаблонов
# x command - обменивается содержимым между пространствами шалонов и удержания
# H command -
# D command - удаляет первую строку из обшасти шаблонов

```

