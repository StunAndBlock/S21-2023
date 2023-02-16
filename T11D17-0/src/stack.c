#include "stack.h"

#include <stdlib.h>

Node* init(int number) {
    Node* top = (Node*)malloc(sizeof(Node));
    top->num = number;
    top->prev = NULL;
    return top;
}

Node* push(int number, Node* top) {
    Node* tmp = NULL;
    if (top != NULL) {
        tmp = (Node*)malloc(sizeof(Node));
        if (tmp != NULL) {
            tmp->num = number;
            tmp->prev = top;
        }
    }
    return tmp;
}

Node* pop(Node* top) {
    Node* tmp = NULL;
    if (top != NULL) {
        tmp = top->prev;
        free(top);
    }
    return tmp;
}

void destroy(Node* top) {
    if (top != NULL) {
        while (top->prev != NULL) {
            Node* tmp = top->prev;
            free(top);
            top = tmp;
        }
    }
    free(top);
}