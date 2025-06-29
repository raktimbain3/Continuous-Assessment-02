#include<stdio.h>

void ascendingSort(int arr[], int n);
void descendingSort(int arr[], int n);

int main()
{
    int n;
    printf("Enter number of values (1-20): ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    char choice;
    do
    {
        int option;
        printf("Sort in (1) Ascending or (2) Descending? ");
        scanf("%d", &option);

        if (option == 1)
        {
            ascendingSort(arr, n);
            printf("Sorted array: ");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        else if (option == 2)
        {
            descendingSort(arr, n);
            printf("Sorted array: ");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        else
        {
            printf("Invalid option!\n");
        }

        printf("Sort again? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void ascendingSort(int arr[], int n)
{
    for ( int i=0; i < n-1; i++ )
    {
        for ( int j=0; j < n-1-i; j++ )
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void descendingSort(int arr[], int n)
{
    for (int i=0; i < n-1; i++ )
    {
        for ( int j=0; j < n-1-i; j++ )
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
