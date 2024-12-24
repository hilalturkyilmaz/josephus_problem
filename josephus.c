#include <stdio.h>

// Function to calculate the survivor's position in the Josephus problem
// n - total number of people in the circle
// k - the interval (i.e., every k-th person is eliminated)
int josephus(int n, int k) {
  int i, temp = 0; // temp keeps track of the current position of the survivor

  // Loop through all the people (1 to n)
  for(i = 1; i <= n; i++) {
    // Update the position of the survivor using the Josephus recurrence relation
    // (temp + k) % i gives the new position in a circle of size i
    temp = (temp + k) % i;
  }

  // Return the survivor's position (adding 1 to convert from 0-based to 1-based indexing)
  return temp + 1;
}

int main() {
  int n, k = 2; // n is the number of people, k is the interval (fixed to 2)

  printf("How many people are in the circle: ");
  scanf("%d", &n);

  printf("Survivor: %d\n", josephus(n, k));

  return 0;
}
