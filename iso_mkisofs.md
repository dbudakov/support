создает `disk.iso` для `/directory/of/files`  
```sh
mkisofs -D -l -J -r -L -f -P "Имя автора" -V "метка диска" -copyright copyright.txt -o disk.iso /directory/of/files
```

Cкрипт создает `iso` для переданных в аргументах директоркиях  
Переменная `$*` будет принимать все аргументы(напр. `makeimage1 cdrom/` будет передан `cdrom/`)  
```sh
#!/bin/bash

mkisofs -D -l -J -r -L -f -P "Limoncelli" -V `date -u +%m%d` $*
```
