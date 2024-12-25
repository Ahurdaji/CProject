#ifndef TRAIN_H
#define TRAIN_H

#include "vagon.h" // Include Wagon definition

typedef struct Train {
    char train_id[20];         // Unique identifier for the train
    struct Wagon *first_wagon; // Pointer to the first wagon
    int wagon_count;           // Total number of wagons
} Train;

// Function prototypes
Train *create_train(const char *id);      // Create a train
void add_wagon_to_train(Train *train);   // Add a new wagon to the train
void remove_wagon_from_train(Train *train); // Remove the last wagon
void display_train_status(const Train *train); // Display train and wagon details
void free_train(Train *train);           // Free all memory used by the train

#endif // TRAIN_H
