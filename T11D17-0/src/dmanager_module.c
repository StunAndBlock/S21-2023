#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void sort_doors(struct door* doors, int first, int last);
void output(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort_doors(doors, 0, DOORS_COUNT - 1);
    output(doors);
    return 0;
}

void initialize_doors(struct door* doors) {
    srand(time(0));
    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort_doors(struct door* doors, int first, int last) {
    if (first < last) {
        int pivot = first;
        int i = first;
        int j = last;
        int temp = 0;
        while (i < j) {
            while (i < last && doors[i].id <= doors[pivot].id) i++;
            while (doors[j].id > doors[pivot].id) j--;
            if (i < j) {
                temp = doors[i].id;
                doors[i].id = doors[j].id;
                doors[j].id = temp;
            }
        }
        temp = doors[pivot].id;
        doors[pivot].id = doors[j].id;
        doors[j].id = temp;
        sort_doors(doors, first, j - 1);
        sort_doors(doors, j + 1, last);
    }
}

void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT - 1; i++) {
        doors[i].status = 0;
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }
    doors[DOORS_COUNT - 1].status = 0;
    printf("%d, %d", doors[DOORS_COUNT - 1].id, doors[DOORS_COUNT - 1].status);
}