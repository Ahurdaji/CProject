#include "../include/train.h"
#include <stdio.h>

int main() {
    // Create a train
    Train *train = create_train("T123");

    // Add wagons
    add_wagon_to_train(train);
    add_wagon_to_train(train);

    // Display train status
    display_train_status(train);

    // Remove a wagon
    remove_wagon_from_train(train);

    // Display train status again
    display_train_status(train);

    // Free memory
    free_train(train);
    return 0;
}
