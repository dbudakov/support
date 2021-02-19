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

Посмотреть версии пакетов

```sh
yum --showduplicates list mongodb-org
```

Подключение, отключение репозиториев:

```sh
yum-config-manager --enable docker-ce-test
yum-config-manager --disable docker-ce-nightly
```

GPG

```sh
# Проверка пакета
rpm -K epel-release-latest-8.noarch.rpm 

# Импорт открытого ключа
rpm --import RPM-GPG-KEY-EPEL-8 

# Вывод списка ключей
rpm -qa gpg-pubkey*

# Информация о ключе
rpm -qi gpg-pubkey-2f86d6a1-5cf7cefb

# Удаление ключа
sudo rpm -e gpg-pubkey-2f86d6a1-5cf7cefb
```
