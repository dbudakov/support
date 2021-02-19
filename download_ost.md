# Скачать список mp3

```sh
#https://www.ostmusic.org/album/id/269

ARTIST="Jed Palmer"

cat /tmp/ost/list.txt \
| sed -e 's/[[:digit:]]//g' -e 's/://g' -e 's/"${ARTIST}"/g' -e 's/ /_/g' \
| grep -v ^$ \
| awk -v i=0 'NR <= 9 ,$0 !~ /^[[:blank:]]/ {  print "0" ++i "." $0 ; next } { print }' \
| awk  -v i=9 'NR > 9 , $0 !~ /^[[:blank:]]/ {  print  ++i "." $0 ; next } { print }'>/tmp/ost/list1.txt

arr2+=($(cat /tmp/ost/list1.txt))
for(( i= 0; i<${#arr2[@]}; i ++)); do b=$(($i+6471)); wget -q "https://www.ostmusic.org/?view=file&format=raw&id=$b" -O /tmp/ost/${arr2[i]}.mp3;echo ${arr2[$i]}; done
```
