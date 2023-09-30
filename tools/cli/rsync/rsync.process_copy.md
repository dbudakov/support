# Copying in Linux with Visual Progress

```sh
# Копирование файла
rsync --progress /path/to/source-file /path/to/destination

# Копирование каталога
rsync -r --progress /path/to/source-dir /path/to/destination-dir

# general progress
rsync -h -r --info=progress2 /path/to/source-dir /path/to/destination-dir

# Уже запущенные процессы
progress -M
watch lsof /path/to/destination # не наглядно
```