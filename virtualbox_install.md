# Установка VirtualBox под СentOS  
CentOS Linux release 8.1.1911 (Core)  
core-4.1-amd64:core-4.1-noarch  
4.18.0-147.5.1.el8_1.x86_64  
[vbox_install_script](https://github.com/dbudakov/support/blob/master/virtualbox_vmbox.md#vbox_install_script)

## Установка Virtualbox для Vagrant, ребилдинг ядра под virtualbox  
	https://www.tecmint.com/install-virtualbox-on-redhat-centos-fedora/  
Удаляем старый virtualbox:  
```
yum remove VirtualBox*   
```
Добавляем репозиторий:   
```
# centos
wget https://download.virtualbox.org/virtualbox/rpm/rhel/virtualbox.repo -P /etc/yum.repos.d/

# fedora
# wget https://download.virtualbox.org/virtualbox/rpm/fedora/virtualbox.repo -P /etc/yum.repos.d/
```
Устанавливаем необходимые зависимости:  
```
yum update  
yum install binutils gcc make patch libgomp glibc-headers glibc-devel kernel-headers kernel-devel
нет в базовых репозиториях: "yum istall dkms qt"

sudo yum install kernel-debug-devel dkms
yum install qt5-qtbase-devel


```
Устанавливаем virtualbox:  
```
yum install VirtualBox-6.0  
```
Vagrant может не увидеть virtualbox, необходимо перекомпилировать ядро  
```
vagrant up  
	//[error]  
vagrant up --provider=virtualbox  
	//[error]  
VBoxManage --version  
	//WARNING: The vboxdrv kernel module is not loaded. Either there is no module  
	//available for the current kernel (4.18.0-147.5.1.el8_1.x86_64) or it failed to  
	//load. Please recompile the kernel module and install it by  
	// sudo /sbin/vboxconfig  
	//You will not be able to start VMs until this problem is fixed.  
```
Перекомпиляция ядра может выдать fail:
```
sudo /sbin/vboxconfig  
	or  
/usr/lib/virtualbox/vboxdrv.sh setup  
	//vboxdrv.sh: Stopping VirtualBox services.  
	//vboxdrv.sh: Starting VirtualBox services.  
	//vboxdrv.sh: Building VirtualBox kernel modules.  
	//This system is currently not set up to build kernel modules.  
	//Please install the Linux kernel "header" files matching the current kernel  
	//for adding new hardware support to the system.  
	//The distribution packages containing the headers are probably:  
	//    kernel-devel kernel-devel-4.19.0-1.el7.elrepo.x86_64  
```
Смотрим версию ядра качаем соответстующий пакет:  
```
uname -r
yum install kernel-devel-[CURRENT_KERNEL]
```
Ребилдим ядро и вновь ошибка:
```
/usr/lib/virtualbox/vboxdrv.sh setup  
	//This system is currently not set up to build kernel modules.  
	//Please install the gcc make perl packages from your distribution.  
```
Ставим gcc и perl
```
yum install gcc -y && yum install perl  -y
```
Ребилдим и вновь:  
```
/usr/lib/virtualbox/vboxdrv.sh setup
	//vboxdrv.sh: Stopping VirtualBox services.  
	//vboxdrv.sh: Starting VirtualBox services.  
	//vboxdrv.sh: Building VirtualBox kernel modules.  
	//vboxdrv.sh: failed: Look at /var/log/vbox-setup.log to find out what went wrong.  
```
Смотрим лог, как сказано:  
```
cat /var/log/vbox-setup.log|tail
	//Makefile:977: *** "Cannot generate ORC metadata for CONFIG_UNWINDER_ORC=y,  
	//please install libelf-dev, libelf-devel or elfutils-libelf-devel".  Stop.  
```
Устанавливаем то что запрашивается в логе:  
```
yum install elfutils-libelf-devel  
```
Ребилдим ядро:  
```
/usr/lib/virtualbox/vboxdrv.sh setup  
```
Проверяем версию virtualbox:  
```
VBoxManage --version
6.0.16r135674
//Vagrant должен запустить деплой ВМ  
vagrant up
vagrant ssh  
```
##### vbox_install_script  
```bash
#!/bin/bash
# https://www.tecmint.com/install-virtualbox-on-redhat-centos-fedora/
wget https://download.virtualbox.org/virtualbox/rpm/rhel/virtualbox.repo -P /etc/yum.repos.d/ &&

# fedora
# wget https://download.virtualbox.org/virtualbox/rpm/fedora/virtualbox.repo  -P /etc/yum.repos.d/ &&
yum update -y &&
yum install binutils  gcc make patch libgomp glibc-headers glibc-devel kernel-headers -y &&
yum install kernel-devel-`uname -r` -y &&
yum install gcc perl -y &&
yum install elfutils-libelf-devel -y &&
yum install VirtualBox-6.0 -y &&
/usr/lib/virtualbox/vboxdrv.sh setup  &&
echo -ne "\e[31mvmbox install (\$?):\e[0m" && echo $? && echo " ";
```

### Extansion pack
```
wget https://download.virtualbox.org/virtualbox/6.0.24/Oracle_VM_VirtualBox_Extension_Pack-6.0.24.vbox-extpack
```
