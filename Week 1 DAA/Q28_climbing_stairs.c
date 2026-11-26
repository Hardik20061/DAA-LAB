/*
 * Question 28: Climb n steps taking 1 or 2 steps at a time. Find total distinct ways.
 * Approach: Space-Optimized Dynamic Programming (Fibonacci pattern)
 * Time Complexity: O(n) - Single loop up to n.
 * Space Complexity: O(1) - Uses only two variables instead of a DP array.
 */
#include <stdio.h>

int climbStairs(int n) {
    if (n <= 2) return n;

    int twoStepsBefore = 1; // Ways to reach step 1
    int oneStepBefore = 2;  // Ways to reach step 2
    int currentWays = 0;

    for (int i = 3; i <= n; i++) {
        currentWays = oneStepBefore + twoStepsBefore;
        twoStepsBefore = oneStepBefore;
        oneStepBefore = currentWays;
    }

    return currentWays;
}

int main() {
    int n = 5;
    printf("Distinct ways to climb %d stairs: %d\n", n, climbStairs(n));
    return 0;
}
