Удалить элемент из массива [[link]](https://coderoad.ru/23462869/%D0%A3%D0%B4%D0%B0%D0%BB%D0%B8%D1%82%D1%8C-%D1%8D%D0%BB%D0%B5%D0%BC%D0%B5%D0%BD%D1%82-%D0%B8%D0%B7-%D0%BC%D0%B0%D1%81%D1%81%D0%B8%D0%B2%D0%B0-bash-%D0%BF%D0%BE-%D1%81%D0%BE%D0%B4%D0%B5%D1%80%D0%B6%D0%B8%D0%BC%D0%BE%D0%BC%D1%83-%D1%85%D1%80%D0%B0%D0%BD%D1%8F%D1%89%D0%B5%D0%BC%D1%83%D1%81%D1%8F-%D0%B2-%D0%BF%D0%B5%D1%80%D0%B5%D0%BC%D0%B5%D0%BD%D0%BD%D0%BE%D0%B9-%D0%BD%D0%B5)
```sh
list=(one two three)
var="two"
list=( "${list[@]/$var}" )
list=( "${list[@]/two}" )
echo ${list[@]}
 one three
echo ${#list[@]}
 3
```
