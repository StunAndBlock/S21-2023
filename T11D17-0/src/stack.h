#ifndef STACK_H
#define STACK_H

typedef struct Node {
    int num;
    struct Node* prev;
} Node;

Node* init(int number);
Node* push(int number, Node* top);
Node* pop(Node* top);
void destroy(Node* top);

#endif