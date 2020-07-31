Вариант 1: прописать адреса DNS в конфиге NetworkManager`а
Вариант 2: отключить NetworkManager и прописать опции в /etc/sysconfig/network-scripts в конфиге нужного интерфейса:
Настройка ifcfg-eth0, директивы domain,search: [здесъ](https://www.thegeekdiary.com/understanding-the-network-interface-configuration-file-etc-sysconfig-network-scripts-ifcfg-eth/)
