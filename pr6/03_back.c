#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Структура для хранения узла дерева.
// Необходимо хранить ссылки на потомков, предка и некоторое значение
typedef struct node {
	int value;
	struct node *left;
	struct node *right;
	struct node *parent;
} node;


// Структура для хранения дерева.
// Хранит ссылку на корень дерева и количество элементов в дереве
typedef struct tree {
	int amount;
	struct node *root;
} tree;

// Инициализация дерева
void init(tree* t) {
    t = malloc(sizeof(tree));
    t->root = NULL;
    t->amount = 0;
};

node* createNew(node* parent, int value) {
	node* tmp = malloc(sizeof(node));
    tmp->left = tmp->right = NULL;
    tmp->value = value;
    tmp->parent = parent;
}

int insert(tree* t, int value) {
	node *tmp = NULL;

	// Если корень дерева пуст
    if (t->root == NULL) {
        t->root = createNew(tmp, value);
		t->amount++;
        return 0;
    }

    tmp = t->root;
    while (tmp) {
		// Если значение меньше корневого
        if (value > tmp->value) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = createNew(tmp, value);
				t->amount++;
                return 0;
            }
		// Если значение больше корневого
        } else if (value < tmp->value) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = createNew(tmp, value);
				t->amount++;
                return 0;
            }
        } else if (value == tmp->value)
			return 1;
		else {
            return 2;
        }
    }
};
void preOrderTravers(node* root) {
    if (root) {
        printf("%d ", root->value);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}
 
void inOrderTravers(node* root) {
    if (root) {
        inOrderTravers(root->left);
        printf("%d ", root->value);
        inOrderTravers(root->right);
    }
}
void postorder(node *root) {
    if (root == NULL)
        return;
    postorder(root -> left);
    postorder(root -> right);
    printf("%d ", root -> value);
}

int main() {
	tree* Tree = malloc(sizeof(tree));
    int i, x;
    init(Tree);//1 пункт
    for (i = 0; i < 7; i++)
    {
        scanf("%d", &x);
        insert(Tree, x);
    }
    postorder(Tree->root);
}
