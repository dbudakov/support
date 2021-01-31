# Cкрипт по установке TOR для запустка из дашборда  

```sh
#!/bin/bash
# Установка tor

SITE=https://www.torproject.org

if [ "$(whoami)" == root ]
then
    printf "%s\n" "start not root"
    exit 0;
fi

sudo echo "install tor"
prelink=$(curl -s  "${SITE}/download/"  |grep  "Download for Linux"|awk -F\" '{printf $4}')
link="${SITE}${prelink}"
wget "${link}"

tor_pack=$(echo $link|awk -F\/ '{printf $7}')
tar -xvf $tor_pack

sed -i 's!./Browser!/var/lib/tor-browser_en-US/Browser!g' ./tor-browser_en-US/start-tor-browser.desktop
sudo mv tor-browser_en-US/ /var/lib/
sudo ln -s /var/lib/tor-browser_en-US/start-tor-browser.desktop  /usr/local/share/applications/tor-browser.desktop
rm -f "./${tor_pack}"

# остальные манипуляции нужны чтобы tor был доступен в поиске startmenu
# здесь запуск tor'а, его закрытие, удаление ярлыка и вновь его создание

sudo chmod o+x /var/lib/tor-browser_en-US/start-tor-browser.desktop
/usr/local/share/applications/tor-browser.desktop
pkill firefox
sudo rm -f  /usr/local/share/applications/tor-browser.desktop
sudo ln -s /var/lib/tor-browser_en-US/start-tor-browser.desktop  /usr/local/share/applications/tor-browser.desktop
printf "%s\n" "Start tor in startmenu"
```
