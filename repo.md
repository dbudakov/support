## Репозитории  
```
yum repolist      - список установленных репозиториев  
/etc/yum.repos.d  - конфиги установленных репозиториев 
```
### Добавление репозитория:  
```
curl -o /etc/yum.repos.d/[name].repo [http://lnk]  
```
## Cписок репозиториев  

#### Kernels
```
http://elrepo.org/tiki/tiki-index.php       //ванильлные ядра
https://www.kernel.org/                     //ванильные ядра
http://yum.oracle.com/public-yum-ol7.repo   //OUEK - Oracle Unbreakable Enterprise Kernel

```
#### Packets
```
sudo yum install epel-release               //репозиторий с большим количеством пакетов  
```
