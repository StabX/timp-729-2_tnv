#include <stdio.h>
#include <stdlib.h>

 typedef struct node {
         int value;
         struct node* left;
         struct node* right; 
         struct node* parent;
 } node;

  typedef struct tree {
	node *root; 
 } tree;

  typedef struct node_stack {
	 node *data;  
	 struct node_stack* next; 
 } node_stack;

   typedef struct stack {
	 node_stack* head;  
 } stack;

 void init_stack(stack *s) {
	s->head = NULL;
 }

 int push(stack *s, node *n) {
     node_stack *snode = malloc(sizeof(node_stack));
     snode->data = n;
     snode->next = s->head;
     s->head = snode;
        return 0;
 }

 node* pop(stack *s) {
       node_stack *snode = s->head;
       node *n = s->head->data;
       s->head = s->head->next;
       free(snode);
            return n;
 }

  void clear_stack(stack *s) {
       node_stack *tmp = s->head;
  
            while(tmp != NULL) {
               node_stack *p = tmp->next;
               free(tmp);
               tmp = p;
            }
            s->head = NULL;
 }

  void init(tree* t) {
       t->root = NULL;
 }
 
 node* clear_impl(node *n) { 
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
        return 0;							
  }

 void iterPreorder(node *n) {
      if (n == NULL) {
          return;
      } 
    stack *s = malloc(sizeof(stack));
    init_stack(s);
    push(s, n);

      while (s->head != NULL) {
             n = pop(s);
             printf("%d", n->value);
                
             if (n->right != NULL) {
                 push(s, n->right);
             }
             
             if (n->left != NULL) {
                 push(s, n->left);
             }
             if (s->head != NULL) {
                 printf(" ");
             }
       }
       printf("%c", '\n');
       clear_stack(s);
 }

 int main() {
        tree *t = malloc(sizeof(tree));
        init(t);
	int n = 7;
        int a;

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		insert(t, a);
	}

	iterPreorder(t->root);
        clear(t);

	return 0;
 }
