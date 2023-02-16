#include <stdio.h>

#include "bst.h"

int main() {
    int item1 = 0;
    t_btree *root = bstree_create_node(item1);
    if (root != NULL) {
        puts("TEST-1 ... ");
        int item2 = -1;
        printf("Root:\n\t%d\n", root->item);
        bstree_insert(root, item2, compare);
        printf("Input: %d\n", item2);
        puts("Output:");
        printf("\t%d\n", root->item);
        if (root->left != NULL) {
            printf("%d\t\t-\n", root->left->item);
            if (root->left->item == item2 && root->right == NULL) {
                puts("\tSUCCESS");
            } else {
                puts("\tFAIL");
            }
        }
        puts("TEST-2 ... ");
        int item3 = 1;
        printf("Root:\n\t%d\n", root->item);
        if (root->left != NULL) {
            printf("%d\t\t-\n", root->left->item);
        }
        bstree_insert(root, item3, compare);
        printf("Input: %d\n", item3);
        puts("Output:");
        printf("\t%d\n", root->item);
        if (root->left != NULL && root->right != NULL) {
            printf("%d\t\t%d\n", root->left->item, root->right->item);
            if (root->right->item == item3) {
                puts("\tSUCCESS");
            } else {
                puts("\tFAIL");
            }
        }
        puts("TEST-3 ... ");
        int item4 = 2;
        printf("Root:\n\t%d\n", root->item);
        if (root->left != NULL && root->right != NULL) {
            printf("%d\t\t%d\n", root->left->item, root->right->item);
        }
        bstree_insert(root, item4, compare);
        printf("Input: %d\n", item4);
        puts("Output:");
        printf("\t%d\n", root->item);
        if (root->left != NULL && root->right != NULL && root->right->right != NULL) {
            printf("%d\t\t%d\n\t-\t\t%d\n", root->left->item, root->right->item, root->right->right->item);

            if (root->right->right->item == item4) {
                puts("\tSUCCESS");
            } else {
                puts("\tFAIL");
            }
            free(root->right->right);
            free(root->right);
            free(root->left);
            free(root);
        }
    }
    return 0;
}