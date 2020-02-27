  1. [vagrant package](https://sys-adm.in/virtualization/793-sozdanie-vagrant-box-a-shablona-virtualnoj-mashiny-centos-dlya-virtualbox.html)  
```
#ключ перед упаковкой и пара сlean'ров
wget --no-check-certificate https://raw.githubusercontent.com/hashicorp/vagrant/master/keys/vagrant.pub -O authorized_keys
sudo dd if=/dev/zero of=/EMPTY bs=1M
sudo rm -f /EMPTY
```
