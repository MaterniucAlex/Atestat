#ifndef ARRAY_FUNCTIONS
#define ARRAY_FUNCTIONS

#include "SDL3/SDL.h"
#include "../Main.h"

void initializeArrayFunctions(SDL_Renderer *rend, int w, int h, int *sId);
void shuffleAray(int *array, int n);
void renderArray(SDL_Renderer *renderer, int *array, int n);
int isArraySorted(int *array, int n);
void switchArrayItemsAndRender(int *array, int n, int i, int j);
void handleEvents(int *array, int n);
void forceSortArray(int *array, int n);

#endif // !ARRAY_FUNCTIONS
