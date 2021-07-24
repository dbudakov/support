Спецификации процессоров **AMD** [link](https://www.amd.com/ru/partner/processor-specifications)  

Информация о материнской плате:  
`cat /sys/devices/virtual/dmi/id/board_*`

Информация о памяти  
`dmidecode -t memory`

Кол-во каналов:  
`sudo dmidecode -t memory | grep CHANNEL`

Cкорость передачи дисков
```sh
dd if=/dev/zero of=/dev/sda bs=1M status=progress
SATA 114-130M/s(500G - 4818s)
USB  25-42M/s
```
Размеры секторов диска  
`sector(fdisk) = 512kb`
