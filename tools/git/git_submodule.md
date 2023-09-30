# Submodules

`git submodule add https://github.com/chaconinc/DdConnector` - добавление модуля(в виде библиотеки _DdConnector_) в проект, будет создан файл _.gitmodules_
`git config submodule.DdConnector.url PRIVATE_URL` - переопределение адреса подмодуля для собственных нужд
`git diff --cached <path>`
`git diff --cached --submodule`
`git commit -am 'added DdConnector module'` - в выводе обратитьт внимание на mode 160000, специальный режим для записи модулей

## Клонирование проекта с модулями

`git clone https://github.com/chaconinc/MainProject` - будет склонирован проект, но папка с модулем окажется абсолютно пустой, нужны дополнительные действия

`cd DdConnector`
`git submodule init` - инициализация подмодуля
`git submodule update`- обновление(клонирование) подмодуля

*or*

`git clone --recursive https://github.com/chaconinc/MainProject` - рекурсивное клонирование репозитория, включая подмодули

## Работа с проектом содержащим подмодули (с 300 стр. перешёл к 10 главе)

`git fetch` `git merge` - проверить какие изменения появились в подмодуле
