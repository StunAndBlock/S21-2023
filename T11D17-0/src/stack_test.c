#include "stack.h"

#include <stdio.h>

Node* stack_tests(Node* top);

int main() {
    int first_num = 1;
    Node* top = init(first_num);
    if (top == NULL) {
        return 1;
    }
    top = stack_tests(top);
    destroy(top);
    return 0;
}

Node* stack_tests(Node* top) {
    int num1 = 2;
    int num2 = 3;
    printf("TEST-1 ... \n");
    top = push(num1, top);
    if (top != NULL && top->num == 2 && top->prev->num == 1) {
        printf("\tSUCCESS\n");
    } else {
        printf("\tFAIL\n");
    }
    printf("TEST-2 ... \n");
    top = push(num2, top);
    if (top != NULL && top->num == 3 && top->prev->num == 2) {
        printf("\tSUCCESS\n");
    } else {
        printf("\tFAIL\n");
    }
    printf("TEST-3 ... \n");
    top = pop(top);
    if (top != NULL && top->num == 2 && top->prev->num == 1) {
        printf("\tSUCCESS\n");
    } else {
        printf("\tFAIL\n");
    }
    return top;
}