source: [link]https://unix.stackexchange.com/questions/108493/easy-way-to-paste-command-line-output-to-paste-bin-services)  

Для отпарвки в pastebin на rpm дистрибутивах используется команда `fpaste -i`
```
fpaste -i <file>
fpaste --sysinfo
fpaste --printonly sometime.txt
man fpaste
```

Для других дистрибутивов используется `pastebinit`
