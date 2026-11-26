/*
 * Question 30: Find the smallest missing positive integer in an unsorted array.
 * 1. Normal Approach (Linear Search for each positive integer 1..n+1):
 *    Time Complexity: O(n^2)
 *    Space Complexity: O(1)
 * 2. Optimized Approach (Cyclic Sort / Index Hashing):
 *    Time Complexity: O(n)
 *    Space Complexity: O(1)
 */
#include <stdio.h>

// 1. Normal Approach: O(n^2) Time, O(1) Space
int firstMissingPositiveNormal(int nums[], int n) {
    for (int target = 1; target <= n + 1; target++) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                found = 1;
                break;
            }
        }
        if (!found) return target;
    }
    return n + 1;
}

// 2. Optimized Approach (Cyclic Sort): O(n) Time, O(1) Space
int firstMissingPositiveOptimized(int nums[], int n) {
    // Place every number x (where 1 <= x <= n) at index x - 1
    for (int i = 0; i < n; i++) {
        while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            int correctIdx = nums[i] - 1;
            int temp = nums[i];
            nums[i] = nums[correctIdx];
            nums[correctIdx] = temp;
        }
    }

    // The first index i where nums[i] != i + 1 gives the missing positive
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}

int main() {
    int arr1[] = {3, 4, -1, 1};
    int arr2[] = {3, 4, -1, 1};
    int n = 4;

    printf("Normal Output:    %d\n", firstMissingPositiveNormal(arr1, n));
    printf("Optimized Output: %d\n", firstMissingPositiveOptimized(arr2, n));
    return 0;
}
