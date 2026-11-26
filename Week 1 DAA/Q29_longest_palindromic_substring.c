/*
 * Question 29: Find the longest contiguous palindromic substring within a string.
 * Approach: Expand Around Center (handles both odd and even length palindromes)
 * Time Complexity: O(n^2) - n centers, each expanding up to O(n).
 * Space Complexity: O(1) - Uses only index variables.
 */
#include <stdio.h>
#include <string.h>

// Helper function to expand outward while characters match
int expandAroundCenter(char *s, int left, int right, int n) {
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    // Length of palindrome is (right - 1) - (left + 1) + 1 = right - left - 1
    return right - left - 1;
}

void longestPalindrome(char *s) {
    int n = strlen(s);
    if (n == 0) return;

    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        int len1 = expandAroundCenter(s, i, i, n);     // Odd length (e.g., "aba")
        int len2 = expandAroundCenter(s, i, i + 1, n); // Even length (e.g., "abba")
        int len = (len1 > len2) ? len1 : len2;

        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2;
        }
    }

    printf("Longest Palindromic Substring: ");
    for (int i = start; i < start + maxLen; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
}

int main() {
    char str[] = "babad";
    printf("Input: %s\n", str);
    longestPalindrome(str);
    return 0;
}
