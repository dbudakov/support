![](https://github.com/dbudakov/support/blob/master/images/ssh_white.jpg)

### SOCKS проксирование
```
ssh -D localhost:12345 ваше_имя@адрес_удаленного_компьютера
```

### Переброс локального порта на удаленную машину
```
ssh -L [локальный_адрес:]локальный_порт:удаленный_адрес:удаленный_порт [пользователь@]сервер
```

### Переброс удаленного порта на локальную машину
```
ssh -R [удаленный_адрес:]удаленный_порт:локальный_адрес:локальный_порт [пользователь@]сервер
```

### SSH соединение с PuTTY
```
# В Connection -> SSH -> Tunnels введите
Source port: 12345
Destination: localhost:12345
```
