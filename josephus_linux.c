#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to eliminate a person from the circle
void eliminate_person(int *circle, int n, int *size) {
    int index = 0;        // The current position in the circle
    int eliminated = 0;    // To keep track of eliminations

    while (*size > 1) {   // Continue until only one person remains
        // Find the next valid person (not eliminated)
        while (circle[index] == -1) {
            index = (index + 1) % n; // Skip eliminated people
        }

        // Every second person is eliminated
        if (++eliminated == 2) {
            pid_t pid = fork(); // Create a new child process
            if (pid == 0) { // Child process does the elimination
                printf("Eliminated: %d\n", circle[index]);
                exit(0); // Child exits after printing the elimination
            } else { // Parent waits for the child to finish
                wait(NULL); // Wait until child finishes
                circle[index] = -1; // Mark the person as eliminated
                (*size)--; // Reduce the number of people
            }
            eliminated = 0; // Reset the elimination counter
        }

        // Move to the next person in the circle
        index = (index + 1) % n;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_people>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Number of people must be greater than 0.\n");
        return 1;
    }

    int *circle = malloc(n * sizeof(int)); // Allocate memory for the circle
    int size = n;

    // Initialize the circle with people numbered 1 to n
    for (int i = 0; i < n; i++) {
        circle[i] = i + 1;
    }

    eliminate_person(circle, n, &size); // Eliminate people in the circle

    // Find and print the last remaining person (the survivor)
    for (int i = 0; i < n; i++) {
        if (circle[i] != -1) { // The last remaining person is the survivor
            printf("Survivor: %d\n", circle[i]);
            break;
        }
    }

    free(circle); // Free the allocated memory
    return 0;
}
