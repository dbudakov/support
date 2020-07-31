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
