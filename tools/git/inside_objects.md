Добавляем данные:
`echo 'test content' | git hash-object -w --stdin` - команда _-w_ заставляет записать данные, без нее просто выведется hash, _--stdin_ заставляет команду читать содержимое из стандартного потока ввода, без нее нужно указывать файл с содержимым _d670460b4b4aece..._
`find .git/objects -type f` - будет выведен наш хеш, но первые два символа уйдут на каталог _.git/objects/d6/70460b4b4aece..._
`git cat-file -p d670460b4b4... ` - воспроизведение файла, _-p_ для определения типа содержимого

Восстановление версии
Изменим содержимое нашего файла:
`echo 'version 1' > test.txt`
`git hash-bobject -w test.txt`
`83baae61...`

И еще раз:
`echo 'version 2' > test.txt`
`git hash-bobject -w test.txt`
`1f7a7a472...`

Проверим каталог _.git/objects_
find .git/objects/ -type f
_.git/objects/1f/7a7a47..._
_.git/objects/83/baae61..._
_.git/objects/d6/70460b..._

Восстановим сначала _version 1_, затем исходное состояние
`git cat-file -p 83baae... > test.txt && cat test.txt`
`git cat-file -p 1f7a7a... > test.txt && cat test.txt`

#### blob

В системе сохраняется не имя файла, а только содержимое, объеты такого типа называются массивами двоичных данных или большими бинарными объектами(_Binary Large Object_l, \_blob_)
`git cat-file -t 1f7a7a472...` - вывести тип файла
_blob_

#### tree

Объект дерево это способ хранения имен и групп файлов, дерево может содержать как _blob_ так в вложенные деревья _tree_, с указанием _SHA-1_, прав доступа, типом и именами файлов

`git cat-file -p master^{tree}` - просмотр содержимого объект-дерева последнего коммита;
`git cat-file -p <hash>`

##### Создание собственных деревьев

Git берет состояние области индесирования и записывает оттуда набор объектов-деревьев, поэтому для создания дерева, нужно проиндексировать файлы.
`git update-index --add test.txt` - добавить файл в индекс
`git update-index test.txt` - проиндексировать файл
`git write-tree` - запись дерева, будет выведен _hash_

`git update-index --add --cacheinfo 100644 83baae61804e65cc73a7201a7252750c76066a30 test.txt` - добавление файла в индекс
_update-index_ - принудительно помещает балее раннюю версию в новую область индексации
_--add_ - так как файл еще не индерсирован(и не настроена область индексации)
_--cacheinfo_ - так как файл находится в базе данных, а не в файле
_100644_ - права доступа, эта комбинация обозначает обычный файл, Вариант _100755_ - соответствует исполняемому файлу, а _120000_ - символической ссылки, у каталогов свои права
_83baae61804e65cc73a7201a7252750c76066a30_ - контрольная сумма
_test.txt_ - имя файла

`git cat-file -t <hash>` - узнать тип файла, будет выведен _tree_
`git read-tree --prefix=bak <hash_tree>` - чтение дерева в область индексирования, таким образом можно добавить поддерево в дерево, если после добавления записать дерево

#### commit

`echo 'first commit' | git commit-tree d8329f` - создания коммита на основе дерева
`echo 'second commit' | git commit-tree 0155eb -p fdf4fc3` - первый хеш, это хеш дерева, второй это хеш коммита, для предыдущего дерева, будет создан второй коммит
`echo 'third commit' | git commit-tree 3c4e9c -p cac0cab`

`echo 'text commit' | git commit-tree <hash-tree> -p <hash_commit>` - общая схема создания коммита

`git cat-file <hash-commit>` - просмотр коммитов
`find .git/objects -type f` - объекты для каждого изменения

#### interactive blob

```rb
# yum install rube git -y
#
# for start: `ruby file.rb`
# or interactive mode `irb`

# создание тела файла
content = "что нового доктор?"

# создание заголовка файла
header = "blob #{content.length}\0"

# задание всего контента как store
store = header + content

# запрос соответствующей библиотеки и подсчет хеша для store
require 'digest/sha1'
sha1 = Digest::SHA1.hexdigest(store)

# запрос соответствующей библиотеки и сжатие контента
require 'zlib'
zlib_content = Zlib::Deflate.deflate(store)

# задание переменной пути для файла
path = '.git/objects/' + sha1[0,2] + '/' + sha1[2,38]

# запрос соответствующей библиотеки, и запись контенса в файл
require 'fileutils'
FileUtils.mkdir_p(File.dirname(path))
File.open(path,'w'){|f| f.write zlib_content}
```
