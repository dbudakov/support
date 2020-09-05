### Trap обработка сигналов и ошибок в Bash [[link]](https://laurvas.ru/bash-trap/)  

Организация `trap` для скрипта выглядит так:  
Запись `set -o noclobber`  - запрещает перезаписывать по оператору `>`, в уже существующий файл, если запись проходит, значит файла нет 
Мы записываем `$$(PID)` в `$lockfile`, и ставим `trap` на удаление в случает сигналов `INT` `TERM` `EXIT`  
Далее идет описание тела скрипта `ml` - это функция включающая все функции  
Удаление `$lockfile`  
`trap - INT TERM EXIT` - возвращает дефолтный обработчик сигнала
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
Прервать установку пакета(.deb)  
```sh
trap "kill -9 $$" INT TERM EXIT
...
...
...
trap - INT TERM EXIT
```
### Дополнительно по trap  
```
trap -lp - вывод номеров и названия сигналов для перехвата
trap "" 1 2 3 15 - игнорирование следующих сигналов

01 SIGHUP   hangup, освобождение линии связи;
02 SIGINT   interrupt, прерывание;
03 SIGQUIT  quit, выход;
15 SIGTERM  terminate, программный сигнал завершения.
```

```
 1) SIGHUP       2) SIGINT       3) SIGQUIT      4) SIGILL       5) SIGTRAP
 6) SIGABRT      7) SIGBUS       8) SIGFPE       9) SIGKILL     10) SIGUSR1
11) SIGSEGV     12) SIGUSR2     13) SIGPIPE     14) SIGALRM     15) SIGTERM
16) SIGSTKFLT   17) SIGCHLD     18) SIGCONT     19) SIGSTOP     20) SIGTSTP
21) SIGTTIN     22) SIGTTOU     23) SIGURG      24) SIGXCPU     25) SIGXFSZ
26) SIGVTALRM   27) SIGPROF     28) SIGWINCH    29) SIGIO       30) SIGPWR
31) SIGSYS      34) SIGRTMIN    35) SIGRTMIN+1  36) SIGRTMIN+2  37) SIGRTMIN+3
38) SIGRTMIN+4  39) SIGRTMIN+5  40) SIGRTMIN+6  41) SIGRTMIN+7  42) SIGRTMIN+8
43) SIGRTMIN+9  44) SIGRTMIN+10 45) SIGRTMIN+11 46) SIGRTMIN+12 47) SIGRTMIN+13
48) SIGRTMIN+14 49) SIGRTMIN+15 50) SIGRTMAX-14 51) SIGRTMAX-13 52) SIGRTMAX-12
53) SIGRTMAX-11 54) SIGRTMAX-10 55) SIGRTMAX-9  56) SIGRTMAX-8  57) SIGRTMAX-7
58) SIGRTMAX-6  59) SIGRTMAX-5  60) SIGRTMAX-4  61) SIGRTMAX-3  62) SIGRTMAX-2
63) SIGRTMAX-1  64) SIGRTMAX
```
