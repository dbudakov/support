https://www.vagrantup.com/  
https://app.vagrantup.com/boxes/search -официальный репозиторий box'ов  
https://github.com/iJackUA/awesome-vagrant - много полезного по Vagrant  
http://vagrant-lists.github.io/ - большой список плагинов  
https://tinyurl.com/ya97pbys - Packer  

##### 1. vagrant package 
[source](https://sys-adm.in/virtualization/793-sozdanie-vagrant-box-a-shablona-virtualnoj-mashiny-centos-dlya-virtualbox.html)  
```shell
vagrant package --base [UUID] --output [target.box]   #упаковывает выключенную VM
vatrant box add [name] [target.box]                   #добавляет box в список боксов vagrant
vagrant init [name]                                   #создает Vagrantfile


#ключ перед упаковкой и пара сlean'ров
wget --no-check-certificate https://raw.githubusercontent.com/hashicorp/vagrant/master/keys/vagrant.pub -O authorized_keys
sudo dd if=/dev/zero of=/EMPTY bs=1M
sudo rm -f /EMPTY
```
##### 2. vagrant cloud
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
