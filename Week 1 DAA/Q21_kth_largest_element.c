/*
 * Question 21: Find the kth largest element in an array.
 * Includes:
 *   1. With Sorting (qsort) -> Time: O(n log n), Space: O(1)
 *   2. Without Sorting (Repeated Max Extraction) -> Time: O(n * k), Space: O(n)
 *   3. Optimal Approach (QuickSelect / Hoare's Selection) -> Time: O(n) average, O(n^2) worst; Space: O(1)
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Helper comparator for qsort (Descending order)
int compareDesc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// 1. WITH SORTING: Time O(n log n), Space O(1)
int kthLargestSorting(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), compareDesc);
    return arr[k - 1];
}

// 2. WITHOUT SORTING: Time O(n * k), Space O(n)
int kthLargestWithoutSorting(int arr[], int n, int k) {
    int *visited = (int *)calloc(n, sizeof(int));
    int kthMax = INT_MIN;

    for (int count = 0; count < k; count++) {
        int maxVal = INT_MIN;
        int maxIdx = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && arr[i] > maxVal) {
                maxVal = arr[i];
                maxIdx = i;
            }
        }
        visited[maxIdx] = 1;
        kthMax = maxVal;
    }
    free(visited);
    return kthMax;
}

// 3. OPTIMAL (QuickSelect): Time O(n) average, Space O(1)
int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left;
    for (int j = left; j < right; j++) {
        // Place elements larger than pivot to the left
        if (arr[j] >= pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    int temp = arr[i];
    arr[i] = arr[right];
    arr[right] = temp;
    return i;
}

int kthLargestOptimal(int arr[], int left, int right, int k) {
    while (left <= right) {
        int pivotIdx = partition(arr, left, right);
        if (pivotIdx == k - 1) {
            return arr[pivotIdx];
        } else if (pivotIdx > k - 1) {
            right = pivotIdx - 1;
        } else {
            left = pivotIdx + 1;
        }
    }
    return -1;
}

int main() {
    int arr1[] = {3, 2, 1, 5, 6, 4};
    int arr2[] = {3, 2, 1, 5, 6, 4};
    int arr3[] = {3, 2, 1, 5, 6, 4};
    int n = 6, k = 2;

    printf("1. With Sorting: %d\n", kthLargestSorting(arr1, n, k));
    printf("2. Without Sorting: %d\n", kthLargestWithoutSorting(arr2, n, k));
    printf("3. Optimal (QuickSelect): %d\n", kthLargestOptimal(arr3, 0, n - 1, k));
    return 0;
}
