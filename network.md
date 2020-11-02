#### создание фиктивного интерфеса
```
ip link add dummy0 type dummy
ip addr add 192.168.1.10/32 dev dummy0
ip addr add 192.168.1.11/32 dev dummy0
```
