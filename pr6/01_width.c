#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value; 
	struct node *left; 
	struct node *right; 
	struct node *parent;  
 } node;

 typedef struct tree {
	node *root; 
	unsigned int size;
 } tree;

 typedef struct node_queue {
	 node *limb;  
	 struct node_queue* next; 
 } node_queue;

 typedef struct queue {
	 node_queue* head; 
	 node_queue* tail; 
 } queue;


 void init_queue(queue *q) {
	q->head = NULL;
	q->tail = NULL;
 }


 int push_queue(queue *q, node *n) {
	node_queue *tmp = malloc(sizeof(node_queue));

	tmp->limb = n;
	tmp->next = NULL;

	if(q->head == NULL) {
	   q->head = tmp;
	   q->tail = tmp;
	}
	else {
		q->tail->next = tmp;
            q->tail = tmp;
	}
    return 0;
 }

 node* pop_queue(queue *q) {
	node_queue *tmp = q->head;
	node* n = tmp->limb;

	if(q->head == NULL) {
	   return NULL;
    }
    q->head = tmp->next;
	free(tmp);

	return n;
 }
 
 void clear_queue(queue *q) {
    node_queue *tmp = q->head;

    while (tmp != NULL) {
        node_queue *tmp1 = tmp->next;
        free(tmp);
        tmp = tmp1;
    }
    q->head = NULL;
    q->tail = NULL;
}

  void init(tree* t) {
    t->root = NULL;
	t->size = 0;
 }

 node* clear_impl(node *n) {  //
    if (n != NULL) {
        clear_impl(n->left);
        clear_impl(n->right);
        n = NULL;
        return n;
    }

    return NULL;
}

void clear(tree *t) {
    clear_impl(t->root);
}

 int insert(tree* t, int value) {
	node* tmp = malloc(sizeof(node));
  	tmp->value = value;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = NULL;

	node* curr = t->root;
	node* prev = NULL;
	
	if(t->root == NULL) {
	   t->root = tmp;
	}
	else {
		while(curr != NULL){
		      prev = curr;
		      if(value < curr->value) {
			 curr = curr->left;
		}
		       else if(value > curr->value) {
			       curr = curr->right;
			}
			else if (value == curr->value) {
			       return 1;
			}
		}
                tmp->parent = prev;

		if(value < prev->value) {
			   prev->left = tmp;	   
		}
		else if (value > prev->value) {
		      prev->right = tmp;
		}
	}
        t->size++;
        return 0;																																																
 }

 void print_queue(tree *t) {
    queue *q = malloc(sizeof(queue));
    init_queue(q);
    push_queue(q, t->root);
     
    while (q->head != NULL) {
        node *tmp = pop_queue(q);
        printf("%d", tmp->value);
     
        if (tmp->left != NULL) {
            push_queue(q, tmp->left);
        } 
        if (tmp->right != NULL) {
            push_queue(q, tmp->right);
        }
        if (q->head != NULL) {
            printf(" ");
       }
    }																																																																	
    printf( "%c", '\n');
    clear_queue(q);
}


int main() {
    tree *t = malloc(sizeof(tree));
    init(t);
	int n = 7;
    int x;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		insert(t, x);
	}
	print_queue(t);
    clear(t);
	return 0;
 }
