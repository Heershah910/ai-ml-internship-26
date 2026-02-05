#include <stdio.h>
#include <conio.h>

#define SIZE 5

int main()
{
    int a[SIZE];
    int i, j, temp;
    int choice, key;
    int low, high, mid;
    int flag = -1;
    int count = 0;
    int exch = 1;

    /* Input array */
    for (i = 0; i < SIZE; i++)
    {
        printf("Enter value %d : ", i + 1);
        scanf("%d", &a[i]);
    }

    /* Display Unsorted Array */
    printf("\nUnsorted Array:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }

    /* Bubble Sort */
    for (i = 0; i < SIZE && exch == 1; i++)
    {
        exch = 0;
        for (j = 0; j < SIZE - 1; j++)
        {
            count++;

            if (a[j] > a[j + 1])
            {
                exch = 1;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    /* Exclude last unnecessary iteration */
    count = count - 1;

    /* Display Sorted Array */
    printf("\n\nSorted Array:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\n\nSorting Iterations (excluding last): %d\n", count);

    /* Search Menu */
    printf("\n1. Linear Search");
    printf("\n2. Binary Search");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    printf("Enter key to search: ");
    scanf("%d", &key);

    if (choice == 1) /* Linear Search */
    {
        flag = -1;
        for (i = 0; i < SIZE; i++)
        {
            if (a[i] == key)
            {
                flag = i;
                break;
            }
        }

        if (flag >= 0)
            printf("\nKey found at index %d (Linear Search)\n", flag);
        else
            printf("\nKey not found (Linear Search)\n");
    }

    else if (choice == 2) /* Binary Search */
    {
        low = 0;
        high = SIZE - 1;
        flag = -1;

        while (low <= high)
        {
            mid = (low + high) / 2;

            if (a[mid] == key)
            {
                flag = mid;
                break;
            }
            else if (key > a[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }

        if (flag >= 0)
            printf("\nKey found at index %d (Binary Search)\n", flag);
        else
            printf("\nKey not found (Binary Search)\n");
    }

    else
    {
        printf("\nInvalid Choice!\n");
    }

    return 0;
}
