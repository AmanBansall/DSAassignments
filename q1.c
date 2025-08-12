#include <stdio.h>
int main() 
{
    int arr[100], n = 0, choice, i, pos, val, search;

    while (1) {
        printf("\n--- MENU ---\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter number of elements: ");
            scanf("%d", &n);
            printf("Enter elements:\n");
            for (i = 0; i < n; i++)
                scanf("%d", &arr[i]);
        }

        else if (choice == 2) {
            printf("Array elements: ");
            for (i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }

        else if (choice == 3) {
            printf("Enter position to insert (0 to %d): ", n);
            scanf("%d", &pos);
            printf("Enter value to insert: ");
            scanf("%d", &val);
            for (i = n; i > pos; i--)
                arr[i] = arr[i - 1];
            arr[pos] = val;
            n++;
        }

        else if (choice == 4) {
            printf("Enter position to delete (0 to %d): ", n - 1);
            scanf("%d", &pos);
            for (i = pos; i < n - 1; i++)
                arr[i] = arr[i + 1];
            n--;
        }

        else if (choice == 5) {
            printf("Enter value to search: ");
            scanf("%d", &search);
            for (i = 0; i < n; i++) {
                if (arr[i] == search) {
                    printf("Found at position %d\n", i);
                    break;
                }
            }
            if (i == n)
                printf("Not found\n");
        }

        else if (choice == 6) {
            break;
        }

        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
