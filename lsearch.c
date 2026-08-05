#include <stdio.h>
int main()
{
    int n;
    int count = 0;
    int result = 0;
    printf("enter the length of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements of array.\n");

    for (int i = 0; i < n; i++)
    {
        printf("enter the %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int f;

    printf("enter the element to be searched: ");
    scanf("%d", &f);

    for (int i = 0; i < n; i++)
    {
        count++;

        if (arr[i] == f)
        {
            result = 1;
            break;
        }
    }

    if (result == 1)
    {
        printf("the element is present. the number of comparison is %d\n", count);

        if (count == 1)
        {
            printf("the best case. the number of comparison is %d\n", count);
        }
        else if (count == n)
        {
            printf("the worst case. the number of comparison is %d\n", count);
        }
        else
        {
            printf("the average case. the number of comparison is %d\n", count);
        }
    }
    else
    {
        printf("the element is not found. the number of comparison is %d. the worst case\n", count);
    }

    return 0;
}
