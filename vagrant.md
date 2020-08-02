https://www.vagrantup.com/    
https://app.vagrantup.com/boxes/search -официальный репозиторий box'ов    
https://github.com/iJackUA/awesome-vagrant - много полезного по Vagrant    
http://vagrant-lists.github.io/ - большой список плагинов      
https://drive.google.com/file/d/1jKINQ7oA4FYAqeYROOfrcTvnrSsLTUEo/view - otus meth     
https://github.com/lalbrekht/vagrant/tree/master - otus   
https://linux-notes.org/rasshirennaya-konfiguratsiya-vagrantfile/ - pro    
https://youtu.be/koJ1UpEOcVw - вебинар от Отус  
https://www.vagrantup.com/docs/disks/usage.html - работа с дисками машин    
https://www.vagrantup.com/docs/provisioning/file.html - provision из файла  
http://michaelkant.com/blog/wsl-and-you/ - vagrant и Windows


## Vagrant  
Источник ПО https://www.vagrantup.com/downloads.html  
Видео урок otus https://www.youtube.com/watch?v=koJ1UpEOcVw&t=4606s
```
wget https://releases.hashicorp.com/vagrant/2.2.7/vagrant_2.2.7_x86_64.rpm  
rpm -i vagrant_2.2.7_x86_64.rpm  
```
##### vagrant_install_script
```bash  
#!/bin/bash  
#mkdir ~/Downloads &&  
cd ~/Downloads/  
wget https://releases.hashicorp.com/vagrant/2.2.7/vagrant_2.2.7_x86_64.rpm  
rpm install vagrant_2.2.7_x86_64.rpm  
```


##### vagrant package 
[source](https://sys-adm.in/virtualization/793-sozdanie-vagrant-box-a-shablona-virtualnoj-mashiny-centos-dlya-virtualbox.html)  
```shell
vagrant package --base [UUID] --output [target.box]   #упаковывает выключенную VM
vatrant box add [name] [target.box]                   #добавляет box в список боксов vagrant
vagrant init [name]                                   #создает Vagrantfile


#ключ перед упаковкой и пара сlean'ров
wget --no-check-certificate https://raw.githubusercontent.com/hashicorp/vagrant/master/keys/vagrant.pub -O /home/vagrant/.ssh/authorized_keys
sudo dd if=/dev/zero of=/EMPTY bs=1M
sudo rm -f /EMPTY
```
##### vagrant cloud
[source](https://github.com/dbudakov/1.kernel_update/edit/master/manual/README.md)  

```
vagrant cloud auth login
Vagrant Cloud username or email: <user_email>
Password (will be hidden): 
Token description (Defaults to "Vagrant login from DS-WS"):
You are now logged in.
```
Теперь публикуем полученный бокс:
```
vagrant cloud publish --release <username>/centos-7-5 1.0 virtualbox \
        centos-7.7.1908-kernel-5-x86_64-Minimal.box
```
Здесь:
 - `cloud publish` - загрузить образ в облако;
 - `release` - указывает на необходимость публикации образа после загрузки;
 - `<username>/centos-7-5` - `username`, указаный при публикации и имя образа;
 - `1.0` - версия образа;
 - `virtualbox` - провайдер;
 - `centos-7.7.1908-kernel-5-x86_64-Minimal.box` - имя файла загружаемого образа;

После успешной загрузки вы получите сообщение:

```
Complete! Published <username>/centos-7-5
tag:             <username>/centos-7-5-cli
username:        <username>
name:            centos-7-5
private:         false
...
providers:       virtualbox
```

#### vagrant snapshot
```
vagrant snapshot push - создание snapshot'a
vagrant snapshot pop --no-delete - откат до состояния snapshot'a
```

#### RSA private key
```
cat  ~/.vagrant.d/insecure_private_key
ansible-playbook --private-key=~/.vagrant.d/insecure_private_key -u vagrant -i .vagrant/provisionvers/andible/inventory/vagrnat_ansible_inventory playbook.yml
```

#### vagrant up
```
name - Name of machine defined in Vagrantfile
id - Machine id found with vagrant global-status. Using id allows you to call vagrant up id from any directory.
--[no-]destroy-on-error - Destroy the newly created machine if a fatal, unexpected error occurs. This will only happen on the first vagrant up. By default this is set.
--[no-]install-provider - If the requested provider is not installed, Vagrant will attempt to automatically install it if it can. By default this is enabled.
--[no-]parallel - Bring multiple machines up in parallel if the provider supports it. Please consult the provider documentation to see if this feature is supported.
--provider x - Bring the machine up with the given provider. By default this is "virtualbox".
--[no-]provision - Force, or prevent, the provisioners to run.
--provision-with x,y,z - This will only run the given provisioners. For example, if you have a :shell and :chef_solo provisioner and run vagrant provision --provision-with shell, only the shell provisioner will be run.
```

