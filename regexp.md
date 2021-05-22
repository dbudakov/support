### Удалить все кроме  
```
rm *.!(txt)
```

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
Вложенные папки, для путей a/z a/b/z a/b/c/z
```
a/**/z 
```

Только цифры
```
grep -E ^[[:digit:]]+$
```

Несколько символов - квантификатор, пример 3 любых цифры
```sh
grep -E '[[:digit:]]{3}'
```

### Дополнительно:
Справочник [regular-expressions](http://www.regular-expressions.info/)
