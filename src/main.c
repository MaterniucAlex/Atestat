#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>

#define SCREEN_WIDTH 1250
#define SCREEN_HEIGHT 720

void shuffleAray(int *array, int n);
void renderArray(int *array, int n, SDL_Renderer *renderer);
int isAraySorted(int *array, int n);
void switchArrayItems(int *array, int n, int i, int j);
void simpleSort(int *array, int n);

int switchId = -1;
int selectedID = -1;

int main()
{
  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);
  SDL_Window *window = SDL_CreateWindow("Algoritmi de sortare - Vizualizator", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

  SDL_Event event;
  SDL_bool isRunning = SDL_TRUE;

  int n = 50;
  int array[n];

  shuffleAray(array, n);

  int FPS = 30;
  int msInAsecond = 1000;
  int minimumWaitTime = msInAsecond / FPS;
  int timer_start = SDL_GetTicks();

  while(isRunning)
  {
    //keyboard input
    while (SDL_PollEvent(&event))
    {
      switch (event.type) {
        case SDL_EVENT_QUIT:
          isRunning = SDL_FALSE;
          break;
      }
    }

    //update
    if (!isAraySorted(array, n))
    {
      simpleSort(array, n);
      switchArrayItems(array, n, selectedID, switchId);
    }

    //render
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
    SDL_RenderClear(renderer);

    renderArray(array, n, renderer);

    SDL_RenderPresent(renderer);

    //fps controll
    int currentTime = SDL_GetTicks();
    int loopTime = timer_start - currentTime;
    SDL_Delay(minimumWaitTime - loopTime);
    timer_start = SDL_GetTicks();
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
  return 0;
}

void shuffleAray(int *array, int n)
{
  for(int i = 0; i < n; i++)
    array[i] = n + 1 - i;
}

void renderArray(int *array, int n, SDL_Renderer *renderer)
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
    else if (i == switchId)
      SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    else
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &itemRect);
  }
}

int isAraySorted(int *array, int n)
{
  for(int i = 1; i < n; i++)
    if (array[i-1] > array[i]) return 0;
  return 1;
}

void simpleSort(int *array, int n)
{
  for(int i = 0; i < n - 1; i++)
  {
    selectedID = i;
    for(int j = i + 1; j < n; j++)
    {
      if (array[j] < array[i])
      {
        switchId = j;
        return;
      }
    }
  }
}

void switchArrayItems(int *array, int n, int i, int j)
{
  if (i >= n || j >= n) return;
  int ok = array[i];
  array[i] = array[j];
  array[j] = ok;
}
