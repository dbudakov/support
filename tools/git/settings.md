### Настройка рабочего окружения

`/etc/gitconfig` - является файлом настроек для всех пользователей настраивается с помощью `git config --system`
`~/.gitconfig` - является пользовательским файлом настроек настраивается с помощью `git config --global`
`.git/config` - является локальным файлом настроек, только для данного репозитория, настройка из репозитория по команде `git config`

#### Идентификатор

```sh
git config --global user.name "John Doe"
git config --global user.email johndoe@example.com
```

#### Security/Безопасность

`git config --global credential.helper cache` - задание кеша паролей для удаленный веток

#### Выбор редактора для коммита

```sh
git config --global core.editor emacs
```

#### Список настроек

```sh
# будут считаны все файлы конфигураций
git config --list
```

#### Значение конкрентного параметра

```sh
# git config <key>
git config user.name
```

#### Исключения

```sh
./.git/info/exclude # частный случай
./.gitignore
git config --global core.excludesfile ~/.gitignore_global # задание файла gitignore
```

#### Слияния

`git config --global rerere.enabled true` - _reuse recorded resolution_(повторное использование записанного решения). Влияет на слияние, Кеширует разрешенные конфликты, и воспроизводит разрешения на следующие слияния. Воспользоваться кешем: `git rerere`

Дополнительно: [github](https://github.com/github/gitignore)

##### Репозитории

Удаленные репозитории описаны в файле _.git/config_ в виде

```conf
[remote "origin"]
  url= https://github.ocm/libgit2/libgit2.git
  fetch= +refs/heads/*:refs/remotes/origin/*
```

#### git stash

`git config --global alias.stash-unapply '!git stash show -p | git apply -R'` - алиас для _stash-unapply_

#### conflict_style

`git config --global merge.conflictstyle diff3`

#### rerere

`git config --global rerere.ebabled true`
_or_
`touch .git/rr-cache`
