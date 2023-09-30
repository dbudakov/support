# buffer

Идет запись в буфер, обработка и вывод строки, далее идет восстановление из буфера и повторная обработка

## Example

```sh
echo 'one
one,two
one,two,three'>  file
```

```sh
sed -e '{p; /one/ {h;s/two/MOM/p;g; {s/two/DAD/p;d;}}}' file

# h; - записать шаблон обработки в буфер
# g; - восстановить из буфера
```

Без использования буфера, нужно обрабатывать уже новую строку

```sh
sed -e '{p; /one/ {s/two/MOM/p; {s/MOM/DAD/p;d;}}}' file
```

*источник:* _4. Multi-Line Slow Sliding Window_ <https://www.baeldung.com/linux/sed-replace-multi-line-string#3-editing-in-action>