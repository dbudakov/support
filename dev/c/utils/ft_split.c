# include <unistd.h>
# include <stdlib.h>

typedef struct Data {
	char *str;
} Data;

typedef struct Node {
	Data p_data;
	struct Node *next;
} Node;

typedef Node *PNode;

PNode InitNode(char *s){
	PNode INode = (Node *)malloc(sizeof(Node));
	INode->p_data.str = s;
	INode->next = NULL;
	return INode;
}

void AddFirst(PNode *Head, PNode NewNode){

	NewNode->next = *Head;
	*Head = NewNode;
}

void AddAfter(PNode p, PNode NewNode){
	NewNode->next = p->next;
	p->next = NewNode;
}

void AddLast(PNode *Head, PNode NewNode)
{
	PNode q = *Head;
	if (*Head == NULL) {
		AddFirst(Head, NewNode);
		return;
	}
	while (q->next)
		q = q->next;
	AddAfter(q, NewNode);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		write(1, &str[i],1);
		i++;
	}

}

int	ft_isspace(char c)
{
	if (c >= 9 && c <= 13 || c == ' ' || c == '\0')
		return 1;
	return 0;
}

int	ft_char_count(char *str)
{
	int	i;

	i = 0;
	while(!ft_isspace(str[i]))
		i++;
	return i;
}

char *ft_get_word(char *str)
{
	char	*s;
	int		i;

	i = 0;
	s = NULL;
	s = (char *)malloc((sizeof(char) * ft_char_count(&str[i])) + 1);
	if (!s)
		return NULL;
	while(!ft_isspace(str[i]))
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return s;
}

int ft_get_list(char *str, PNode *lst)
{
	int	i;
	int	j;
	int	n;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while(str[i] != '\0')
	{
		if (flag == 0)
		{
			if (!ft_isspace(str[i]))
			{
				flag = 1;
				AddLast(lst, InitNode(ft_get_word(&str[i])));
				j++;
			}
		}
		else
			if (ft_isspace(str[i]))
				flag = 0;
		i++;
	}
	return j;
}

char    **ft_split(char *str)
{
	int		i;
	int		num_word;
	char	**arr;
	PNode	lst;
	PNode	q;

	i = 0;
	lst = NULL;
	num_word = 0;
	num_word = ft_get_list(str, &lst);
	arr = (char **)malloc((sizeof(char *) * (num_word + 1)));

	q = lst;
	while (q)
	{
		arr[i] = q->p_data.str;
		q = q->next;
		i++;
	}
	arr[i] = '\0';

	while(lst->next)
	{
		q = lst;
		while(q->next->next)
			q = q->next;
		free(q->next);
		q->next = NULL;
	}
	free(lst);
	return arr;
}

int main(void)
{
	int	i;
	int	j;
	char	**arr;

	i = 0;
	arr = 0;
	arr = ft_split("Alea jacta est");
	while(arr[i]){
		ft_putstr(arr[i]);
		ft_putstr("\n");
		free(arr[i]);
		i++;
	}
	free(arr);

	return 0;
}
