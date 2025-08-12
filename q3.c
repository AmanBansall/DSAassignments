#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};  // Missing number is 5
    int n = sizeof(arr) / sizeof(arr[0]);

    int total = (n + 1) * (n + 2) / 2;  // Sum of 1 to n+1 numbers
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int missing = total - sum;
    printf("Missing number is: %d\n", missing);

    return 0;
}
