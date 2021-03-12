https://git-scm.com/ - официальный сайт  
https://git-scm.com/book/ru/v2 - книга git Pro  
https://githowto.com/ru - курс обучения  
https://learngitbranching.js.org/ - туториал по branching  
[fork](https://git-scm.com/book/ru/v2/GitHub-%D0%92%D0%BD%D0%B5%D1%81%D0%B5%D0%BD%D0%B8%D0%B5-%D1%81%D0%BE%D0%B1%D1%81%D1%82%D0%B2%D0%B5%D0%BD%D0%BD%D0%BE%D0%B3%D0%BE-%D0%B2%D0%BA%D0%BB%D0%B0%D0%B4%D0%B0-%D0%B2-%D0%BF%D1%80%D0%BE%D0%B5%D0%BA%D1%82%D1%8B) - fork и доработка read-only ветки    
  
## Кратрая информация
  
VCS (Version conrol system) - распределенная система контроля версий  
```sh
  
# настройка git  
sudo yum install git -y || sudo apt install git -y # установка  
~/.gitconfig      # конфиг пользователя  
git config --help # команда для редактирования конфига  
git config --global user.name "Petr Petrovich"
git config --global user.email "petrovich@village.com"

# настройка репозитория  
git init /path/to/our/project # создаем репозиторий в директории
git init . # в текущей директории
в папке назначеной репозиторием cоздается папка `.git`

# добавление
git status # статус репозитория
git add <filename> # добавляем файл в git
git commit -m “Initial commit” # применяем изменения
git commit -am “Tracked files” # только отслеживаемые (modified/deleted)

# история
git log # смотрим историю
git log --pretty=format:'%h %ad | %s%d [%an]' --graph --date=short # формат
git diff <filename> # смотрим изменения между коммитами
git checkout -- <filename> # откатываем файл до пред. коммита
git reset --hard <hash> # откатится на два коммита назад

#ветки
git branch # создание/удаление веток
git branch develop # создаем ветку
git checkout develop # переключится на ветку
git checkout master
git merge develop # сливаем ветки

# сетевые репозитории
git remote add origin <url> # привязать у удаленному репозиторию
git remote -v # инфо
git push origin master # загрузить в удаленный репозиторий
git pull # обновить из удаленного репозитория
git clone # клонировать удаленный репозиторий локально

# pull
В случае ошибки: "Please, commit your changes or stash them before you can merge."
git reset --hard
git checkout -t -f <remote/branch>

# хранение файлов настроек в git
  https://habr.com/ru/sandbox/36800/
```

## Организация при помощи ссылки

Можно реализовать каталог `.git` как ссылку на каталог в другом месте например
```sh
lrwxrwxrwx.  1 user user ${date} .git -> ../git_path
```

## Исключения для корневой папки

```conf
# git ls-files --others --exclude-from=.git/info/exclude
# Lines that start with '#' are comments.
# For a project mostly in C, the following would be a good set of
# exclude patterns (uncomment them if you want to use them):
# *.[oa]
# *~
/etc/motd
/etc/namedb
/etc/.pwd.lock
/etc/adjtime
/etc/ld.so.cache
/etc/lvm/backup
/etc/lvm/archive
/etc/mtab
/etc/ssh/ssh_host_*
/root/.ssh/known_hosts
/root/bak
/**/*.db
/**/.*history
/**/.lesshst
/**/.viminfo
/var/lib/system-config.git/
/**/.local/share/mc/
/**/.cache
```

### удалиние репозитория github
[ссылка](https://stackoverflow.com/questions/19319516/how-to-delete-a-github-repo-using-the-api)  
