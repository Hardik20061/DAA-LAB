#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int max = 0, len, i, j, k, duplicate;

    scanf("%s", s);
    len = strlen(s);

    for (i = 0; i < len; i++) {
        duplicate = 0;

        for (j = i + 1; j < len; j++) {
            for (k = i; k < j; k++) {
                if (s[k] == s[j]) {
                    duplicate = 1;
                    break;
                }
            }

            if (duplicate)
                break;

            if (j - i + 1 > max)
                max = j - i + 1;
        }

        if (max == 0)
            max = 1;
    }

    printf("Longest length = %d", max);

    return 0;
}
