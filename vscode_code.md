Для запуска кода потребуется плагин `code runner`, запуск кода `Ctrl + Alt + N`а также некоторые настройки для него:  
``` 
  {
  ...
  
  // отключени автокомплита(выпадания подсказов при наборе команды)/autocomplete
  "editor.quickSuggestions": false,
  
  // отключает подсказки
  "editor.parameterHints": false,
  
  // затухающие мигания курсора
  "editor.cursorBlinking": "phase",
  
  // показывает количество пробелов перед строкой
  "editor.renderWhitespace": "boundary"
  
  // убирает всплывающие подсказки
  "editor.hover.enabled": false,
  
  // показывает сниппеты, варианты использования команды(функции)
  "editor.suggest.showSnippets": false,
  
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

```
// ДОПОЛНИТЕЛЬНАЯ ПЕРЕДАЧА СЛОВ
// Определяет, должны ли строки переноситься. Строки будут перенесены на min (editor.wrappingColumn, viewportWidthInColumns).
"editor.wordWrap": "выкл",
// Управляет отступом переносимых строк. Может принимать одно из следующих значений: «нет», «такой же» или «отступ».
"editor.wrappingIndent": "нет",
// ОТКЛЮЧИТЬ АВТОЗАВЕРШЕНИЕ
// Контролирует, должны ли отображаться быстрые предложения при вводе текста
"editor.quickSuggestions": ложь,
// Контролирует задержку в мс, после которой будут появляться быстрые предложения
"editor.quickSuggestionsDelay": 90,
// Включает подсказки параметров
"editor.parameterHints": ложь,
// Контролирует, должен ли редактор автоматически закрывать скобки после их открытия
"editor.autoClosingBrackets": false,
// Определяет, должен ли редактор автоматически форматировать строку после ввода
"editor.formatOnType": false,
// Контролирует, должны ли предложения автоматически отображаться при вводе триггерных символов
"editor.suggestOnTriggerCharacters": false,
// Контролирует, следует ли принимать предложения. «Enter» - в дополнение к «Tab». Помогает избежать двусмысленности между вставкой новых строк или принятием предложений.
"editor.acceptSuggestionOnEnter": "off"
```
