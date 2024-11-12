#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"

int main()
{
  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);
  SDL_Window *window = SDL_CreateWindow("Algoritmi de sortare - Vizualizator", 1270, 720, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

  SDL_Event event;
  SDL_bool isRunning = SDL_TRUE;
  while(isRunning)
  {
    while (SDL_PollEvent(&event))
    {
      switch (event.type) {
        case SDL_EVENT_QUIT:
          isRunning = SDL_FALSE;
          break;
      }
    }

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
  return 0;
}
