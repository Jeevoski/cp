#include<stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printarray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void readarray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

int main() {
    int arr[50], n;
    printf("enter the number of elements\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    readarray(arr, n);
    printf("the original array: ");
    printarray(arr, n);
    mergesort(arr, 0, n - 1);
    printf("the sorted array is: ");
    printarray(arr, n);
    return 0;
}
