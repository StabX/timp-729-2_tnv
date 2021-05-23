#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
	int value;          // значение, которое хранит узел 
	struct node *next;  // ссылка на следующий элемент списка
} node;

int pop(node **head){
    node* prev = NULL;
    int val;
    if(head == NULL){
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

// инициализация пустого списка
void init(node **n)
{
    node *tmp = (node*) malloc(sizeof(node));
    tmp->value = 1;
    tmp->next = (*n);
    (*n) = tmp;
}


// удалить все элементы из списка
void clean(node *n)
{
	node *tmp = n;
	node *tmp1;
	while (tmp != NULL)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		free(tmp1);
	}
	n = NULL;
}

// проверка на пустоту списка
bool is_empty(node *n)
{
	if (n == NULL)
		return 1;
	else return 0;
}

// поиск элемента по значению. вернуть NULL если эжемент не найден
node *find(node *n, int value)
{
	node *tmp = n;
	while (tmp != NULL)
	{
		if (tmp->value == value)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}
// вставка значения в конец списка, вернуть 0 если успешно
int push_back(node *n, int value)
{
    if(n == NULL){
        n->value = value;
        return 0;
    }
    while(n->next){
        n = n->next;
    }
    node *last = n;
    node *tmp = (node*) malloc(sizeof(node));
    tmp->value = value;
    tmp->next = NULL;
    last->next = tmp;

    return 0;
}

// вставка значения в начало списка, вернуть 0 если успешно
int push_front(node **l, int value)
{
    node * new_node;
    new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->next = *l;
    *l = new_node;

    return 0;
}

// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(node *n, int value)
{ 
	node* new = (node*)malloc(sizeof(node));
	new->value = value;
	new->next = n->next;
	n->next = new;
}

void insert_after_num(node* n, int num, int value)
{
	node* new = (node*)malloc(sizeof(node));
	new->value = value;
	node* tmp = n;
	int count = 1;
	while (count != num)
	{
		tmp = tmp->next;
		count++;
	}
	new->next = tmp->next;
	tmp->next = new;
}

// удалить первый элемент из списка с указанным значением, 
// вернуть 0 если успешно
int remove_node(node *n, int value)
{
	node *adress;
	node *temp=n;
	adress = find(n, value);
	if (adress==NULL){
		return 1;
	}
	else{
		if (adress == n){
			n = n -> next;
		}
		else{
			while (temp->next != adress){
				temp = temp -> next;
			}
            while(n->next){
                n = n->next;
			if ((adress == n) && (temp->next==NULL)){
                n = temp;
	        }
			else{
			    temp->next=adress->next;
			}
		}
		free(adress);
		return 0;
	    }	
    }
}

// вывести все значения из списка в прямом порядке через пробел,
// после окончания вывода перейти на новую строку
void print(node *n)
{
	if (is_empty(n) == 0)
	{
		node* tmp = n;
		while (tmp != NULL)
		{
			if (tmp->next == NULL)
			{
				printf("%d", tmp->value);
				tmp = tmp->next;
			}
			else
			{
				printf("%d ", tmp->value);
				tmp = tmp->next;
			}
		}
		printf("\n");
	}
}


int main() {
    node *n = NULL;
	init(&n);
	int num, val;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &val);
		push_back(n, val);
	}
    pop(&n);
	print(n);
	for (int i=0; i<3; i++)
	{
	    scanf("%d", &val);
	    if (find(n, val)==NULL)
	    {
	        printf("%d ", 0);
	    }
	    else 
	    {
	        printf("%d ", 1);
	    }
	}
	printf("\n");
	scanf("%d", &val);
	push_back(n, val);
	print(n);
	scanf("%d", &val);
	push_front(&n, val);
	print(n);
	int j, x;
	scanf("%d", &j);
	scanf("%d", &x);
	insert_after_num(n, j, x);
	print(n);
	scanf("%d", &val);
	remove_node(n,val);
	print(n);
	clean(n);
	return 0;
}
