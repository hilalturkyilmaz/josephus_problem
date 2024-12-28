#include <stdio.h>
#include <stdbool.h>

// Function to calculate the survivor's position and print the eliminated people in the Josephus problem
// n - total number of people in the circle
// k - the interval (i.e., every k-th person is eliminated)
int josephus(int n, int k) {
    int people[n];  // Array to represent people in the circle
    bool eliminated[n];  // Array to mark eliminated people
    int remaining = n;  // Track the number of remaining people
    int i, idx = 0;  // Index for elimination

    // Initialize the people and elimination status arrays
    for (i = 0; i < n; i++) {
        people[i] = i + 1;  // Assign each person a number (1 to n)
        eliminated[i] = false;  // No one is eliminated initially
    }

    while (remaining > 1) {
        // Find the next person to eliminate
        int count = 0;
        while (count < k) {
            // Only consider people who have not been eliminated
            if (!eliminated[idx % n]) {
                count++;
            }
            if (count < k) {
                idx++;
            }
        }

        // Eliminate the person at the current index
        eliminated[idx % n] = true;
        printf("Eliminated: %d\n", people[idx % n]);  // Print the eliminated person with the required format
        remaining--;  // Decrease the number of remaining people
        idx++;  // Move to the next person
    }

    // Find and return the position of the last remaining person (the survivor)
    for (i = 0; i < n; i++) {
        if (!eliminated[i]) {
            return people[i];
        }
    }

    return -1;  // This should never happen
}

int main() {
    int n, k = 2;  // n is the number of people, k is the interval (fixed to 2)

    printf("How many people are in the circle: ");
    scanf("%d", &n);

    printf("Survivor: %d\n", josephus(n, k));

    return 0;
}

