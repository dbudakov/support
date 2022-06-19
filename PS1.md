[тонкости PS1](https://riptutorial.com/ru/bash/example/24948/%d0%b8%d1%81%d0%bf%d0%be%d0%bb%d1%8c%d0%b7%d0%be%d0%b2%d0%b0%d0%bd%d0%b8%d0%b5-ps1)  
[настройка PS1](https://sodocumentation.net/ru/bash/topic/3340/%D0%BD%D0%B0%D1%81%D1%82%D1%80%D0%BE%D0%B9%D0%BA%D0%B0-ps1)

```
## ~/.bashrc
PS1='\[\033[0;94m\]\u$\[\033[00m\] '
  [0;94m] - 0 - вид шрифка(жирность), 94 - цвет шрифта(94-light blue, 31-red)  

```

```bash
# current path, no more than 8 characters
ft_path(){ 
    pwd | 
    awk -F / '{if (length($NF) > 8) print substr($NF,1,6)"*"substr($NF,length($NF),length($NF)); else printf $NF}';
}

# rc in prefix
ft_returnCode(){
  if [ $? -eq 0 ]; then
    echo '\[\033[2;32m\][v]\[\033[00m\]'
  else
    echo '\[\033[2;31m\][x]\[\033[00m\]'
  fi
}

ft_currentDirectory(){
    echo '\[\033[0;94m\]$(ft_path)$ \[\033[00m\]'  
}

function prompt_cmd
{
  returnCode=$(ft_returnCode)
  currentDirectory=$(ft_currentDirectory)
  export PS1="$returnCode$currentDirectory"
}

export PROMPT_COMMAND=prompt_cmd
```
