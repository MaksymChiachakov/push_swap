#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int  is_duplicate(int *arr, int n, int value)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (arr[i] == value)
            return (1);
        i++;
    }
    return (0);
}

static int  generate_unique(int *arr, int n)
{
    int value;
    int mod;

    mod = 1000000;
    value = rand() % mod;
    while (is_duplicate(arr, n, value))
        value = rand() % mod;
    return (value);
}

int main(void)
{
    int arr[500];
    int i;
    int value;

    i = 0;
    srand(time(NULL));

    while (i < 500)
    {
        value = generate_unique(arr, i);
        arr[i] = value;
        i++;
    }
    i = 0;

    while (i < 500)
    {
        printf("%d", arr[i]);
        if (i < 499)
            printf(" ");
        i++;
    }
    return (0);
}
