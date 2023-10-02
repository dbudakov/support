# docker

## show runtime container
```
docker inspect \
  --format "$(curl -s https://gist.githubusercontent.com/efrecon/8ce9c75d518b6eb863f667442d7bc679/raw/run.tpl)" \
  name_or_id_of_your_running_container
```