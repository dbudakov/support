Операции регулярных выражений в ls источник [set](https://habr.com/ru/post/452522/)
```sh
$ touch afile bfile cfile
$ ls
afile bfile cfile
$ ls ?(a*|b*)
afile bfile
$ ls !(a*|b*)
cfile
```
