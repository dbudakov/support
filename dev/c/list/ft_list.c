#ifndef FT_LIST_H
# define FT_LIST_H

// # include <unistd.h>
// # include <stdio.h>
# include <stdlib.h>


typedef struct Data {
	int count;
} Data;

typedef struct Node {
	Data p_data;
	struct Node *next;
} Node;

typedef Node *PNode;

PNode InitNode(int c){
	PNode INode = (Node *)malloc(sizeof(Node));
	INode->p_data.count = c;
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

/* имеется добавление в пустой список (head = null)*/
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

void AddBefore2 (PNode p, PNode NewNode)
{
	Node temp;

	temp = *p;
	*p = *NewNode;
	*NewNode = temp;
	p->next = NewNode;
}

void AddBefore(PNode Head, PNode p, PNode NewNode){
	PNode q = Head;
	if (Head == NULL){
		AddFirst (&Head, NewNode);
		return;
	}
	while (q && q->next != p)
		q = q->next;
	if (q)
		AddAfter(q, NewNode);
}

void DeleteNode(PNode &Head, PNode p) {
	PNode q = Head;
	if (p == Head)
		Head = p->next;
	else {
		while (q && q->next != p)
			q = q->next;
		if (q == NULL)
			return;
		q->next = p->next;
	}
	free (p);
}

#endif

// int main(void)
// {
// 	PNode ptr;
// 	PNode q;

// 	ptr = NULL;
// 	ptr = InitNode(5);
// 	// AddAfter(ptr, InitNode(4));


// 	q = ptr;
// 	while (q)
// 	{
// 		// printf("%p\n", q);
// 		printf("%d\n", q->p_data.count);
// 		q = q->next;
// 	}
// 	return 0;
// }
