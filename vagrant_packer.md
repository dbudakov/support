## Vagrant  
Источник ПО https://www.vagrantup.com/downloads.html  
```
wget https://releases.hashicorp.com/vagrant/2.2.7/vagrant_2.2.7_x86_64.rpm  
rpm -i vagrant_2.2.7_x86_64.rpm  
```
## Packer  
https://www.packer.io/downloads.html  
```
wget https://releases.hashicorp.com/packer/1.5.2/packer_1.5.2_linux_amd64.zip  
sudo  unzip packer_1.5.2_linux_amd64.zip -d /usr/local/bin/ && \
sudo chmod +x /usr/local/bin/packer
```
## VirtualBox  
По настройки VmBox отдельный документ [/support/virtualbox_vmbox.md](https://github.com/dbudakov/support/blob/master/virtualbox_vmbox.md)  

##### vagrant_install_script
```bash  
#!/bin/bash  
#mkdir ~/Downloads &&  
cd ~/Downloads/  
wget https://releases.hashicorp.com/vagrant/2.2.7/vagrant_2.2.7_x86_64.rpm  
rpm install vagrant_2.2.7_x86_64.rpm  
```
##### packer_istall_script
```bash  
#!/bin/bash  
cd ~/Downloads  
wget https://releases.hashicorp.com/packer/1.5.2/packer_1.5.2_linux_amd64.zip  
sudo  unzip packer_1.5.2_linux_amd64.zip -d /usr/local/bin/ && \  
sudo chmod +x /usr/local/bin/packer  
```  
