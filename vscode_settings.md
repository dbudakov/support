# settings.json

Открыть меню настроем можно, выполнив поиск в настройках vscode:

```js
"[json]":{"editor.quickSuggestions": {"strings": true},"editor.suggest.insertMode": "replace"}
```

## Settings

```json

//.config/Code/User/settings.json

//.config/Code/User/settings.json
{
    "files.insertFinalNewline": true, // insert one line in the end file
    "files.trimFinalNewlines": true, // delete all lines in the end, after final line
    "files.trimTrailingWhitespace": true, // save last space
    "explorer.confirmDelete": false, // quest befor delete file
    "explorer.confirmDragAndDrop": false, // quest befor draganddrop file
    ////ignore sync settings
    //@sync-ignore
    //"editor.fontSize": 14,
    //@sync-ignore
    //"terminal.integrated.fontSize": 14,
    //@sync-ignore
    //"markdown.preview.fontSize": 14,
    "editor.wordWrap": "off", // умещать строку в окне
    "editor.mouseWheelZoom": true, //mouse zoom
    "editor.formatOnSave": true,
    "editor.insertSpaces": false,
    "editor.tabSize": 2,
    "editor.quickSuggestionsDelay": 1000,
    "workbench.colorTheme": "Ayu Mirage Bordered",
    "workbench.iconTheme": "vs-seti",
    "workbench.settings.useSplitJSON": true,
    "C_Cpp.updateChannel": "Insiders",
    "launch": {
        "configurations": [],
        "compounds": []
    },
    "[markdown]": {
        "files.trimTrailingWhitespace": false,
        "editor.wordWrap": "off", // умещать строку в окне
    },
    "markdownlint.config": {
        //https://github.com/DavidAnson/vscode-markdownlint#configure
        "default": true,
        "no-hard-tabs": false
    },
}

```

## Debugger

```json

//.vscode/launch.json

{
    /* comment */
	// Use IntelliSense to learn about possible attributes.
	// Hover to view descriptions of existing attributes.
	// For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
	"version": "0.2.0",
	"configurations": [
		{
			"name": "(gdb) Launch",
			"type": "cppdbg",
			"request": "launch",
			"program": "enter program name, for example ${workspaceFolder}/a.out",
			"args": [],
			"stopAtEntry": false,
			"cwd": "${workspaceFolder}",
			"environment": [],
			"console": "externalTerminal",
			"MIMode": "gdb",
			"setupCommands": [
				{
					"description": "Enable pretty-printing for gdb",
					"text": "-enable-pretty-printing",
					"ignoreFailures": true
				}
			]
		}
	]
}
```
