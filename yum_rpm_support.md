yum шпаргалка  [link](https://habr.com/ru/post/301292/)  

Узнать в каком пакете содержиться утилита

```sh
  yum whatprovides [tools] || 
    например
    yum whatprovides semanage  
```

Установить пакет из сетевого репозитория без загрузки  

```sh
rpm -Uhv http:// || rpm -i http://  
```

Узнать установленные пакеты  [link](http://blog.sedicomm.com/2018/02/04/3-sposoba-uznat-vse-ustanovlennye-pakety-v-rhel-centos-i-fedora/)

```sh
## Использую базовые утилиты
rpm -qa
yum list installed

## Через yum-utils   
yum update && yum install yum-utils
repoquery -a --installed 

## Установленные пакеты из определенного репозитория
yumdb search from_repo base
  
## Состав группы пакетов
yum whatprovides 'rpmlib(SetVersions)'

```

Обновить один пакет

```sh
yum update [make]
```

Вывести список репозиториев

```sh
yum repolist
yum repolist enabled
```
