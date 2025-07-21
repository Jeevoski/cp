#include<stdio.h>

void swap(int*a ,int*b)
{
    int temp= *a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low, int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int j=low; j<high; j++)  
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quicksort(int arr[],int low ,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    printf("\n");
}

void readarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
}

int main()
{
    int n, a[50];
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    readarray(a,n);  
    printf("Original array: ");
    printarray(a,n); 
    quicksort(a,0,n-1); 
    printf("Sorted array: ");
    printarray(a,n);  
    return 0;
}
	
