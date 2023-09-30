/*budakvoda, https://github.com/dbudakov */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define SYMBOL ' '
#define NEGATIVE 1

#define FILE "./testfile"
#define NUM_COLUMN 1

size_t get_len_file(int fd)
{
	size_t num;

	lseek(fd, 0, SEEK_END);
	num = lseek(fd,0, SEEK_CUR);
	lseek(fd, 0, SEEK_SET);
	printf("len = %d\n", num);
	return num;
}

char *file_to_str(int fd, size_t len)
{
	char 	str1[len];
	char	*str;

	// str = (char *)malloc(len + 1);
	read(fd, &str1, len);
	str1[len] = '\0';
	str = str1;

	return str;
}

int get_num_str(char *str_file)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (str_file[i] != '\0')
	{
		if (str_file[i] == '\n')
			n++;
		i++;
	}
	return n;
}

int get_max_word(char *str_file)
{
	int i;
	int n;
	int max_word;

	n = 0;
	i = 0;
	max_word = 0;
	while (str_file[i] != '\0')
	{
		while (str_file[i] != '\n')
		{
			if (str_file[i] == ' ')
				n++;
			i++;
		}
		if (str_file[i] == '\n')
			n++;
		if (max_word < n)
			max_word = n;
		n = 0;
		i++;
	}
	return max_word;
}

int **get_arr_pre(char *str_file, int num_str, int num_max_word)
{
	int	i, j, k;
	int	start;
	int	end;
	int	s;
	int **arr_pre;

	i = 0;
	arr_pre = (int**)malloc(num_str);
	while(i < num_str)
	{
		arr_pre[i] = (int*)malloc(1);
		// printf("%d, ", sizeof(arr_pre[2][1]));
		i++;
	}

	i = 0;
	j = 0;
	k = 0;
	while(str_file[i] != '\0')
	{
		if (str_file[i] == SYMBOL || str_file[i] == '\n')
		{
			arr_pre[j][k++] = s;
			// printf("%d,%d: %d\n", j,k, arr_pre[j][k-1]);
			s = 0;
			if (str_file[i] != '\n')
				i++;
		}
		if (str_file[i] == '\n')
		{
			k = 0;
			j++;
		}
		s++;
		i++;
	}
	return arr_pre;
}

int *get_max_val_arr(int **arr_pre, int num_str, int num_max_word)
{
	int i;
	int j;
	int max_val;
	int	arr_res[num_max_word];
	// char *arr_rez;
	int *num;

	i = 0;
	j = 0;
	max_val = 0;

	// arr_res = (int*)malloc(num_max_word);
	// arr_rez = malloc(1);

	while(i < num_max_word)
	{
		while(j < num_str)
		{
			if (max_val < arr_pre[j][i])
				max_val = arr_pre[j][i];
			j++;
		}
		arr_res[i] = max_val;
		max_val = 0;
		j = 0;
		i++;
	}
	num = arr_res;
	return num;
}

void ft_column_output(int *arr_res, char *str_file, int num_max_word)
{
	int	i;
	int	j;
	int n;

	int max_value;

	i = 0;
	j = 0;
	max_value = 0;
	while( i < num_max_word)
	{
		if (max_value < arr_res[i])
			max_value = arr_res[i];
		i++;
	}
	n = 0;
	// str = (char *)malloc(max_value + 1);
	char str[max_value + 1];

	i = 0;
	while(str_file[i] != '\0')
	{
		while (str_file[i] != SYMBOL && str_file[i] != '\n' && str_file[i] != '\0')
			str[n++] = str_file[i++];
		str[n] = '\0';
		n = 0;

		if (j < NUM_COLUMN)
		{
			if (NEGATIVE)
				printf("%-*s ", arr_res[j], str);
			else
				printf("%*s ", arr_res[j], str);
		}
		else
			printf("%s ", str);


		if (j < num_max_word - 1)
			j++;
		else
		{
			printf("\n");
			j = 0;
		}
		i++;

	}

	// printf("", arr_res[j], )
}

int *get_max_val_field(char *str_file)
{
	int i, j;
	int **arr_pre;
	int *arr_res;
	int	num_str;
	int	num_max_word;

	i = 0;

	num_str = get_num_str(str_file);

	num_max_word = get_max_word(str_file);


	arr_pre = get_arr_pre(str_file, num_str, num_max_word);
	arr_res = get_max_val_arr(arr_pre, num_str, num_max_word);
	ft_column_output(arr_res, str_file, num_max_word);
	return arr_res;
}

void main()
{
	int		fd;
	int		*arr;
	size_t	len;
	char	*str_file;


	fd = open(FILE, O_RDONLY);
	len = get_len_file(fd);
	str_file = file_to_str(fd, len);

	arr = get_max_val_field(str_file);
}
