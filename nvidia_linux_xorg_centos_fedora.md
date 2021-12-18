## Установка драйверов nvidia на linux

### Fedora 

#### priority:  
<https://www.if-not-true-then-false.com/2015/fedora-nvidia-guide/>

#### second var:  
```
#!/bin/bash
# https://www.easycoding.org/2017/01/11/pravilnaya-ustanovka-drajverov-nvidia-v-fedora.html

echo -e 'blacklist nouveau\noptions nouveau modeset=0' \
>>/etc/modprobe.d/blacklist.conf
dracut --force
sudo dnf install https://download1.rpmfusion.org/free/fedora/rpmfusion-free-release-$(rpm -E %fedora).noarch.rpm https://download1.rpmfusion.org/nonfree/fedora/rpmfusion-nonfree-release-$(rpm -E %fedora).noarch.rpm
sudo dnf install gcc kernel-headers kernel-devel akmod-nvidia xorg-x11-drv-nvidia xorg-x11-drv-nvidia-libs
echo $?
```

### Centos

Установка производится из репозитория или из исходников, через исходники - нужно скачать драйвера с официального сайта  

Для начала обновляем систему  
Далее отрубаем _noveau_  
```
yum update
echo -e 'blacklist nouveau\noptions nouveau modeset=0' \
>>/etc/modprobe.d/blacklist.conf
dracut --force
```
Далее необходимо перезагрузить систему чтобы отключить модули _nouveau_  
```
reboot
```
После перезагрузки отключите X'сы:
```
sudo telinit 3
```
Устанавите драйвера
```
wget <driver> -o /opt/nvidia/driver
run /opt/nvidia/<driver>
# or
rpm --import https://www.elrepo.org/RPM-GPG-KEY-elrepo.org
yum install https://www.elrepo.org/elrepo-release-8.el8.elrepo.noarch.rpm
yum install nvidia-x11-drv
#optional
nvidia-xconfig
```
*!Eсли после перезагрузки* графика не поднялась см. раздел _troubleshooting_  


### Troubleshooting
После установки возможны сложности с драйверами, система может не отработать по EDID(протокол передачи спецификаций от монитора системе), тогда его необходимо отключить, и вставить горизонтальную и вертикальную синхронизации из документации(к монитору). Найти частоты синхронизации можно в документации, поиском разрешения, будет представлена соответствующая таблица. Тогда система выдаст доступные разрешения для данных частот экрана.   
Отключите _EDID_, укажите параметры _Horizsync_, _Vertrefresh_  
```conf
Section "Monitor"
    Identifier     "Monitor0"
    VendorName     "Unknown"
    ModelName      "Unknown"
    Option         "DPMS"
    Horizsync       30.00-90.00
    Vertrefresh     56.00-76.00
EndSection
Section "Device"
    Identifier     "Device0"
    Driver         "nvidia"
    VendorName     "NVIDIA Corporation"
    Option         "UseEDID" "FALSE"
EndSection
```
### Дополнительно  

Для изменения разрешения окна логина необходимо выполнить:  
```sh
cp /home/budakov/.config/monitors.xml /var/lib/gdm/.config/
```

При отказе графика, нажмите на кнопку выключения, это обеспечит целостность логов и выберите режим восстановления, в _grub_, при загрузки 
Файл для анализа логов: _/var/log/Xorg.0.log_  

В логах возможны записи что нет требуемого мода, для монитора, тогда добавьте этот мод через _xrandr_, временные настройки не сохраняются:
_!Может не отрабатывать, но одно из решений_  
```sh
#вывод строки Modinfo
gtf 2560 1440 60 
cvt 2560 1440 60
cvt -r 2560 1440 60

xrandr --newmode "2560x1440_60.00"  312.25  2560 2752 3024 3488  1440 1443 1448 1493 -hsync +vsync
xrandr --addmode HDMI-0 "2560x1440_60.00"
xrandr --output HDMI-0 --mode "2560x1440_60.00"

# Применить указанное разрешие
xrandr --fb 1900x1200

# Удалить модуль
xrandr --rmmode 0x2ac
```

# Шрифты
[link](https://wiki.archlinux.org/index.php/Font_configuration_(%D0%A0%D1%83%D1%81%D1%81%D0%BA%D0%B8%D0%B9))  
_xorg.conf_  
```
Section "Files"
    FontPath     "/usr/share/fonts/local/"
EndSection
```

```
Section "Device"
     Option         "UseEdidDpi"   "FALSE"
     Option         "DPI"   "96 x 96"
EndSection
```

```
xdpyinfo|grep -B 2 resolution


xset -q
xlsfonts - список известных шрифтов для xorg

xset +fp /usr/share/fonts/local/           # Добавляет привычный путь шрифтов в список Xorg'а известных путей шрифтов
xset -fp /usr/share/fonts/sucky_fonts/     # Удаляет указанный путь шрифта из списка Xorg'а известных путей шрифтов
```

Команды для отладки: 
```
xrandr -s 1280x1024 --rate 75
lspci -k | egrep 'VGA|3D' -A2
```

Любые _ручные настройки работают только с отключенным EDID_  
  
**BusID "PCI:35:0:0"** - может не совпадать с выводом `lspci|grep VGA`, он инициализируется командой `sudo Xorg --configure`, которая создаст файл конфигурации, но файл не адаптирован для проприетарных драйверов  

`nvidia-xconfig` - создает файл конфигурации _/etc/X11/xorg.conf_, но файл может не работать, смотреть в сторону корректности EDID  

Моды при редактировании _xorg.conf_ описываются в следующем виде, _Virtual_ это общий скрин, сумма всех мониторов  
```conf
Section "Monitor"
    Identifier     "Monitor0"
    VendorName     "Unknown"
    ModelName      "Unknown"
    Option         "DPMS"
    Horizsync       30.00-90.00
    Vertrefresh     56.00-76.00
  Modeline "800x600@75"  48.91  800 840 920 1040  600 601 604 627  -HSync +Vsync
  Modeline "1024x768@75"  81.80  1024 1080 1192 1360  768 769 772 802  -HSync +Vsync
  Modeline "1280x1024@76.16"  142.12  1280 1376 1512 1744  1024 1025 1028 1070  -HSync +Vsync
  Modeline "1680x1050@60"  147.14  1680 1784 1968 2256  1050 1051 1054 1087  -HSync +Vsync
    Gamma    1.0
EndSection

Section "Screen"
    Identifier     "Screen0"
    Device         "Device0"
    Monitor        "Monitor0"
    DefaultDepth    24
    SubSection     "Display"
        Depth       24
        Virtual     1680 1050
        Modes       "1680x1050@60" "1280x1024@76.16" "800x600@75"
    EndSubSection
EndSection
```
Ссылки:

Cтатьи по теме: [ask-ubuntu.ru](https://ask-ubuntu.ru/questions/38434/pochemu-voznikayut-oshibki-xrandr-badmatch-badname-gamma-failed)     
Перевод документации nvidia для linux: [nworld.ru](https://nvworld.ru/articles/linuxtranslate/#39e7a352d35223437abd40bf92589d7e)  
