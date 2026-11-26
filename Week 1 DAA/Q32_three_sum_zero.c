/*
 * Question 32: Find unique triplets in an array whose sum is 0.
 * Approach: Sort + Two Pointers with Duplicate Skipping
 * Time Complexity: O(n^2) - Sorting takes O(n log n), nested two-pointer loop takes O(n^2).
 * Space Complexity: O(1) - Ignoring output printing space.
 */
#include <stdio.h>
#include <stdlib.h>

int cmpInt(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void threeSum(int nums[], int n) {
    qsort(nums, n, sizeof(int), cmpInt);

    printf("Unique triplets summing to 0:\n");
    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                printf("%d %d %d\n", nums[i], nums[left], nums[right]);

                // Skip duplicate values for left and right pointers
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
}

int main() {
    int arr[] = {2, 0, 3, -2, -1, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    threeSum(arr, n);
    return 0;
}
