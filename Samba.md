#### Пример SAMBA с анонимным пользователем при использовании samba 4 был доработан следующим образом:  
```
chown -R nobody:nobody
/var/samba/anonymous_share
```
В секцию шары была добавлена строка:
```
force user = nobody
```
Не забываем про Selinux:
```
chcon -t samba_share_t 
/var/samba/anonymous_share
``
Рестартим:
```
testparm
systemctl reload smb
```
Монтируемся с клиента и проверяем:
```
[root@client mnt]# umount /mnt/samba 
[root@client mnt]# mount -t cifs -o guest '//192.168.11.170/anonymous' /mnt/samba/
[root@client mnt]# touch /mnt/samba/1
[root@client mnt]#
```
