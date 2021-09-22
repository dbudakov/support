# for while cheatsheet

## Перебор параметров переданных скрипту

```
i=0; while [ $i -lt $# ]; do
	echo ${!i}
    ((i++));
done
```
source: [eval](https://coderoad.ru/11065077/%D0%BA%D0%BE%D0%BC%D0%B0%D0%BD%D0%B4%D0%B0-eval-%D0%B2-Bash-%D0%B8-%D0%B5%D0%B5-%D1%82%D0%B8%D0%BF%D0%B8%D1%87%D0%BD%D0%BE%D0%B5-%D0%B8%D1%81%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5)  
