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

```sh
cat<<EOF>/tmp/file
one
one,two
one,two,three
EOF

# Изменить one на BANG если НЕ строка содержит two И не содержит three
sed -Ee '/two|three/! s/one/BANG/' /tmp/file

# Изменить one на BANG если строка содержит two И не содержит three
sed -e '/two/!n' -e '/three/! s/one/BANG/' /tmp/file
```
