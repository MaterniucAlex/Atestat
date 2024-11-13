#include "arrayFunctions.h"
#include "../Main.h"
#include <SDL3/SDL_render.h>

void shuffleAray(int *array, int n)
{
  for(int i = 0; i < n; i++)
    array[i] = n + 1 - i;
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

    if (i == selectedID)
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

  int ok = array[i];
  array[i] = array[j];
  array[j] = ok;

  renderAndWait(array, n);
}
