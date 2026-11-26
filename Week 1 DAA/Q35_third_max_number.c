/*
 * Question 35: Find the third maximum distinct number in an array.
 * Constraints:
 *   - Time complexity must be better than O(n log n) -> Achieved O(n).
 *   - Duplicate elements count as one entity.
 *   (Note: If fewer than 3 distinct numbers exist, returns the overall maximum).
 * Space Complexity: O(1) - Tracks top 3 distinct values using 3 variables.
 */
#include <stdio.h>
#include <limits.h>

int thirdMax(int nums[], int n) {
    // Use long long min so INT_MIN inside the array is handled accurately
    long long first = LLONG_MIN;
    long long second = LLONG_MIN;
    long long third = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        int current = nums[i];

        // Skip duplicate values
        if (current == first || current == second || current == third) {
            continue;
        }

        if (current > first) {
            third = second;
            second = first;
            first = current;
        } else if (current > second) {
            third = second;
            second = current;
        } else if (current > third) {
            third = current;
        }
    }

    // If third maximum does not exist, return the maximum (first)
    return (third == LLONG_MIN) ? (int)first : (int)third;
}

int main() {
    int arr[] = {2, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Third distinct maximum: %d\n", thirdMax(arr, n));
    return 0;
}
