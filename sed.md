Для того чтобы экранировать `'` нужно набирать `'\''`     

Вывеси диапазон строк в середине файла(например с 10 по 15)
```bash
cat /path/to/source.file | sed -n 10,15p
```

Вывод номера строки
```
sed '26!D' /path/to/file
```

Вырезать все после символа
```
sed -r 's/W.+//' file
```

Вставить после строки
```
sed '14a\ hello' /path/file
```

И, ИЛИ для sed
```sh
cat<<EOF>file
one
one,two
one,two,three
EOF

# Изменить one на BANG если строка содержит two И НЕ содержит three
sed -e '/two/ {/three/! {s/one/BANG/}}' file
```

Поиск по типу файла
```
find ./ -type
find ./ --mime-type
```

Регулярка для ip  
```
sed -n '/\([0-9]\{1,3\}\.\)\{3\}[0-9]\{1,3\}/p' file
sed -rn '/([0-9]{1,3}\.){3}[0-9]{1,3}/p' file
```
