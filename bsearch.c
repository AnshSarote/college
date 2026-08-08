#include <stdio.h>
#include <math.h>
int count = 0;
int binary(int n, int arr[], int fin)
{
    int low = 0;
    int high = n - 1;
    int mid = (low + high) / 2;
    while (low <= high)
    {
        if (arr[mid] == fin)
        {
            count++;
            return 1;
        }
        else if (arr[mid] < fin)
        {
            low = mid + 1;
            count++;
        }
        else     {
            high = mid - 1;
            count++;
        }
        mid = (low + high) / 2;
    }

    return 0;
}

int main()
{
    int n;

    printf("enter the length of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("enter the elements of array in ascending order.\n");

    for (int i = 0; i < n; i++)
    {
        printf("enter the %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int f;
    printf("enter the element to be searched: ");
    scanf("%d", &f);

    int result = binary(n, arr, f);
    int re= log2(n)+1;
    if (result == 1)
    {
        printf("the element is present. the number of comparison is %d\n", count);

        if (count == 1)
        {
            printf("the best case. the number of comparison is %d\n", count);
        }
        else if (count == re)
        {
            printf("the worst case. the number of comparison is %d\n", count);
        }
        else
        {
            printf("the average case. the number of comparison is %d\n", count);
        }
    }
    else  {
        printf("the element is not found. the number of comparison is %d. the worst case\n", count);
    }
    return 0;
}
