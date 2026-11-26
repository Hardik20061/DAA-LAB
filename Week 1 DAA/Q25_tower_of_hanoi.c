/*
 * Question 25: Implementation of Tower of Hanoi problem.
 * Approach: Recursion
 * Time Complexity: O(2^n) - Total moves required is (2^n - 1).
 * Space Complexity: O(n) - Maximum depth of the recursion call stack is n.
 */
#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Base case: Only 1 disk left to move
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Step 1: Move top n-1 disks from source to auxiliary using destination
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Step 2: Move the nth (largest) disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Step 3: Move the n-1 disks from auxiliary to destination using source
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int numDisks = 3;
    printf("Tower of Hanoi steps for %d disks:\n", numDisks);
    towerOfHanoi(numDisks, 'A', 'B', 'C');
    return 0;
}
