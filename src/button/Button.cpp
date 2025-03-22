#include "SDL3/SDL.h"
#include "Button.h"

static float mouseX;
static float mouseY;

Button createButton(int x, int y, int w, int h, void (*clickFunction)(int))
{
	Button button;
	button.rect.x = x;
	button.rect.y = y;
	button.rect.w = w;
	button.rect.h = h;
	button.isVisible = 0;

	button.clickFunction = clickFunction;

	return button;
}

void updateMousePosition()
{
	SDL_GetMouseState(&mouseX, &mouseY);
}

int isMouseInsideButton(Button *button)
{
	if (mouseX >= button->rect.x && mouseX <= button->rect.x + button->rect.w && 
		mouseY >= button->rect.y && mouseY <= button->rect.y + button->rect.h)
		return 1;
	return 0;
}

// void pressButton(Button *button)
// {
// 	button->clickFunction();
// }

void renderButton(SDL_Renderer *renderer, Button *button)
{
	if (button->isVisible == 0) return;
	if (!isMouseInsideButton(button)) return;

	SDL_SetRenderDrawColor(renderer, 200, 200, 200, 100);
	SDL_RenderFillRect(renderer, &button->rect);

}