/*square every element and return it sorted , without sorting again*/

#include <stdio.h>

int main() {
    int arr[] = {-7, -3, 2, 3, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res[n];
    int left = 0, right = n - 1, pos = n - 1;

    while (left <= right) {
        int l = arr[left] * arr[left];
        int r = arr[right] * arr[right];
        if (l > r) {
            res[pos--] = l;
            left++;
        } else {
            res[pos--] = r;
            right--;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", res[i]);
    return 0;
}
