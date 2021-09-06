1. cronn_umputun [link](https://github.com/umputun/cronn)
2. Eсли в процессах уже есть  запущенный процесс, сразу выход, без вычисления уже существующего или своего PID  
`if $(ps | grep [process]); then exit; fi`
3. trap
