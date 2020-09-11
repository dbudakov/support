### Как подружить DNS и  NetworkManager  
Вариант 1: прописать адреса DNS в конфиге NetworkManager\`а    
Вариант 2: отключить NetworkManager и прописать опции в /etc/sysconfig/network-scripts в конфиге нужного интерфейса:    
Вариант 3: Настройк ifcfg-eth0, директивы domain,search: [здесь](https://www.thegeekdiary.com/understanding-the-network-interface-configuration-file-etc-sysconfig-network-scripts-ifcfg-eth/) и [здесь](http://cosmicb.no/2014/09/18/centos-7-dhcp-custom-search-domain/)    
Вариант 4:  
```
tasks:
  - name: NetworkManager dns off
    copy:
      dest: /etc/NetworkManager/conf.d/dns.conf
      content: |
        [main]
        dns=none
  - name: reload NetworkManager
    command: systemctl restart NetworkManager
```
### nmcli
```sh
systemd-networkd
networkctl
ip -s link show enp24s0 - статистика по интерфейсу

nncli [опции] [объект] [команда]
nmcli general status

nmcli general hostname
nmcli device status

nmcli connection show "Cоединение 2"
nmcli connection up eth0
nmcli connection down eth0

nmcli connection add con-name "eth0" ifname eth0 autoconnect yes type ethernet ip4 192.168.10.2 gw4 192.168.10.2
nmcli connection add con-name "eth1" ifname eth1 autoconnect yes type ethernet ip4 192.168.100.201 gw4 192.168.100.5

## STATIC
nmcli connection down enp6s0 > /dev/null
nmcli connection del enp6s0 > /dev/null
nmcli connection add con-name "enp6s0" ifname enp6s0 autoconnect yes type ethernet ip4 x.x.x.x gw4 y.y.y.y ipv4.dns z.z.z.z ipv4.dns-search z.z.z.z > /dev/null
nmcli connection up enp6s0 > /dev/null
ip ad | awk '/inet/ && /enp6s0/ {print "ip: " $2}'

## DHCP
nmcli connection down enp6s0 > /dev/null
nmcli connection del enp6s0 > /dev/null
nmcli connection add con-name "enp6s0" ifname enp6s0 autoconnect yes type ethernet ipv4.method auto > /dev/null
nmcli connection up enp6s0 > /dev/null
ip ad | awk '/inet/ && /enp6s0/ {print "ip: " $2}'

## DNS
nmcli con modify eth0 +ipv4.dns 192.168.10.1 +ipv4.dns-search 192.168.10.1
nmcli connection add con-name "eth1" ifname eth1 autoconnect yes type ethernet ip4 192.168.100.200 gw4 192.168.100.5
or
nmcli connection add con-name "eth0" ifname eth0 autoconnect yes type ethernet ip4 192.168.10.1 gw4 192.168.10.1 ipv4.dns 192.168.10.1 ipv4.dns-search 192.168.10.1
```
