#ifndef VAGON_H
#define VAGON_H

typedef struct Wagon {
    int wagon_id;              // Unique ID for the wagon
    float max_weight;          // Maximum weight capacity
    float current_weight;      // Current weight
    struct Wagon *next;        // Pointer to the next wagon
    struct Wagon *prev;        // Pointer to the previous wagon
} Wagon;

// Function prototypes
Wagon *create_wagon(int id);              // Create a wagon with a given ID
void display_wagon(const Wagon *wagon);  // Display details of a single wagon
void free_wagon(Wagon *wagon);           // Free memory used by a wagon

#endif // VAGON_H
