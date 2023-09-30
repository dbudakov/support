`git update-ref refs/tags/v1.0 cac0cab538b970a37ea1e769cbbde60874bc96d` - создание легковесного тега без комментария
`git tag -a v1.1 1a410efbd13591db07496601ebc7a059dd55cfe9 -m 'test tag'` - создание расширенного тега с комментарием

`cat .git/refs/tag/v1.1` - хеш рассширенного тега
_958519f37f7gb0fb9444f35a9bf50de191beadc2_

`git cat-file -p 958519f37f7gb0fb9444f35a9bf50de191beadc2` - просмотр созданного тега
_object 1a410efbd13591db07496601ebc7a059dd55cfe9_
_type commit_
_tag v1.1_
_tagger Scatt CHacon 'schacon@gmail.com' Sat May 23 16:48:58 2009 -0700_
_\ntest tag_

Рассширенный тег содержит строку _object_ указывающую на _blob_ объект, и значит тег можно создать для любого _blob_ объекта
