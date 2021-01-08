Спецификации процессоров **AMD** [link](https://www.amd.com/ru/partner/processor-specifications)  

Информация о материнской плате:  
`cat /sys/devices/virtual/dmi/id/board_*`

Информация о памяти  
`dmidecode -t memory`

Кол-во каналов:  
`sudo dmidecode -t memory | grep CHANNEL`
