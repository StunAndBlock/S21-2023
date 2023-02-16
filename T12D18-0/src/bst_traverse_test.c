#include <stdio.h>

#include "bst.h"

int main() {
    int items[10] = {8, 3, 1, 14, 6, 14, 4, 7, 13, 1};
    t_btree *root = bstree_create_node(items[0]);
    if (root) {
        for (int i = 1; i < 10; i++) {
            bstree_insert(root, items[i], compare);
        }
    }
    printf("Input data: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", items[i]);
    }
    printf("\nTEST-1 ... \n");
    bstree_apply_infix(root, apply_function);
    printf("\n\tSUCCESS\nTEST-2 ... \n");
    bstree_apply_prefix(root, apply_function);
    printf("\n\tSUCCESS\nTEST-3 ... \n");
    bstree_apply_postfix(root, apply_function);
    putchar('\n');
    bstree_delete(root);
    return 0;
}