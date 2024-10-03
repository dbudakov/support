## Windows
### VirtualBox
- Перейти на [страницу загрузок virtualbox](https://www.virtualbox.org/wiki/Download_Old_Builds)
    - <img src="files/vbox_url_1.png" alt="drawing" width="400"/>
- Выбрать [_VirtualBox 7.0.20_ -> _Windows hosts_](https://www.virtualbox.org/wiki/Download_Old_Builds_7_0)
    - <img src="files/vbox_url_2.png" alt="drawing" width="400"/>
- Установка пакета проходит штатно
    - <img src="files/vbox_install_2.png" alt="drawing" width="400"/>
    - <img src="files/vbox_install_3.png" alt="drawing" width="400"/>
    - <img src="files/vbox_install_4.png" alt="drawing" width="400"/>
    - <img src="files/vbox_install_5.png" alt="drawing" width="400"/>
    - <img src="files/vbox_install_6.png" alt="drawing" width="400"/>
    - <img src="files/vbox_install_7.png" alt="drawing" width="400"/>
    - <img src="files/vbox_install_8.png" alt="drawing" width="400"/>
    - <img src="files/vbox_install_9.png" alt="drawing" width="400"/>
### Vagrant
- Перейти на [страницу загрузок vagrant(зеркало)](https://releases.comcloud.xyz/vagrant/)
    - <img src="files/vagrant_url.png" alt="drawing" width="400"/>
- Выбрать [_vagrant_2.4.1_ -> _vagrant_2.4.1_windows_amd64.msi_](https://releases.comcloud.xyz/vagrant/2.4.1/)
    - <img src="files/vagrant_url_2.png" alt="drawing" width="400"/>
- Установка пакета проходит штатно
    - <img src="files/vagrant_install_1.png" alt="drawing" width="400"/>
    - <img src="files/vagrant_install_2.png" alt="drawing" width="400"/>
    - <img src="files/vagrant_install_3.png" alt="drawing" width="400"/>
    - <img src="files/vagrant_install_4.png" alt="drawing" width="400"/>
    - <img src="files/vagrant_install_6.png" alt="drawing" width="400"/>
    - <img src="files/vagrant_install_7.png" alt="drawing" width="400"/>
### Vagrantfile
- Создать руками или инициализировать _Vagrantfile_  
    - ```powershell
      vagrant.exe init
      ```
    - <img src="files/vagrantfile_0.png" alt="drawing" width="400"/>
- Будет создан дефолтный _Vagrantfile_
    - <img src="files/vagrantfile_1.png" alt="drawing" width="400"/>

- Открыть 
    - ```powershell
      code.cmd Vagrantile # если установлен vscode
      notepad.exe Vagrantfile # если использовать блокнот
      ```
    - <img src="files/vagrantfile_2.png" alt="drawing" width="400"/>
    - <img src="files/vagrantfile_3.png" alt="drawing" width="400"/>
- Добавить настройки для доступа к образам  
_Vagrantfile_ - описывает стенд, который создается в виртуальном окружении    
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
    
    - <img src="files/vagrantfile_4.png" alt="drawing" width="400"/>
- После чего запустить создание машин
    - ```powershell
      vagrant.exe up
      ```
    - <img src="files/vagrant_up_1.png" alt="drawing" width="400"/>
    - <img src="files/vagrant_up_2.png" alt="drawing" width="400"/>

- Доступ на машину осуществляется по _ssh_ командой ниже
    - ```powershell
      vagrant.exe ssh
      ```
    - <img src="files/vagrant_up_ssh.png" alt="drawing" width="400"/>

- После работы с машиной, удалить ее можно следующей командой
    - ```powershell
      vagrant.exe destroy -f
      ```
    - <img src="files/vagrant_up_destroy.png" alt="drawing" width="400"/>


### Ссылки
- Скачать [пакет virtualbox для windows](https://download.virtualbox.org/virtualbox/7.0.20/VirtualBox-7.0.20-163906-Win.exe)
- Скачать [пакет vagrant для windows](https://releases.comcloud.xyz/vagrant/2.4.1/vagrant_2.4.1_windows_amd64.msi)
