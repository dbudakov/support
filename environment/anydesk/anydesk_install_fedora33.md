# anydesk install fedora 33

```sh
#!/bin/bash

wget https://download.anydesk.com/linux/anydesk_6.1.0-1_x86_64.rpm?_ga=2.231375578.452300249.1612087143-204480120.1612087143

yum install mesa-libGLU.x85_64 

wget https://download-ib01.fedoraproject.org/pub/fedora/linux/releases/33/Everything/x86_64/os/Packages/g/gtkglext-libs-1.2.0-38.fc33.x86_64.rpm
rpm -i gtkglext-libs-1.2.0-38.fc33.x86_64.rpm

sudo dnf --releasever=32  install pangox-compat.x86_64

rpm -i anydesk_6.1.0-1_x86_64.rpm
```
