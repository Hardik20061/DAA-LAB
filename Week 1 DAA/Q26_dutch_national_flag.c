/*
 * Question 26: Implement the Dutch National Flag Algorithm (Sort 0s, 1s, and 2s).
 * Approach: Three-Pointer Partitioning (low, mid, high)
 * Time Complexity: O(n) - Single pass through the array.
 * Space Complexity: O(1) - In-place sorting.
 *
 * Real-World Case Studies:
 * 1. Quicksort Optimization (3-Way Partitioning): Handles arrays with many duplicate
 *    elements efficiently by grouping equal elements in the middle.
 * 2. Task/Packet Prioritization: Segregating network packets or OS threads into
 *    High (0), Medium (1), and Low (2) priority queues in a single pass.
 * 3. E-Commerce Inventory/Status Filtering: Grouping items into "In Stock",
 *    "Low Stock", and "Out of Stock" without full sorting overhead.
 */
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void dutchNationalFlag(int arr[], int n) {
    int low = 0;       // Boundary for 0s
    int mid = 0;       // Current element under inspection
    int high = n - 1;  // Boundary for 2s

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(&arr[low], &arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else { // arr[mid] == 2
            swap(&arr[mid], &arr[high]);
            high--;
            // Do not increment mid here because swapped element from high is uninspected
        }
    }
}

int main() {
    int arr[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    dutchNationalFlag(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
