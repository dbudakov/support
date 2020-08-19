#### Звуковое сопровождение пинг
Изначально создаем шаблон звукового сигнала(Ctrl+G) из консоли
```cmd
echo ^G > beep.txt
```

Далее пишем цикл с передачей параметра  
создаем файл `beep_ping.bat` следующего содержания
```cmd
@echo off

:loop
ping %1 -n 1 | findstr TTL && more beep.txt || echo "not connect"
timeout 2 > null
goto loop
```
все просто, пингуем и в выводе ищем `TTL`, вслучае наличия выводим звуковой сигнал, иначе `"not connect"`, ждем 2 сек, возвращаемся к метке `:loop`  
**вызов скрипта**
```cmd
beep_ping.bat ya.ru
```


Для примера используется `more beep.txt`, можно заменить на `echo ^G`  
Выход осуществляется через `Ctrl+C` и подтверждение выхода