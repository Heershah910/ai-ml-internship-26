#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account
{
    int accNo;
    char name[50];
    float balance;
};

void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
void transferMoney();
void viewAccount();

int main()
{
    int choice;

    while (1)
    {
        printf("\n====== BANKING SYSTEM ======\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Transfer Money\n");
        printf("6. View Account Details\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            depositMoney();
            break;
        case 3:
            withdrawMoney();
            break;
        case 4:
            checkBalance();
            break;
        case 5:
            transferMoney();
            break;
        case 6:
            viewAccount();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

void createAccount()
{
    FILE *fp = fopen("bank.dat", "ab");
    struct Account a;

    printf("Enter Account Number: ");
    scanf("%d", &a.accNo);
    printf("Enter Name: ");
    scanf(" %[^\n]", a.name);
    printf("Enter Initial Balance: ");
    scanf("%f", &a.balance);

    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);

    printf("Account created successfully!\n");
}

void depositMoney()
{
    FILE *fp = fopen("bank.dat", "rb+");
    struct Account a;
    int acc;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    while (fread(&a, sizeof(a), 1, fp))
    {
        if (a.accNo == acc)
        {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            a.balance += amount;

            fseek(fp, -sizeof(a), SEEK_CUR);
            fwrite(&a, sizeof(a), 1, fp);
            fclose(fp);

            printf("Money deposited successfully!\n");
            return;
        }
    }
    fclose(fp);
    printf("Account not found!\n");
}

void withdrawMoney()
{
    FILE *fp = fopen("bank.dat", "rb+");
    struct Account a;
    int acc;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    while (fread(&a, sizeof(a), 1, fp))
    {
        if (a.accNo == acc)
        {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (a.balance >= amount)
            {
                a.balance -= amount;
                fseek(fp, -sizeof(a), SEEK_CUR);
                fwrite(&a, sizeof(a), 1, fp);
                printf("Withdrawal successful!\n");
            }
            else
            {
                printf("Insufficient balance!\n");
            }
            fclose(fp);
            return;
        }
    }
    fclose(fp);
    printf("Account not found!\n");
}

void checkBalance()
{
    FILE *fp = fopen("bank.dat", "rb");
    struct Account a;
    int acc;

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    while (fread(&a, sizeof(a), 1, fp))
    {
        if (a.accNo == acc)
        {
            printf("Current Balance: %.2f\n", a.balance);
            fclose(fp);
            return;
        }
    }
    fclose(fp);
    printf("Account not found!\n");
}

void transferMoney()
{
    FILE *fp = fopen("bank.dat", "rb+");
    struct Account a1, a2;
    int from, to;
    float amount;

    printf("Enter Your Account Number: ");
    scanf("%d", &from);
    printf("Enter Receiver Account Number: ");
    scanf("%d", &to);
    printf("Enter Amount to Transfer: ");
    scanf("%f", &amount);

    int found1 = 0, found2 = 0;
    long pos1, pos2;

    while (fread(&a1, sizeof(a1), 1, fp))
    {
        if (a1.accNo == from)
        {
            found1 = 1;
            pos1 = ftell(fp) - sizeof(a1);
            break;
        }
    }

    rewind(fp);

    while (fread(&a2, sizeof(a2), 1, fp))
    {
        if (a2.accNo == to)
        {
            found2 = 1;
            pos2 = ftell(fp) - sizeof(a2);
            break;
        }
    }

    if (found1 && found2 && a1.balance >= amount)
    {
        a1.balance -= amount;
        a2.balance += amount;

        fseek(fp, pos1, SEEK_SET);
        fwrite(&a1, sizeof(a1), 1, fp);

        fseek(fp, pos2, SEEK_SET);
        fwrite(&a2, sizeof(a2), 1, fp);

        printf("Transfer successful!\n");
    }
    else
    {
        printf("Transfer failed!\n");
    }

    fclose(fp);
}

void viewAccount()
{
    FILE *fp = fopen("bank.dat", "rb");
    struct Account a;
    int acc;

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    while (fread(&a, sizeof(a), 1, fp))
    {
        if (a.accNo == acc)
        {
            printf("\nAccount Number: %d", a.accNo);
            printf("\nName: %s", a.name);
            printf("\nBalance: %.2f\n", a.balance);
            fclose(fp);
            return;
        }
    }
    fclose(fp);
    printf("Account not found!\n");
}
