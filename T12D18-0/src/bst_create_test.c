#include <stdio.h>

#include "bst.h"

int main() {
    puts("TEST-1 ... ");
    int item1 = 1;
    printf("Input: %d\n", item1);
    t_btree *tmp1 = bstree_create_node(item1);
    if (tmp1 != NULL) {
        printf("Output: %d\n", tmp1->item);
        if (tmp1->item == item1) {
            puts("\tSUCCESS");
        } else {
            puts("\tFAIL");
        }
        free(tmp1);
    }
    puts("TEST-2 ... ");
    int item2 = 2;
    printf("Input: %d\n", item2);
    t_btree *tmp2 = bstree_create_node(item2);
    if (tmp1 != NULL) {
        printf("Output: %d\n", tmp2->item);
        if (tmp2->item == item2) {
            puts("\tSUCCESS");
        } else {
            puts("\tFAIL");
        }
        free(tmp2);
    }
    puts("TEST-2 ... ");
    int item3 = 3;
    printf("Input: %d\n", item3);
    t_btree *tmp3 = bstree_create_node(item3);
    if (tmp1 != NULL) {
        printf("Output: %d\n", tmp3->item);
        if (tmp3->item == item3) {
            printf("\tSUCCESS");
        } else {
            printf("\tFAIL");
        }
        free(tmp3);
    }
    return 0;
}