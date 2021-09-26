## link
[linuxcofig.org](https://linuxconfig.org/bash-prompt-basics)  
[habr.com](https://habr.com/ru/post/269967/)  

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

#radio-t
alias cat=`bat`
alias ls=`exa`
alias ll=`exa --long --grid`
alias mc='broot'

# git
alias pgit='git add .; git commit -m "next"; git push'
alias fgit='pgit; git fetch; git pull'
alias gclean='git clean -xf'

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

### bind ^L = clear && date

[humbug.in](http://www.humbug.in/2010/custom-key-bindings-keyboard-shortcuts-in-bash/)  

```sh
bind '"\C-l"':"\"clear; printf \'\\\033[01;91m[%s]\\\033[01;00m\\\n\' $(date +%T) \C-m\""
# bind '"\C-l"':"\"clear; printf \'[%s]\\\n\' $(date +%T) \C-m\""
# bind '"\C-l"':"\" clear; echo -e \'\\\033[01;91m[$(date +%T)]\\\033[01;00m\' \C-m\""
```

### [code_return]user@host:path (git branch)$ 

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
    for (( i = $start; $i < $len; i++ )); do
        if (( $i > $start )); then
            echo -n /
        fi
	# write [$i + 1] for print 1 level path
        echo -n ${array[$i]}
    done
}

parse_git_branch() {
git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/(\1)/'
}

PROMPT_COMMAND=__prompt_command # Func to gen PS1 after CMDs
__prompt_command() {
    local EXIT="$?"             # This needs to be first
    PS1=""

    local color_zero='\[\e[0m\]'

    local color_red='\[\e[0;31m\]'
    local color_green='\[\e[0;32m\]'
    #local BYel='\[\e[1;33m\]'
    #local BBlu='\[\e[1;34m\]'
    #local Pur='\[\e[0;35m\]'

    if [ $EXIT != 0 ]; then
        PS1+="[${color_red}x${color_zero}]"      # Add red if exit code non 0
    else
        PS1+="[${color_green}√${color_zero}]"
    fi

    #PS1+="${RCol}@${BBlu}\h ${Pur}\W${BYel}$ ${RCol}"
    PS1+="\[\033[0;91m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\$(DIR_LAST 2)\[\033[00m\]$(parse_git_branch)\[\033[00m\]$ "
}
```

### more var

```sh
PS1='\[\e[0;32m\][ $? \[\e[0;33m\]\t \[\e[0;32m\]\u \[\e[0;33m\]\w \[\e[0;32m\]] \$ \[\e[0m\]'
```

### editor

```sh
export EDITOR=vim
```
