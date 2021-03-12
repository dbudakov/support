Операции регулярных выражений в ls источник [set](https://habr.com/ru/post/452522/)
```sh
$ touch afile bfile cfile
$ ls
afile bfile cfile
$ ls ?(a*|b*)
afile bfile
$ ls !(a*|b*)
cfile
# touch 1 2 3 4 5 a b c A B C ; rm -f *!([3-5]|[a]) 
1  2  A  b  B  c  C
# touch 1 2 3 ; ls !(3)
1  2
```
