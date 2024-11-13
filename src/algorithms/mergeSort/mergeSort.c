#include "mergeSort.h"
#include "../../arrayFunctions/arrayFunctions.h"
#include "../../Main.h"

void merge(int arr[], int n, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    
    // Merge the temporary arrays back into arr[]
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        selectedID = k;
        switchArrayItemsAndRender(arr, n, k, k);
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        selectedID = k;
        switchArrayItemsAndRender(arr, n, k, k);
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        selectedID = k;
        switchArrayItemsAndRender(arr, n, k, k);
        j++;
        k++;
    }
}
void mergeSort(int arr[], int n, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, n, left, mid);
        mergeSort(arr, n, mid + 1, right);

        // Merge the sorted halves
        merge(arr, n, left, mid, right);
    }
}
