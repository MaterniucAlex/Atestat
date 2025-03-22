#pragma once
#ifndef CUSTOM_BUTTON
#define CUSTOM_BUTTON

typedef struct 
{
	SDL_FRect rect;
	void (*clickFunction)(int);
	int isVisible;
} Button;

Button createButton(int x, int y, int w, int h, void (*clickFunction)(int n) );
void updateMousePosition();
void renderButton(SDL_Renderer *renderer, Button *button);
int isMouseInsideButton(Button *button);
// void pressButton(Button *button);
#endif