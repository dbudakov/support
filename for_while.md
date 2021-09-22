# for while cheatsheet

## Перебор по кол-ву параметров переданных скрипту

```
i=0; while [ $i -lt $# ]; do
	echo $i;
    ((i++));
done
```
