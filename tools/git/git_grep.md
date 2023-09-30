`git grep` - по рабочему каталогу
`git grep -n` - максимальное кол-во совпадений в файлах
`git grep --count gmtime_r`- вывод количества совпадений для фалов
`git grep -p gmtime_r *.c` - вывод файла и функции вызывающие регулярное выражение
`git grep --break --heading -n -e '#define' --and \( -e LINK -e BUF_MAX \) v1.8.0` - составной запрос по _#define_ и _BUF-MAX_
