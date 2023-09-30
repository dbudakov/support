# double pattern sed

sed -n -e '/home/ {
	/ansible/ {
		s/ansible/MOM/;
		p;
		d;
	}
}
p;' file

sed -e '/home/ {/ansible/ {s/ansible/MOM/;p;d;}}p;' file

## Example

```sh
echo 'one
one,two
one,two,three'>  file

# Изменить one на BANG если строка содержит two И НЕ содержит three
sed -e '/two/ {/three/! {s/one/BANG/}}' file
sed -f file.sed file
```

*источник:* _2.2. Two-Level Nesting_ <https://www.baeldung.com/linux/sed-replace-multi-line-string#3-editing-in-action>