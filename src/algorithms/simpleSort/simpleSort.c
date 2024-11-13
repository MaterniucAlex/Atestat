#include "simpleSort.h"
#include "../../arrayFunctions/arrayFunctions.h"
#include "../../Main.h"

void simpleSort(int *array, int n)
{
  for(int i = 0; i < n-1; i++)
  {
    int min = i;
    selectedID = i;
    for(int j = i + 1; j < n; j++)
      if (array[j] < array[min]) min = j;
    switchArrayItemsAndRender(array, n, selectedID, min);
  }
}
