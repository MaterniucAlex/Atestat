#include <stdlib.h>
#include "arrayFunctions.h"
#include "SDL3/SDL_render.h"
#include "../Main.h"

void shuffleAray(int *array, int n)
{
  for(int i = 0; i < n; i++)
    array[i] = n + 1 - i;
  for(int i = 0; i < n; i++)
  {
    int s = rand() % n;
    int aux = array[i];
    array[i] = array[s];
    array[s] = aux;
  }
}

void renderArray(SDL_Renderer *renderer, int *array, int n)
{
  SDL_FRect itemRect;
  itemRect.w = SCREEN_WIDTH / n;

  for(int i = 0; i < n; i++)
  {
    itemRect.x = i * itemRect.w;
    itemRect.h = SCREEN_HEIGHT / (n + 1) * array[i];
    itemRect.y = SCREEN_HEIGHT - itemRect.h;

    if (i == getSelectedId())
      SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    else
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &itemRect);
  }
}

int isArraySorted(int *array, int n)
{
  for(int i = 1; i < n; i++)
    if (array[i-1] > array[i]) return 0;
  return 1;
}

void switchArrayItemsAndRender(int *array, int n, int i, int j)
{
  if (i >= n || j >= n) return;

  handleEvents(array, n);

  int ok = array[i];
  array[i] = array[j];
  array[j] = ok;

  renderAndWait(array, n);
}

void forceSortArray(int *array, int n)
{
  for(int i = 0; i < n; i++)
    array[i] = i;

}
