### ansible.replase.regexp:  
в начале строки # либо есть либо нет  
```
^#?node.name
```
строка заканчивается на любое кол-во любых значений  
```
node.name:.*
```

#### Примеры
использование `'`
```
sed 's/hello/'\''hello'\''/' file.txt
```

использование [[:digit:]]
```
            [[:digit:]]    \d
grep -E          ✓          ×
grep -P          ✓          ✓
sed              ✓          ×
sed -E           ✓          ×
```


### Дополнительно:
Справочник [regular-expressions](http://www.regular-expressions.info/)
