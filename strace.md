strace -f [command] - перед командой, вывод информации по процессу    
strace -f -p $(ps ax | grep /usr/sbin/sshd|awk '{print $1}') - вывод информации по номеру PID
strace -f -o example_name.strace [command] - вывод в файл
execve - интерпритация параметров    
nmap - инклуд библиотек     
connect - подсоединение  
send/recv - операции обмена  
close - закрытие сокета  
bind - связка файла с дескриптором сокета  
listen - прослушка подключений  
select - для форка процесса, в случае множества подключений, служит для приема и обработки новых подключений
  select(8 [3 4 6]) 
    3 4 6 - набор открытых сокетов  
  accept(3, {sa_family=AF_INET, sin_port=htons(61805), sin_addr=inet_addr("10.51.21.1")}, [16])=5
    AF_INET - указывает на работу по TCP сокету
    61805 - клиентский порт
    10.51.21.1 - клиентский адрес
  clone() - непосредственно сам форк
wait4 - для завершения select


Операции strace  
socket()   
bind()  
listen()  
accept()  
recv()  
send()  
close()  
unlink()  
connect()  
select()  
wait4()
clone()

можно почитать о них в мануалах  
  man accept - описание подключения на сокет  
