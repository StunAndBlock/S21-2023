#include "bst.h"

t_btree *bstree_create_node(int num) {
    t_btree *tmp = (t_btree *)malloc(sizeof(t_btree));
    if (tmp != NULL) {
        tmp->item = num;
        tmp->left = NULL;
        tmp->right = NULL;
    }
    return tmp;
}

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    t_btree *leaf = bstree_create_node(item);
    if (leaf != NULL) {
        int flag = 1;
        while (flag) {
            if (cmpf(item, root->item) == -1) {
                if (root->left != NULL) {
                    root = root->left;
                } else {
                    root->left = leaf;
                    flag = 0;
                }
            } else if (cmpf(item, root->item) == 1) {
                if (root->right != NULL) {
                    root = root->right;
                } else {
                    root->right = leaf;
                    flag = 0;
                }
            } else {
                flag = 0;
                free(leaf);
            }
        }
    }
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        bstree_apply_infix(root->left, apply_function);
        applyf(root->item);
        bstree_apply_infix(root->right, apply_function);
    }
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        applyf(root->item);
        bstree_apply_prefix(root->left, apply_function);
        bstree_apply_prefix(root->right, apply_function);
    }
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        bstree_apply_postfix(root->left, apply_function);
        bstree_apply_postfix(root->right, apply_function);
        applyf(root->item);
    }
}

void bstree_delete(t_btree *root) {
    if (root != NULL) {
        bstree_delete(root->left);
        bstree_delete(root->right);
        free(root);
    }
}

int compare(int num1, int num2) {
    int res = 0;
    if (num1 < num2) {
        res = -1;
    } else if (num1 > num2) {
        res = 1;
    } else {
        res = 0;
    }
    return res;
}

void apply_function(int num) { printf("%d ", num); }