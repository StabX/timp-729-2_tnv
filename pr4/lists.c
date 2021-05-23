#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
int value;
struct node* next;
struct node* prev;
} node;

typedef struct list {
struct node* head;
struct node* tail;
} list;

void init(list* l)
{
list* tmp = (list*)malloc(sizeof(list));
tmp->head = tmp->tail = NULL;
*l = *tmp;
}

void clean(list* l)
{
node* tmp = l->head;
node* tmp1;
while (tmp != NULL)
{
tmp1 = tmp;
tmp = tmp->next;
free(tmp1);
}
l->head = NULL;
l->tail = NULL;
}

bool is_empty(list* l)
{
if (l->head == NULL)
return 1;
else return 0;
}

node* find(list* l, int value)
{
node* tmp = l->head;
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

int push_back(list* l, int value)
{
node *tmp = malloc(sizeof(node));
if (tmp == NULL)
{
return 0;
}
tmp->value = value;
tmp->next = NULL;
tmp->prev = l->tail;
if (l->tail)
{
l->tail->next = tmp;
}
l->tail = tmp;

if (l->head == NULL)
{
l->head = tmp;
}
return 0;
}

int push_front(list* l, int value)
{
node* newNode = (node*)malloc(sizeof(node));
newNode->value = value;
if (l->head == NULL)
{
l->head = newNode;
l->tail = newNode;
}

else
{
newNode->next = l->head;
newNode->next->prev = newNode;
l->head = newNode;
}
if (newNode != NULL)
{
return 0;
}
}

int insert_after_num(node *n, int value, list* l) {
node *node_added = (node*) malloc(sizeof(node));
if (n->next == NULL)
{
node_added->prev = n;
n->next = node_added;
l->tail = node_added;
node_added->value=value;
return 0;
}
node_added->value = value;
node_added->prev = n;
node_added->next = n->next;
n->next->prev = node_added;
n->next = node_added;
return 0;
}

int insert_before(node *n, int value, list* l)
{
node *node_added = (node*) malloc(sizeof(node));
if (n->prev == NULL)
{
node_added->next = n;
n->prev = node_added;
l->head = node_added;
node_added->value=value;
return 0;
}
node_added->value = value;
node_added->prev = n->prev;
n->prev->next = node_added;
node_added->next = n;
n->prev = node_added;
return 0;
}

int remove_node(list* l, int value)
{
node *tmp = l->head;
while(tmp != NULL){
if(tmp->value == value){
if (tmp->prev) {
tmp->prev->next = tmp->next;
}
if (tmp->next) {
tmp->next->prev = tmp->prev;
}

if (!tmp->prev) {
l->head = tmp->next;
}
if (!tmp->next) {
l->tail = tmp->prev;
}

free(tmp);
return 0;
}
else {
tmp = tmp->next;
}
}
return 1;
}

node *findlast(list *l, int value) {
node *tmp = l->tail;
if(! l -> head) {
return NULL;
}
while(tmp) {
if(tmp->value == value)
return tmp;
tmp=tmp->prev;
}
return NULL;
}

int remove_last(list *l, int key) {
if(l -> head == NULL) {
return 1;
}
node *found = findlast(l, key);
if (found != NULL) {
node *prev = found -> prev;
node *next = found -> next;
if (prev != NULL) {
prev -> next = next;
}
if (next != NULL) {
next -> prev = prev;
}
if (found == l->head) {
l -> head = found -> next;
}
if (found == l -> tail) {
l -> tail = found -> prev;
}
free(found);
}
return 0;
}

void print(list* l)
{
node *tmp = l->head;
if (tmp == NULL) {
return;
}
while(tmp != NULL) {
printf("%d ", tmp-> value);
tmp = tmp -> next;
}
printf("\n");
}

void print_invers(list* l)
{
node *tmp = l -> tail;
if(tmp == NULL) {
return;
}
while(tmp != NULL) {
printf("%d ", tmp-> value);
tmp = tmp -> prev;
}
printf("\n");
}

int main() {

struct list* l;
l = malloc(sizeof(list));
init(l);
int n, val, i;
scanf("%d", &n);
for (int i = 0; i < n; i++)
{
scanf("%d", &val);
push_back(l, val);
}
print(l);
for (int i = 0; i < 3; i++)
{
scanf("%d", &val);
if (find(l, val) == NULL)
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
push_back(l, val);
print_invers(l);
scanf("%d", &val);
push_front(l, val);
print(l);
int j, x;
scanf("%d", &j);
scanf("%d", &x);
node *temp = l->head;
for (i = 1; i < j; i++)
{
temp = temp->next;
}
insert_after_num(temp, x, l);
print_invers(l);
int u, y;
scanf("%d", &u);
scanf("%d", &y);
temp = l->head;
for (i = 1; i < u; i++)
{
temp = temp->next;
}
insert_before(temp, y, l);
print(l);

scanf("%d", &val);
remove_node(l, val);
print_invers(l);

scanf("%d", &val);
remove_last(l, val);
print(l);
clean(l);
return 0;
}
