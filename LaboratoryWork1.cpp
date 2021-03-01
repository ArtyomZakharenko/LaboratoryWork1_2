#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void GetNumber(int *);
int GetSign (int);
void ShowResult (int);

int main()
{   
    int number;
    int (*ptGtSgn)(int) = GetSign;

    GetNumber(&number);
    ShowResult(ptGtSgn(number));
    
}

void GetNumber(int * num) {
    printf("Please, enter the number: ");
    scanf("%d", num);
}

int GetSign(int num) {
    int mask = 1;
    if (num == 0) {
        mask = 0;
    }
    return mask | (num >> 31);
}

void ShowResult(int num) {
    switch (num)
    {
    case 0:
        printf("\nEntered number is 0");
        break;
    case 1:
        printf("\nEntered number is positive");
        break;
    case -1:
        printf("\nEntered number is negative");
        break;
    default:
        printf("Unknown error!");
        return;
    }
}