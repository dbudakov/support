### system bashrc
```
/etc/profile 
/etc/profile.d/ 
/etc/bash.bashrc
```

### user
```sh
# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# Импорт алиасов или переменных
# if [ -f ~/.bash_aliases ];then
#    source ~/.bash_aliases
# fi


# user specific environment
PATH="$HOME/.local/bin:$HOME/bin:$PATH"
export PATH
export PATH="/usr/local/bin:$PATH"

PS1='\[\033[0;94m\]\u$\[\033[00m\] '

```
### root
```sh
alias rm='rm -i'
alias cp='cp -i'
alias mv='mv -i'

if [ -f /etc/bashrc ]; then
        . /etc/bashrc
fi
PATH="$HOME/.local/bin:$HOME/bin:$PATH:/usr/bin:/usr/sbin"
export PATH
export PATH="/usr/local/bin:$PATH"

PS1='\[\033[0;91m\]\u>\[\033[00m\] '
```

### bind

[humbug.in](http://www.humbug.in/2010/custom-key-bindings-keyboard-shortcuts-in-bash/)  

Очистка экрана и вывод времени, цвет(01;91m)
```sh
bind '"\C-l"':"\"clear; printf \'\\\033[01;91m[%s]\\\033[01;00m\\\n\' $(date +%T) \C-m\""
#bind '"\C-l"':"\" clear; echo -e \'\\\033[01;91m[$(date +%T)]\\\033[01;00m\' \C-m\""
```

### user@host:path (git branch)$ 

```sh
# takes a number argument of the number of last dirs to show
function DIR_LAST {
    # read -a didn't seem to work under bash 3
    IFS='/' array=($PWD)
    len=${#array[@]}
    start=$((len - $1))
    # leading / if fewer dir args: /usr/flastname not usr/flastname
    if (( $start <= 1 )); then
        start=1
        echo -n /
	else
		echo -n ../
    fi
    for (( i = $start; $i < $len; i++ )); dov
        if (( $i > $start )); then
            echo -n /
        fi
        echo -n ${array[$i]}
    done
}
parse_git_branch() {
git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/(\1)/'
}
printf "%s\n" $(date +%T)
export PS1="\[\033[0;91m\]\u@\h\[\033[00m\]:\[\033[01;34m\] \$(DIR_LAST 2)\[\033[00m\]$(parse_git_branch)\[\033[00m\]: "

# two line with time in first 
#export PS1="\e]2;[\u@\h]\a[\e[31;1m\t\e[0m]\n\[\033[0;91m\]\u@\h\[\033[00m\]:\[\033[01;34m\] \$(DIR_LAST 2)\[\033[00m\]$(parse_git_branch)\[\033[00m\]: "
```

### code_return
```sh
GREEN="\e[0;32m"
RED="\e[01;91m"
WHITE="\e[0m"
function code_return {
	if (( $? == 0 ))
	then
		echo -en "${GREEN}√${WHITE}"
		# echo -en "${GREEN}$?${WHITE}"
	else
		echo -en "${RED}x${WHITE}"
		# echo -en "${RED}$?${WHITE}"
	fi
}
export PS1='[$(code_return)]$'
```
