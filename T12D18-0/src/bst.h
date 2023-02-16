#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_btree {
    struct s_btree* left;
    struct s_btree* right;
    int item;
} t_btree;

t_btree* bstree_create_node(int num);
void bstree_insert(t_btree* root, int item, int (*cmpf)(int, int));
void bstree_apply_infix(t_btree* root, void (*applyf)(int));
void bstree_apply_prefix(t_btree* root, void (*applyf)(int));
void bstree_apply_postfix(t_btree* root, void (*applyf)(int));
int compare(int num1, int num2);
void apply_function(int num);
void bstree_delete(t_btree* root);

#endif