#include "../include/vagon.h"
#include <stdio.h>
#include <stdlib.h>

Wagon *create_wagon(int id) {
    Wagon *new_wagon = (Wagon *)malloc(sizeof(Wagon));
    if (!new_wagon) {
        printf("Error: Memory allocation failed for wagon.\n");
        return NULL;
    }
    new_wagon->wagon_id = id;
    new_wagon->max_weight = 1000.0; // Assume 1000 kg max weight
    new_wagon->current_weight = 0.0; // Initially empty
    new_wagon->next = NULL;
    new_wagon->prev = NULL;
    return new_wagon;
}

void display_wagon(const Wagon *wagon) {
    if (!wagon) return;

    printf("Wagon ID: %d\n", wagon->wagon_id);
    printf("  Max Weight: %.2f\n", wagon->max_weight);
    printf("  Current Weight: %.2f\n", wagon->current_weight);
}

void free_wagon(Wagon *wagon) {
    if (!wagon) return;

    free(wagon);
}
