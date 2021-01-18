[link](https://qastack.ru/unix/396223/bash-shell-script-output-alignment)  

# По краю
```
$ printf '|%-4s|\n' a ab abc abcd abcde
|a   |
|ab  |
|abc |
|abcd|
|abcde|
 printf '|%4s|\n' a ab abc abcd abcde
|   a|
|  ab|
| abc|
|abcd|
|abcde|
```

# C усечением
```
$ printf '|%.4s|\n' a ab abc abcd abcde
|a|
|ab|
|abc|
|abcd|
|abcd|
$ printf '|%4.4s|\n' a ab abc abcd abcde
|   a|
|  ab|
| abc|
|abcd|
|abcd|
$ printf '|%-4.4s|\n' a ab abc abcd abcde
|a   |
|ab  |
|abc |
|abcd|
|abcd|
```
