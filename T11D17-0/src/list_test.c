#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

#define N 10

void list_tests(struct node* root, struct door* test_door1, struct door* test_door2, struct door* test_door3);

int main() {
    int error = 0;
    struct door* door = (struct door*)malloc(sizeof(struct door));
    if (door == NULL) {
        error = 1;
    }
    struct node* root;
    if (!error) {
        door->id = 1;
        root = init(door);
        if (root == NULL) {
            error = 1;
        }
    }
    if (!error) {
        struct door* test_door1 = (struct door*)malloc(sizeof(struct door));
        struct door* test_door2 = (struct door*)malloc(sizeof(struct door));
        struct door* test_door3 = (struct door*)malloc(sizeof(struct door));
        list_tests(root, test_door1, test_door2, test_door3);
        destroy(root);
    }
    return error;
}

void list_tests(struct node* root, struct door* test_door1, struct door* test_door2,
                struct door* test_door3) {
    printf("TEST-1 ... ");
    test_door1->id = 2;
    struct node* tmp1 = add_door(root, test_door1);
    if (tmp1 != NULL) {
        printf("%d\n", tmp1->data->id);
        if (find_door(2, root) == tmp1) {
            printf("\tSUCCESS\n");
        } else {
            printf("\tFAIL\n");
        }
    }
    printf("TEST-2 ... ");
    test_door2->id = 3;
    struct node* tmp2 = add_door(tmp1, test_door2);
    if (tmp2 != NULL) {
        printf("%d\n", tmp2->data->id);
        if (find_door(3, root) == tmp2) {
            printf("\tSUCCESS\n");
        } else {
            printf("\tFAIL\n");
        }
    }
    printf("TEST-3 ... ");
    test_door3->id = 4;
    struct node* tmp3 = add_door(tmp2, test_door3);
    if (tmp3 != NULL) {
        printf("%d\n", tmp3->data->id);
        if (find_door(4, root) == tmp3) {
            printf("\tSUCCESS\n");
        } else {
            printf("\tFAIL\n");
        }
    }
    printf("TEST-4 ... ");
    struct node* tmp4 = remove_door(tmp2, root);
    if (tmp4 != NULL) {
        printf("%d\n", tmp4->data->id);
        if (tmp4 == tmp1) {
            printf("\tSUCCESS");
        } else {
            printf("\tFAIL");
        }
    }
}