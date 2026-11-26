/*
 * Question 27: Find the first available spot (0) in a 2D mall parking layout and park the car (mark as 1).
 * Time Complexity: O(R * C) - Where R is rows and C is columns (worst case checks all spots).
 * Space Complexity: O(1) - Operates directly on the existing 2D grid.
 */
#include <stdio.h>

#define ROWS 3
#define COLS 4

void parkCar(int lot[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (lot[r][c] == 0) {
                lot[r][c] = 1; // Park the car
                printf("Car parked at Row %d, Column %d.\n", r, c);
                return;
            }
        }
    }
    printf("Parking Full! No available spots.\n");
}

void displayLot(int lot[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%d ", lot[r][c]);
        }
        printf("\n");
    }
}

int main() {
    int parkingLot[ROWS][COLS] = {
        {1, 1, 1, 1},
        {1, 0, 1, 0},
        {0, 0, 1, 1}
    };

    printf("Initial Parking Lot:\n");
    displayLot(parkingLot);

    parkCar(parkingLot);

    printf("Updated Parking Lot:\n");
    displayLot(parkingLot);

    return 0;
}
