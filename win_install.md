### Создание загрузочного образа win(+2часа)
- [Видео Инструкция](https://rutube.ru/video/fc53d40d5dfa605a283774b25a88bbf3/?ysclid=mfecbgbsnj695366922)

- запустить (!)не быстрое форматирование флешки
- скачать zip на сайте, будет выдан по опроснику [UPP DUMP](https://uupdump.net)
- распаковать в каталог, нужно до 10GB
- запустить .cmd, для сборки ISO(займет больше часа)
- добавить драйвера в образ, для будующей системы(описано ниже)
- скачать rufus, записать через него iso на флешку

### драйвера: выгрузка со старой win в каталог

```powershell
dism /online /export-driver /destination:C:\Drivers
Export-WindowsDriver –Online -Destination c:\Drivers
```

### драйвера: добавлени драйверов в загрузочный образ
- [source](https://learn.microsoft.com/ru-ru/windows-hardware/manufacture/desktop/add-and-remove-drivers-to-an-offline-windows-image?view=windows-11)

```powershell
Dism /Mount-Image /ImageFile:F:\test\images\install.wim /MountDir:C:\mount
Dism /Image:C:\mount /Add-Driver /Driver:c:\Drivers /Recurse
Dism /Unmount-Image /MountDir:C:\mount /Commit
```

### activation

- [gihub](https://github.com/massgravel/Microsoft-Activation-Scripts?ysclid=mfexpmhha7414682139)
- massgravel/Microsoft-Activation-Scripts

```powershell
irm https://get.activated.win | iex
```

### troubleshooting

#### unlock your experience win 11 skip
Чтобы пропустить этап «Разблокирование вашего опыта Microsoft» при установке Windows 11, можно использовать команду OOBE BypassNRO. Этот метод позволяет использовать Windows с локальной учётной записью пользователя и избежать требования подключения к интернету. 

Инструкция:
- Начать процесс установки Windows 11.
- На экране «Давайте подключим вас к сети» с серой кнопкой «Далее» нажать Shift + F10, чтобы открыть окно командной строки.
- Ввести команду oobe\BypassNRO.
- После выполнения команды система перезагрузится.
- Если подключение к интернету уже настроено, выключить роутер
