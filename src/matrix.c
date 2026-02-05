#include <stdio.h>
#include <stdlib.h> // Replaced conio.h for modern compatibility

#define ROW 30
#define COL 30

int a[ROW][COL],
    b[ROW][COL], c[ROW][COL] = {0};
int r1, c1, r2, c2;

void scanArray();
void displayArray();
void mult();
void add();
void sub();
void menu();

int main()
{
    int choice;
    scanArray();
    displayArray();

    while (1)
    {
        menu();
        printf("\nEnter the choice: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            sub();
            break;
        case 3:
            mult();
            break;
        case 7:
            exit(0); // Standard way to exit
        default:
            printf("\nInvalid choice!");
        }
        printf("\nPress Enter to continue...");
        getchar(); // To consume the newline from scanf
        getchar(); // To pause
    }
    return 0;
}

void menu()
{
    printf("\n--- Matrix Operations ---");
    printf("\n1 ------ add");
    printf("\n2 ------ subtract");
    printf("\n3 ------ multiply");
    printf("\n7 ------ exit");
}

void scanArray()
{
    int i, j;
    printf("\nEnter rows and cols for 1st array: ");
    scanf("%d %d", &r1, &c1);
    printf("\nEnter rows and cols for 2nd array: ");
    scanf("%d %d", &r2, &c2);

    if (r1 > ROW || c1 > COL || r2 > ROW || c2 > COL)
    {
        printf("\nError: Size exceeds %d", ROW);
        exit(1);
    }

    printf("\nEnter values for 1st matrix:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter values for 2nd matrix:\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
}

void displayArray()
{
    int i, j;
    printf("\n1st Matrix:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n2nd Matrix:\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}

void add()
{
    if (r1 == r2 && c1 == c2)
    {
        printf("\nAddition Result:\n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                c[i][j] = a[i][j] + b[i][j];
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nMatrices are not conformable for addition.");
    }
}

void sub()
{
    if (r1 == r2 && c1 == c2)
    {
        printf("\nSubtraction Result:\n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                c[i][j] = a[i][j] - b[i][j];
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nMatrices are not conformable for subtraction.");
    }
}

void mult()
{
    int i, j, k;
    if (c1 == r2)
    {
        // Reset result matrix to 0
        for (i = 0; i < r1; i++)
            for (j = 0; j < c2; j++)
                c[i][j] = 0;

        printf("\nMultiplication Result:\n");
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c2; j++)
            {
                for (k = 0; k < c1; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nMultiplication not possible (Cols of A must equal Rows of B).");
    }
}