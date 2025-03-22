#include "bubbleSort.h"
#include "../../arrayFunctions/arrayFunctions.h"
#include "../../Main.h"

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (!isGameRunning()) return;
      if (arr[j] > arr[j + 1]) {
        setSelectedId(j);
        switchArrayItemsAndRender(arr, n, j, j + 1);
      }
    }
  }
}

