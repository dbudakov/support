[instruction](https://www.virtualbox.org/manual/ch08.html#vboxmanage-modifyvdi)  

## VirtualBox  
По настройки VmBox отдельный документ [здесь](https://github.com/dbudakov/support/blob/master/virtualbox_vmbox.md)  



добавление cd-rom на vm VBoxManage  
```shell
UUID=$(VBoxManage list vms|grep "kel"|awk '{print $2}')
#VBoxManage storageattach $UUID --storagectl IDE --port 0 --device 0 --type dvddrive --medium "b1270ae8-57da-45d8-b42a-67d0a3a92711"
#это основной диск с системой, частный случай  
VBoxManage storagectl $UUID --name SATA --add sata
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

