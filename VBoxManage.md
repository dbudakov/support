## VirtualBox  
По настройки VmBox отдельный документ [здесь](https://github.com/dbudakov/support/blob/master/virtualbox_vmbox.md)   
  
  
  
[instruction](https://www.virtualbox.org/manual/ch08.html#vboxmanage-modifyvdi)  
добавление cd-rom на vm VBoxManage  
```shell
UUID=$(VBoxManage list vms|grep "kel"|awk '{print $2}')
#VBoxManage storageattach $UUID --storagectl IDE --port 0 --device 0 --type dvddrive --medium "b1270ae8-57da-45d8-b42a-67d0a3a92711"
#это основной диск с системой, частный случай  
VBoxManage storagectl $UUID --name SATA --add sata
# монтирование cdrom
VBoxManage storageattach arm01 --storagectl IDE --port 1 --device 0 --type dvddrive --medium "/home/dbudakov/astra/agg/стенд/dist.iso"
# монтирование системного диска
VBoxManage storageattach $UUID --storagectl SATA --port 1 --device 0 --type dvddrive --medium "/usr/share/virtualbox/VBoxGuestAdditions.iso"
```

Создание и удаление VM  
```
VBoxManage registervm     <filename>
VBoxManage unregistervm   <uuid>|<name> [--delete]
```

Для редактирования Host-only Adapter
```
file --> Host network manager[Ctrl + H]
```
Создание host-only adapter
```
 VBoxManage hostonlyif create
```
Модификация сетевой карты
```
VBoxManage modifyvm centralRouter --intnet3 intnet
VBoxManage modifyvm centralRouter --intnet3 testClient1
```
### Управление  
список хостов:  
```
vboxmanage list vms
```  
переименовать хост :   
```
echo -n "host_id or name: "; read a; echo -n "rename to: "; read b; vboxmanage modifyvm $a --name $b;
```  
запустить хост:   
```
echo -n "start host: ";read a;vboxmanage startvm $a --type headless
```  
выключить хост:   
```
echo -n "poweroff host: ";read a;vboxmanage controlvm $a poweroff
```  
вывести список IP для хоста
```
echo -n "guestvm: "; read a; VBoxManage guestproperty enumerate $a | grep IP
```
