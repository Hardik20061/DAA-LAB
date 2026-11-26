/*
 * Question 23: Move all even integers to the beginning of the array followed by odd integers.
 * Approach: Two-Pointer Converging Partition (In-Place)
 * Time Complexity: O(n) - Each element is checked at most once.
 * Space Complexity: O(1) - No auxiliary data structures used.
 */
#include <stdio.h>

void sortArrayByParity(int nums[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        // Move left pointer forward if it is already even
        if (nums[left] % 2 == 0) {
            left++;
        }
        // Move right pointer backward if it is already odd
        else if (nums[right] % 2 != 0) {
            right--;
        }
        // Left is odd and right is even -> swap them
        else {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
}

int main() {
    int nums[] = {3, 1, 2, 4, 7, 6};
    int n = sizeof(nums) / sizeof(nums[0]);

    sortArrayByParity(nums, n);

    printf("Array after parity partition: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
