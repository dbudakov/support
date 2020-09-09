### Восемь малоизвестных опций Bash [[link]](https://habr.com/ru/post/452522/)  


Если хотите посмотреть на текущие опции, запустите:  
```bash
$ set -o
$ shopt
```
Для активации опции используется длинный или короткий синтаксис:  
```sh
$ set -o errunset
$ set -e
$ shopt -s cdspell # <= on(-s set)
```
Чтобы отключить опцию, нужно поставить плюс вместо минуса:  
```sh
$ set +e
$ shopt -u cdspell # <=off(-u unset)
```

#### 1. cdspell  
С такой настройкой bash начнёт понимать опечатки и будет переносить вас в папку, название которой вы набрали с ошибкой.  
```sh
$ shopt -s cdspell
$ mkdir abcdefg
$ cd abcdeg
abcdefg
$ cd ..
```

#### 2. autocd  
Если вы не готовы мириться с неэффективностью многократного ввода cd, то можете установить эту опцию для перемещения в папку Х, если команда Х не существует.  
```sh
$ shopt -s autocd
$ abcdefg
$ cd ..
```
В сочетании с автозаполнением это позволяет быстро прыгать по папкам:   
```sh
$ ./abc[TAB][RETURN]
cd -- ./abcdefg
```

#### 3. direxpand  
Это классная опция, которая расширяет переменные среды по нажатию Tab:  
```sh
$ shopt -s direxpand
$ ./[TAB]     # заменяется на...
$ /full/path/to/current_working_folder
$ ~/[TAB]     # заменяется на...
$ /full/path/to/home/folder
$ $HOME/[TAB] #  заменяется на...
$ /full/path/to/home/folder
```
  
#### Чистый выход  
#### 4. checkjobs  

Этот параметр останавливает выход из сеанса, если в фоновом режиме ещё выполняются задания.  
   
Вместо выхода выводится список незавершённых заданий. Если вы всё равно хотите выйти, то ещё раз введите exit.  
```sh
$ shopt -s checkjobs
$ echo $$
68125             # <= ID процесса для оболочки
$ sleep 999 &
$ exit
There are running jobs.
[1]+  Running                 sleep 999 &
$ echo $$
68125             # <= ID процесса для оболочки тот же
$ exit
There are running jobs.
[1]+  Running                 sleep 999 &
$ exit
$ echo $$
$ 59316           # <= на этот раз ID процесса  изменился
```
#### Сверхспособности по подстановке  
#### 5. globstar  
Эта опция даёт вам сверхспособности по подстановке! Если ввести:   
```sh
$ shopt -s globstar
$ ls **
```
тогда оболочка покажет рекурсивно все каталоги и подкаталоги.  
  
В сочетании с `direxpand` можно быстро просматривать всё, что ниже в иерархии:  
```sh
$ shopt -s direxpand
$ ls **[TAB][TAB]
Display all 2033 possibilities? (y or n) 
```
#### 6. extglob  
Эта опция активирует функции, которые чаще ассоциируются с регулярными выражениями. Иногда это очень полезно:  
```sh
$ shopt -s extglob
$ touch afile bfile cfile
$ ls
afile bfile cfile
$ ls ?(a*|b*)
afile bfile
$ ls !(a*|b*)
cfile
```
Здесь шаблоны помещаются в круглые скобки и разделяются вертикальной чертой. Вот доступные операторы:  
  
\? = соответствует нулю или одному вхождению заданных шаблонов  
\! = показать всё, что не соответствует заданным шаблонам   
\* = ноль или более вхождений  
\+ = одно или более вхождений  
\@ = ровно одно вхождение  

#### Защита от несчастных случаев  
#### 7. histverify  
Поначалу может быть немного страшновато использовать использовать быстрый запуск команд из истории сокращениями !! и !$.  
Опция `histverify` позволяет сначала посмотреть, как Bash интерпретирует команду до того, как он на самом деле запустится:  
```sh  
$ shopt -s histverify
$ echo !$          # <= По нажатию Enter команда не запускается
$ echo histverify  # <= Она сначала демонстрируется на экране,
histverify         # <= а потом запускается 
```
#### 8. Noclobber  
Опять же, для защиты от несчастных случаев, а именно от перезаписи файла, который уже существует с оператором редиректа (>). Это может стать катастрофой, если у вас нет резервной копии.  
Опция `set -С` запрещает такую перезапись. В случае необходимости можно обойти защиту с помощью оператора `>|`:  
```sh
$ touch afile
$ set -C
$ echo something > afile
-bash: afile: cannot overwrite existing file
$ echo something >| afile
$
```