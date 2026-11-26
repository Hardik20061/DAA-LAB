/*
 * Question 34: Find the integer square root of a non-negative number without sqrt().
 * Approach: Binary Search
 * Time Complexity: O(log n) - Halves search range at every iteration.
 * Space Complexity: O(1) - Constant space.
 */
#include <stdio.h>

int mySqrt(int x) {
    if (x < 0) return -1; // Invalid for negative numbers
    if (x == 0 || x == 1) return x;

    long long left = 1;
    long long right = x / 2;
    int ans = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;

        if (square == x) {
            return (int)mid;
        } else if (square < x) {
            ans = (int)mid; // Store closest floor value
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    int num = 28;
    printf("Integer square root of %d is: %d\n", num, mySqrt(num));
    return 0;
}
