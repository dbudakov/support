# README.md

## Замечания

1. Некорректно работает с одной строкой
2. Добавить указание разделителя

## Описание

Выравнивает указанное количество столбцов слева.

## Решение

Сборка

```c
cc ft_column.c
```

Запуск

```bash
./a.out [filename] -t [num_column]
```

Вывод будет на **stdin**

## Алгоритм

- Открываем файл
- Загоняем файл в строку
- Считаем количество строк и максимальное число слов в строке
- Создаем двумерный массив, в котором запишем длину слов в каждой строках
- Создаем одномерный массив для хранения максимальной длины слова для столбца
- Выводим файл по словам, выровнивая столбцы в указанном диапазоне

## Масштабирование

0.

## Troubleshooting

1. Были проблемы с malloc, требовалось добавить размеры типов(sizeof) при выделении памяти

## Дополнительно

[table](https://unix.stackexchange.com/questions/256739/how-do-i-properly-align-multi-column-text-file)