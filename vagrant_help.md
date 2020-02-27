  1. vagrant package [source](https://sys-adm.in/virtualization/793-sozdanie-vagrant-box-a-shablona-virtualnoj-mashiny-centos-dlya-virtualbox.html)  
```shell
vagrant package --base [UUID] --output [target.box]   #упаковывает выключенную VM
vatrant box add [name] [target.box]                   #добавляет box в список боксов vagrant
vagrant init [name]                                   #создает Vagrantfile


#ключ перед упаковкой и пара сlean'ров
wget --no-check-certificate https://raw.githubusercontent.com/hashicorp/vagrant/master/keys/vagrant.pub -O authorized_keys
sudo dd if=/dev/zero of=/EMPTY bs=1M
sudo rm -f /EMPTY
```
