#include "list.h"

#include <stdlib.h>

#include "door_struct.h"

struct node* init(struct door* door) {
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = door;
    root->next = NULL;
    return root;
}

struct node* add_door(struct node* elem, struct door* door) {
    int error = 0;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        error = 1;
    }
    if (!error) {
        struct node* tmp = elem->next;
        elem->next = new_node;
        new_node->next = tmp;
        new_node->data = door;
    }
    return new_node;
}

struct node* find_door(int door_id, struct node* root) {
    int error = 0;
    struct node* res = root;
    if (root == NULL) {
        error = 1;
    }
    if (!error) {
        while (res != NULL && res->data->id != door_id) {
            res = res->next;
        }
    }
    return res;
}

struct node* remove_door(struct node* elem, struct node* root) {
    int error = 0;
    if (root == NULL || elem == NULL) {
        root = NULL;
        error = 1;
    }
    if (!error) {
        while (root->next != elem && root->next != NULL) {
            root = root->next;
        }
        if (root->next == elem) {
            free(root->next->data);
            free(root->next);
            root->next = elem->next;
        } else {
            root = NULL;
        }
    }
    return root;
}

void destroy(struct node* root) {
    int error = 0;
    if (root == NULL) {
        error = 1;
    }
    if (!error) {
        while (root != NULL) {
            struct node* tmp = root->next;
            free(root->data);
            free(root);
            root = tmp;
        }
    }
}