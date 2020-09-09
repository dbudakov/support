Особенности работы bash [[link]](https://www.opennet.ru/docs/RUS/bash/bash.html#toc7)  

Удалить элемент из массива [[link]](https://coderoad.ru/23462869/%D0%A3%D0%B4%D0%B0%D0%BB%D0%B8%D1%82%D1%8C-%D1%8D%D0%BB%D0%B5%D0%BC%D0%B5%D0%BD%D1%82-%D0%B8%D0%B7-%D0%BC%D0%B0%D1%81%D1%81%D0%B8%D0%B2%D0%B0-bash-%D0%BF%D0%BE-%D1%81%D0%BE%D0%B4%D0%B5%D1%80%D0%B6%D0%B8%D0%BC%D0%BE%D0%BC%D1%83-%D1%85%D1%80%D0%B0%D0%BD%D1%8F%D1%89%D0%B5%D0%BC%D1%83%D1%81%D1%8F-%D0%B2-%D0%BF%D0%B5%D1%80%D0%B5%D0%BC%D0%B5%D0%BD%D0%BD%D0%BE%D0%B9-%D0%BD%D0%B5)

Операторы  
Условные операторы: `case`, `if`, `test`  
Операторы цикла: `for`, `while`, `until`, `select`  

Для инклуда библиотечной функции используется команда `source`  

Пример [`trap`](https://github.com/dbudakov/support/blob/master/trap.md) и дополнительно по [`set`](https://github.com/dbudakov/support/blob/master/set.md)
```
if ( set -o noclobber; echo "$$" > "$lockfile") 1> /dev/null; 
then                                                
  trap 'rm -f "$lockfile"; exit $?' INT  TERM EXIT  
  ml                                                
  sleep 30                                          
  rm -f "$lockfile"                                 
  trap - INT TERM EXIT                              
else                                                
  echo "program running"                            
fi 
```
```
trap -lp - вывод номеров и названия сигналов для перехвата
trap "" 1 2 3 15 - игнорирование следующих сигналов
```


```sh
list=(one two three)
var="two"
list=( "${list[@]/$var}" )
list=( "${list[@]/two}" )
echo ${list[@]}
 one three
echo ${#list[@]}
 3
```
Цепочки  
```
true && true  && echo 1 || echo 2 # выведет 1
true && false && echo 1 || echo 2 # выведет 2
true && true  && echo 1 || echo 2 && echo 3 # выведет "1 3"
```
В случае если нужно выбрать что обрабатывать оптимально прогонять весь список и делать проверку на взведенный флаг, если бекап снимается в одной операции а удаление в другой, то возможен вариант неконсистентного бекапа и удаление каталога.
```sh
# запрос строки bp_list, в ней содержаться имена для обработки
bp_list=(api)
spo_default=(api www setup)

for path in ${spo_default[@]};do
  if [ $(echo $bp_list|grep -cw $path) -eq 1 ]
    then
      tar czpf $dump_path/${path}-$(date +%Y%m%d_%H%M).tar.gz /DATA/$path &>>$dump_path/log/tar_$path.log &&
      /bin/rm -rf /DATA/$path ||
      echo false
    else
      /bin/rm -rf /DATA/$path || 
      echo false
  fi
done
```
Выведет список файлов в `/tmp` и прочитает указанный
```sh
select file in /tmp/* Quit;
do if [ -f $file ]; 
  then cat $file; 
  else break; 
fi; 
  break;
done
```
### Логгирование
Для логов используются утилиты exec, tee, scripts  
```sh
# утилита exec
$ tty
/dev/pts/2
$ echo "вывод на терминал"
вывод на терминал
$ exec > log
$ echo "вывод в файл log"
$ echo "и это в log"
$ exec > /dev/pts/2
$ echo "вывод на терминал"
вывод на терминал
```
```sh
srt - сортировка вывода
column -t - вывод в виде таблицы
```
 ### Выбрать элементы кроме
```sh
touch 1 2 3 4 5 a b c A B C ; rm -f *!([3-5]|[a]) 
touch 1 2 3 ; ls !(3)
```
