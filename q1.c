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
    printf("Enter the element to be searched");
    int search;
    scanf("%d",&search);
    int low = 0, high = n - 1;
    int found = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == search) {
            printf("Element %d found at index %d\n", search, mid);
            found = 1;
            break;
        } else if (arr[mid] < search) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", search);
    }

    return 0;
}
