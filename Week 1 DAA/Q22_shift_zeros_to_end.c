/*
 * Question 22: Shift all zeros to the end of an array.
 * 1. Normal Code (Auxiliary Array):
 *    Time Complexity: O(n)
 *    Space Complexity: O(n) - Uses an extra temporary array.
 * 2. Optimal Code (Two-Pointer In-Place):
 *    Time Complexity: O(n)
 *    Space Complexity: O(1) - Modifies array in-place without extra memory.
 */
#include <stdio.h>
#include <stdlib.h>

// 1. Normal Code using auxiliary array
void shiftZerosNormal(int arr[], int n) {
    int *temp = (int *)calloc(n, sizeof(int)); // Initialized to all 0s
    int j = 0;

    // Copy all non-zero elements in original order
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            temp[j++] = arr[i];
        }
    }

    // Copy back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
    free(temp);
}

// 2. Optimal Code using Two Pointers
void shiftZerosOptimal(int arr[], int n) {
    int nonZeroPos = 0; // Tracks position for next non-zero element

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            // Swap current non-zero element with element at nonZeroPos
            int temp = arr[nonZeroPos];
            arr[nonZeroPos] = arr[i];
            arr[i] = temp;
            nonZeroPos++;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr1[] = {0, 1, 0, 3, 12};
    int arr2[] = {0, 1, 0, 3, 12};
    int n = 5;

    shiftZerosNormal(arr1, n);
    printf("Normal Output:  ");
    printArray(arr1, n);

    shiftZerosOptimal(arr2, n);
    printf("Optimal Output: ");
    printArray(arr2, n);

    return 0;
}
