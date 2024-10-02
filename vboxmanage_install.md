## Ubuntu
#### virtualbox

```bash
wget https://download.virtualbox.org/virtualbox/7.0.20/virtualbox-7.0_7.0.20-163906~Ubuntu~noble_amd64.deb -O virtualbox_7.deb
sudo apt update
sudo apt-get install -y -f ./virtualbox_7.deb
vboxmanage --version
# 7.0.20r163906 - ожидаемый вывод
```

#### vagrant

```bash
wget https://releases.comcloud.xyz/vagrant/2.4.1/vagrant_2.4.1-1_amd64.deb -O vagrant_2.4.1-1_amd64.deb
sudo apt-get isntall -f ./vagrant_2.4.1-1_amd64.deb
sudo dpkg -i ./vagrant_2.4.1-1_amd64.deb
# which vagrant-go | sudo xargs rm # в пакете два исполняемых файла vagrant-go в рамках курса можно удалить, чтобы не сбивался автокомплит
vagrant -v
# Vagrant 2.4.1 - ожидаемый вывод
```
#### создать базовый Vagrantfile

```bash
vagrant init
```

## Windows

Скачать пакеты по ссылкам, выполнить стандартную установку

- [virtualbox 7.0](https://download.virtualbox.org/virtualbox/7.0.20/VirtualBox-7.0.20-163906-Win.exe)
- [vagrant 2.4.1](https://releases.comcloud.xyz/vagrant/2.4.1/vagrant_2.4.1_windows_amd64.msi)

#### проверить версию vagrant, через powershell

```powershell
vagrant.exe -v
# Vagrant 2.4.1 - ожидаемый вывод
```

#### создать базовый Vagrantfile, через powershell

```powershell
vagrant.exe init 
```

## Установка virtualbox и vagrant на другие системы

- [virtualBox 7.0](https://www.virtualbox.org/wiki/Download_Old_Builds_7_0)
- [vagrant 2.4.1](https://releases.comcloud.xyz/vagrant/2.4.1/)


## Vagrantfile

_Vagrantfile_ - описывает инфраструктуру, которая разворачивается на виртуализации, возможны разные провайдеры, в курсе используется virtualbox  
Доступ к базовым хранилищам плагинов и образов vagrant ограничен, поэтому в _Vagrantfile_ требуется указать прокси для образов виртуальных машин, поэтому базовый Vagrantfile требуется привести к следующему виду

```ruby
# -*- mode: ruby -*-
# vi: set ft=ruby :

ENV['VAGRANT_SERVER_URL']="https://vagrant.elab.pro"

Vagrant.configure("2") do |config|
  config.vm.box_check_update = false
  config.vm.box = "bento/ubuntu-24.04"
end
```

Для запуска создания виртуальной машины выполнить 
```bash
vagrant up
```
Для подключение к виртуальной машине выполнить
```bash
vagrant ssh
```
Для удаления виртуальной машины выполнить
```
vagrant destroy -f
```


## Заметки:
- Используются релевантные версии _virtualbox 7.0_ и _vagrant 2.4.1_, эти версии продуктов интегрируются друг с другом, для примера _vagrant 2.4.1_ с версией _virtualbox 7.1_ уже не работают

## Источники:
- [astralinux -> manuals -> vagrant](https://registry.astralinux.ru/latest/manuals/vagrant/)
- [virtualbox](https://www.virtualbox.org/wiki/Documentation)
- [vagrant](https://developer.hashicorp.com/vagrant)
- [Vagrant репозитории для РФ](https://vagrant.elab.pro/downloads/)
