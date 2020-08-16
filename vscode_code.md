Для запуска кода потребуется плагин `code runner`, запуск кода `Ctrl + Alt + N`а также некоторые настройки для него:  
``` 
  {
  ...
  // поправка для базового интерпритатора
  "python.defaultInterpreterPath": "python3",
  "python.pythonPath": "python3",
  
  // изменение базового интерпритатора python на python3
  "code-runner.executorMap": { "python": "python3 -u" },
  
  // автроочится панели OUTPUT, автроскро настраивается на панеле(иконка - замочек)
  "code-runner.clearPreviousOutput": true
  ...
  }
```
