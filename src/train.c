#include "../include/train.h"
#include "../include/vagon.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Train *create_train(const char *id) {
    Train *new_train = (Train *)malloc(sizeof(Train));
    if (!new_train) {
        printf("Error: Memory allocation failed for train.\n");
        return NULL;
    }
    strcpy(new_train->train_id, id);
    new_train->first_wagon = NULL;
    new_train->wagon_count = 0;
    return new_train;
}

void add_wagon_to_train(Train *train) {
    if (!train) return;

    Wagon *new_wagon = create_wagon(train->wagon_count + 1);
    if (!new_wagon) return;

    if (!train->first_wagon) {
        train->first_wagon = new_wagon;
    } else {
        Wagon *current = train->first_wagon;
        while (current->next) {
            current = current->next;
        }
        current->next = new_wagon;
        new_wagon->prev = current;
    }
    train->wagon_count++;
}

void remove_wagon_from_train(Train *train) {
    if (!train || !train->first_wagon) return;

    Wagon *current = train->first_wagon;
    while (current->next) {
        current = current->next;
    }

    if (current->prev) {
        current->prev->next = NULL;
    } else {
        train->first_wagon = NULL;
    }

    free_wagon(current);
    train->wagon_count--;
}
 
void display_train_status(const Train *train) {
    if (!train) return;

    printf("Train ID: %s\n", train->train_id);
    printf("Number of Wagons: %d\n", train->wagon_count);

    Wagon *current = train->first_wagon;
    while (current) {
        display_wagon(current);
        current = current->next;
    }
}

void free_train(Train *train) {
    if (!train) return;

    Wagon *current = train->first_wagon;
    while (current) {
        Wagon *next = current->next;
        free_wagon(current);
        current = next;
    }

    free(train);
}
