/*
 * Question 31: Find all start indices of pattern p's anagrams in string s.
 * 1. Normal Code (Sorting each substring window):
 *    Time Complexity: O((N - M + 1) * M log M)
 *    Space Complexity: O(M)
 * 2. Optimized Code (Sliding Window + Frequency Array):
 *    Time Complexity: O(N) - Constant 26-char comparison per step.
 *    Space Complexity: O(1) - Fixed arrays of size 26.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charCmp(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

// 1. Normal Approach: Sort pattern and every window of length M
void findAnagramsNormal(char *s, char *p) {
    int n = strlen(s);
    int m = strlen(p);
    if (n < m) return;

    char *sortedP = (char *)malloc(m + 1);
    strcpy(sortedP, p);
    qsort(sortedP, m, sizeof(char), charCmp);

    char *window = (char *)malloc(m + 1);
    printf("Normal Anagram Indices:    ");
    for (int i = 0; i <= n - m; i++) {
        strncpy(window, s + i, m);
        window[m] = '\0';
        qsort(window, m, sizeof(char), charCmp);
        if (strcmp(sortedP, window) == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
    free(sortedP);
    free(window);
}

// Helper to compare two 26-element frequency arrays
int areFreqEqual(int a[26], int b[26]) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

// 2. Optimized Approach: Sliding Window with Frequency Count
void findAnagramsOptimized(char *s, char *p) {
    int n = strlen(s);
    int m = strlen(p);
    if (n < m) return;

    int pCount[26] = {0};
    int sCount[26] = {0};

    // Build initial frequency maps for p and the first window of s
    for (int i = 0; i < m; i++) {
        pCount[p[i] - 'a']++;
        sCount[s[i] - 'a']++;
    }

    printf("Optimized Anagram Indices: ");
    if (areFreqEqual(pCount, sCount)) {
        printf("0 ");
    }

    // Slide the window across s
    for (int i = m; i < n; i++) {
        sCount[s[i] - 'a']++;       // Add new incoming character
        sCount[s[i - m] - 'a']--;   // Remove outgoing character

        if (areFreqEqual(pCount, sCount)) {
            printf("%d ", i - m + 1);
        }
    }
    printf("\n");
}

int main() {
    char s[] = "cbaebabacd";
    char p[] = "abc";

    findAnagramsNormal(s, p);
    findAnagramsOptimized(s, p);
    return 0;
}
