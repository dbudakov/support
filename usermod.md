# usermod
[link](https://www.freecodecamp.org/news/linux-user-groups-explained-how-to-add-a-new-group-a-new-group-member-and-change-groups/#:~:text=A%20user's%20primary%20group%20is,other%20than%20the%20primary%20group.)
  
Добалить пользователя в группу
```sh
usermod -a -G group_name user_name
```

Изменить primary group для пользователя
```sh
usermod -g group_name user_name
```

Проверить group
```sh
id -nG quincy
```

Удалить дополнительные группы кроме указанной, игнорирует primary_group
```sh
usermod -G addition_group user_name
```
