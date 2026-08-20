// Online C compiler to run C program online
#include <stdio.h>

void merge(int arr[], int mid, int start, int end)
{
    int temp[end + 1], i, k, j;
    i = start;
    j = mid + 1;
    k = start;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int s = start; s <= end; s++)
    {
        arr[s] = temp[s];
    }
    printf("Merging: ");

    for (int s = start; s <= end; s++)
    {
        printf("%d ", arr[s]);
    }

    
}
void mergesort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, mid, start, end);
    }
}
int main()
{
    int n, g = 0;
    printf("enter the length of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements in this array \n ");
    for (int i = 0; i < n; i++)
    {
        printf("enter the %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }
    mergesort(arr, g, n - 1);
    printf("sorted array");
    for (int v = 0; v < n; v++)
    {
        printf("%d ", arr[v]);
    }
}



/**  Online C compiler to run C program online
#include <stdio.h>

void merge(int arr[], int mid, int start, int end)
{
    int temp[end + 1], i, k, j;
    i = start;
    j = mid + 1;
    k = start;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int s = start; s <= end; s++)
    {
        arr[s] = temp[s];
    }
    printf("merging: ");

    for (int s = start; s <= end; s++)
    {
        printf("%d ", arr[s]);
        
    }
    printf("\n");
    
}
void mergesort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, mid, start, end);
    }
    printf("sorting");
     for(int s=0;s<=end;s++){
        printf("%d ", arr[s]);
     }
     printf("\n");
}
int main()
{
    int n, g = 0;
    printf("enter the length of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements in this array \n ");
    for (int i = 0; i < n; i++)
    {
        printf("enter the %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }
    mergesort(arr, g, n - 1);
    printf("sorted array");
    for (int v = 0; v < n; v++)
    {
        printf("%d ", arr[v]);
    }
}**/
