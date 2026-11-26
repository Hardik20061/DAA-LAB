/*
 * Question 20: Print the longest substring without repeating a character.
 * Approach: Sliding Window using an ASCII last-seen index array.
 * Time Complexity: O(n) - Each character is visited at most once.
 * Space Complexity: O(1) - Fixed array of size 256 for extended ASCII.
 */
#include <stdio.h>
#include <string.h>

void longestUniqueSubstring(char *str) {
    int n = strlen(str);
    int lastIndex[256];
    
    // Initialize all character positions as -1 (not seen yet)
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    int maxLen = 0;
    int start = 0;      // Current window start
    int bestStart = 0;  // Start index of the longest substring found

    for (int end = 0; end < n; end++) {
        unsigned char currentChar = str[end];

        // If currentChar was seen inside the current window, shrink from the left
        if (lastIndex[currentChar] >= start) {
            start = lastIndex[currentChar] + 1;
        }

        // Update the last seen position of the current character
        lastIndex[currentChar] = end;

        // Check if we found a new longest window
        if (end - start + 1 > maxLen) {
            maxLen = end - start + 1;
            bestStart = start;
        }
    }

    printf("Length: %d\nSubstring: ", maxLen);
    for (int i = bestStart; i < bestStart + maxLen; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    char str[] = "abcabcbb";
    printf("Input: %s\n", str);
    longestUniqueSubstring(str);
    return 0;
}
