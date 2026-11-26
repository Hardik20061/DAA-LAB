/*
 * Question 24: Find a peak element (strictly greater than its neighbors) and return its index.
 * Approach: Binary Search
 * Time Complexity: O(log n) - Search space halves at every step.
 * Space Complexity: O(1) - Iterative binary search uses constant extra memory.
 */
#include <stdio.h>

int findPeakElement(int nums[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If mid is smaller than its next neighbor, a peak must exist on the right side
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        }
        // Otherwise, a peak exists on the left side (including mid)
        else {
            right = mid;
        }
    }
    // When left == right, we have converged on a peak index
    return left;
}

int main() {
    int nums[] = {1, 2, 1, 3, 5, 6, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    int peakIdx = findPeakElement(nums, n);
    printf("Peak element %d found at index %d\n", nums[peakIdx], peakIdx);
    return 0;
}
