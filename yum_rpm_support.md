yum шпаргалка  
https://habr.com/ru/post/301292/  

Узнать в каком пакете содержиться утилита
```
  yum whatprovides [tools] || 
    например
    yum whatprovides semanage  
```
Установить пакет из сетевого репозитория без загрузки    
```  
rpm -Uhv http:// || rpm -i http://  
```

Узнать установленные пакеты  
http://blog.sedicomm.com/2018/02/04/3-sposoba-uznat-vse-ustanovlennye-pakety-v-rhel-centos-i-fedora/
```
## Использую базовые утилиты
rpm -qa
yum list installed

## Через yum-utils   
yum update && yum install yum-utils
repoquery -a --installed 

## Установленные пакеты из определенного репозитория
yumdb search from_repo base
  
```

Обновить один пакет
```
yum update [make]
```