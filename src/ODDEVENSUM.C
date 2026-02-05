#include <stdio.h>

int sumFun(int no);
int oddSumFun(int no);
int evenSumFun(int no);

int main()
{
    int no, oddSum, evenSum;

    printf("Enter No : ");
    scanf("%d", &no);

    oddSum = oddSumFun(no);
    evenSum = evenSumFun(no);

    printf("\nOddSum : %d", oddSum);
    printf("\nEvenSum : %d", evenSum);

    return 0;
}

int sumFun(int no)
{
    int digit, sumValue = 0;

    while (no > 0)
    {
        digit = no % 10;
        sumValue = sumValue + digit;
        no = no / 10;
    }
    return sumValue;
}

int oddSumFun(int no)
{
    int digit, oddDigitNo = 0, place = 1;

    while (no > 0)
    {
        digit = no % 10;

        if (digit % 2 != 0)
        {
            oddDigitNo = oddDigitNo + digit * place;
            place = place * 10;
        }
        no = no / 10;
    }
    return sumFun(oddDigitNo);
}

int evenSumFun(int no)
{
    int digit, evenDigitNo = 0, place = 1;

    while (no > 0)
    {
        digit = no % 10;

        if (digit % 2 == 0)
        {
            evenDigitNo = evenDigitNo + digit * place;
            place = place * 10;
        }
        no = no / 10;
    }
    return sumFun(evenDigitNo);
}
