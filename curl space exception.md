# curl space error
```sh
# if you use parameter with SPACE
name="billy willy"
curl -H "Content-type: application/json" "https://$SERVER/$API" -d '{"userId": "'$u_id'", "data": { "name": "'$name'"}}'
> Bad Reques

# this work over file
name="billy willy"
echo '{"userId": "'$u_id'", "data": { "name": "'$name'"}}' >file
curl -H "X-Auth-Token: $auth_token" -H "X-User-Id: $user_id" -H "Content-type: application/json" "https://$SERVER/$API" --data "@./file"
> Success
```
