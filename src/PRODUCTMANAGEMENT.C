#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct Product
{
    int id;
    char name[50];
    char category[30];
    int quantity;
    float price;
    int active; // 1 = available, 0 = deleted
};

struct Product products[SIZE];
int count = 0;

/* ---------- Function Declarations ---------- */
int login();
void addProduct();
void displayProducts();
void searchProductById();
void sortByPrice();
void updateProductById();
void deleteProductById();

/* ---------- Login Function ---------- */
int login()
{
    char username[20], password[20];
    int attempts = 3;

    while (attempts > 0)
    {
        printf("\nEnter Username: ");
        scanf("%s", username);

        printf("Enter Password: ");
        scanf("%s", password);

        if (strcmp(username, "admin") == 0 && strcmp(password, "1234") == 0)
        {
            printf("\nLogin Successful!\n");
            return 1;
        }
        else
        {
            attempts--;
            printf("\nInvalid Login! Attempts left: %d\n", attempts);
        }
    }

    printf("\nAccess Denied. Exiting program...\n");
    return 0;
}

/* ---------- Add Product ---------- */
void addProduct()
{
    if (count == SIZE)
    {
        printf("\nInventory Full!\n");
        return;
    }

    printf("\nEnter Product ID: ");
    scanf("%d", &products[count].id);

    printf("Enter Product Name: ");
    scanf(" %[^\n]", products[count].name);

    printf("Enter Category: ");
    scanf(" %[^\n]", products[count].category);

    printf("Enter Quantity: ");
    scanf("%d", &products[count].quantity);

    printf("Enter Price: ");
    scanf("%f", &products[count].price);

    products[count].active = 1;
    count++;

    printf("\nProduct Added Successfully!\n");
}

/* ---------- Display Products ---------- */
void displayProducts()
{
    int i, found = 0;

    printf("\nID\tName\t\tCategory\tQuantity\tPrice\n");
    printf("-------------------------------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        if (products[i].active == 1)
        {
            printf("%d\t%s\t\t%s\t\t%d\t\t%.2f\n",
                   products[i].id,
                   products[i].name,
                   products[i].category,
                   products[i].quantity,
                   products[i].price);
            found = 1;
        }
    }

    if (!found)
        printf("No Active Products Found!\n");
}

/* ---------- Search Product ---------- */
void searchProductById()
{
    int id, i, found = 0;

    printf("\nEnter Product ID to Search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (products[i].id == id && products[i].active == 1)
        {
            printf("\nProduct Found:\n");
            printf("ID: %d\n", products[i].id);
            printf("Name: %s\n", products[i].name);
            printf("Category: %s\n", products[i].category);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2f\n", products[i].price);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nProduct Not Found!\n");
}

/* ---------- Sort Products By Price ---------- */
void sortByPrice()
{
    int i, j;
    struct Product temp;

    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (products[i].price > products[j].price)
            {
                temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }

    printf("\nProducts Sorted by Price (Ascending)!\n");
    displayProducts();
}

/* ---------- Update Product ---------- */
void updateProductById()
{
    int id, i, found = 0;

    printf("\nEnter Product ID to Update: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (products[i].id == id && products[i].active == 1)
        {
            printf("\nEnter New Name: ");
            scanf(" %[^\n]", products[i].name);

            printf("Enter New Category: ");
            scanf(" %[^\n]", products[i].category);

            printf("Enter New Quantity: ");
            scanf("%d", &products[i].quantity);

            printf("Enter New Price: ");
            scanf("%f", &products[i].price);

            printf("\nProduct Updated Successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nProduct Not Found!\n");
}

/* ---------- Delete Product ---------- */
void deleteProductById()
{
    int id, i, found = 0;

    printf("\nEnter Product ID to Delete: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (products[i].id == id && products[i].active == 1)
        {
            products[i].active = 0;
            printf("\nProduct Deleted Successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nProduct Not Found!\n");
}

/* ---------- Main Function ---------- */
int main()
{
    int choice;

    if (!login())
        return 0;

    do
    {
        printf("\n\n===== PRODUCT INVENTORY MANAGEMENT =====");
        printf("\n1. Add Product");
        printf("\n2. Display All Products");
        printf("\n3. Search Product by ID");
        printf("\n4. Sort Products by Price");
        printf("\n5. Update Product By ID");
        printf("\n6. Delete Product By ID");
        printf("\n7. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addProduct();
            break;
        case 2:
            displayProducts();
            break;
        case 3:
            searchProductById();
            break;
        case 4:
            sortByPrice();
            break;
        case 5:
            updateProductById();
            break;
        case 6:
            deleteProductById();
            break;
        case 7:
            printf("\nExiting Program...\n");
            break;
        default:
            printf("\nInvalid Choice!\n");
        }

    } while (choice != 7);

    return 0;
}
