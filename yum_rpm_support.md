узнать пакет для утилиты
```
  yum whatprovides [tools] || 
    например
    yum whatprovides semanage  
```
установить пакет из сетевого репозитория без загрузки    
```  
rpm -Uhv http:// || rpm -i http://  
```
узнать установленные пакеты  
```
      rpm -qa
      yum list installed
    Использование yum-utils 
      yum update && yum install yum-utils
      repoquery -a --installed 
    Установленные пакеты из определенного репозитория
      yumdb search from_repo base
  http://blog.sedicomm.com/2018/02/04/3-sposoba-uznat-vse-ustanovlennye-pakety-v-rhel-centos-i-fedora/
```
