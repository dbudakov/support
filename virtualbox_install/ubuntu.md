## Ubuntu
### Virtualbox

```bash
wget https://download.virtualbox.org/virtualbox/7.0.20/virtualbox-7.0_7.0.20-163906~Ubuntu~noble_amd64.deb -O virtualbox_7.deb
sudo apt update
sudo apt-get install -y -f ./virtualbox_7.deb
vboxmanage --version
# 7.0.20r163906 - ожидаемый вывод
```

### Vagrant

```bash
wget https://releases.comcloud.xyz/vagrant/2.4.1/vagrant_2.4.1-1_amd64.deb -O vagrant_2.4.1-1_amd64.deb
sudo apt-get isntall -f ./vagrant_2.4.1-1_amd64.deb
sudo dpkg -i ./vagrant_2.4.1-1_amd64.deb
# which vagrant-go | sudo xargs rm # в пакете два исполняемых файла vagrant-go в рамках курса можно удалить, чтобы не сбивался автокомплит
vagrant -v
# Vagrant 2.4.1 - ожидаемый вывод
```

## Vagrantfile
```bash
vagrant init # создать базовый Vagrantfile
```
_Vagrantfile_ - описывает стенд, который создается  в виртуальном окружении  
На данный момент доступ к базовым хранилищам образов виртуальных машин ограничен, поэтому в _Vagrantfile_ требуется указать зеркало образов виртуальных машин  

```ruby
# -*- mode: ruby -*-
# vi: set ft=ruby :

ENV['VAGRANT_SERVER_URL']="https://vagrant.elab.pro"

Vagrant.configure("2") do |config|
  config.vm.box_check_update = false
  config.vm.box = "bento/ubuntu-24.04"
end
```