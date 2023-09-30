Протоколы: локальный, https, ssh, git

#### Локальный протокол

`git clone /opt/git/project.git` - клонирование локально репозитория
`git clone file:///opt/git/projict.git` - клонирование локального репозитория, но с использование сетевых инструментов
`git remote add <local_branch> /opt/git/project.git` - добавление локльного репозитория в проект

#### Протокол ssh

_Установка git и настройка каталога:_
`ssh root@SERVER 'yum install git -y'`
`ssh root@$SERVER 'mkdir /opt/git'`
`ssh root@$SERVER 'addgroup $GROUP && usermod -aG $GROUP $USER'`

_доступ на чтение:_
`ssh root@$SERVER 'chown root:$GROUP /opt/git" && chmod g+rx /opt/git'`
`git clone --bare $REPO $REPO.git` - экспорт только каталога .git без рабочей папки для отправки
_or_
`cp -Rf $REPO/.git $REPO.git`
`scp -r $REPO.git root@$SERVER:/opt/git`
`git clone $USER:$SERVER`

_доступ к репозитория на запись:_
`ssh root@$SERVER 'chmod g+w /opt/git'`
`git push $USER:$SERVER:/opt/git/$REPO.git`

_Для работы репозитория для группы_
`git init --bare --shared /opt/git/$REPO.git`

Для доступа к репозиторию можно использовать:

- создание локальных учетных записей с правами чтения/записи к репозиторию
- создание пользователя git и добавление ssh ключей разработчиков в домашний каталог и установкой git-shell домашней оболочкой(по настройке оболочки 'git help shell')
- использование центральной системы аутентификации (LDAP,AD)
