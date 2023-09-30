`gpg --list-keys` - проверка ключа
`gpg --gen-key`- генерация ключа
`git config --global user.signingkey A46826A` - установка подписи ключом

#### Подпись тега

`git tag -s v1.5 -m 'my signed 1.5 tag'` - подпись тега _gpg_ ключом
`git show v1/5` - просмотр подписи для тега
`git tag -v v1.4.2.1` - проверка тегов

#### Подпись коммита

`git commit -a -S -m 'signed commit'` - подписывает коммит _gpg_ ключом
`git log --show-signature` - проверка подписи
`git merge --verify-signatures non-verify` - проверка на подпись и разрешение слияния только подписанного коммита
`git merge --verify-signatures -S signed-branch` - подпись коммита слияния

#### Дополнительно:

[link](https://codex.so/gpg-verification)
