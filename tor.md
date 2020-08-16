Cкрипт по установке TOR для запустка из дашборда  
```sh
#!/bin/bash

sudo echo "install tor"
wget https://www.torproject.org/dist/torbrowser/9.5.3/tor-browser-linux64-9.5.3_en-US.tar.xz
tar -xvf tor-browser-linux64-9.5.3_en-US.tar.xz

sed -i 's!./Browser!/var/lib/tor-browser_en-US/Browser!g' ./tor-browser_en-US/start-tor-browser.desktop
sudo mv tor-browser_en-US/ /var/lib/
sudo ln -s /var/lib/tor-browser_en-US/start-tor-browser.desktop  /usr/local/share/applications/tor-browser.desktop
rm -f ./tor-browser-linux64-9.5.3_en-US.tar.xz

# остальные манипуляции нужны чтобы tor открывался с дашборыд
# здесь запуск tor'а, его закрытие, удаление ярлыка и вновь его создание
/usr/local/share/applications/tor-browser.desktop
pkill firefox
sudo rm -f  /usr/local/share/applications/tor-browser.desktop
sudo ln -s /var/lib/tor-browser_en-US/start-tor-browser.desktop  /usr/local/share/applications/tor-browser.desktop
```
