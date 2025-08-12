#include <stdio.h>

int main() {
    printf("Enter the size of the array");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements in the array");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    // Bubble Sort Logic
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n -1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
