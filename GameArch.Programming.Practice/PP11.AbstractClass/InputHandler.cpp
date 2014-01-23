#include "InputHandler.h"
#include <SDL.h>
#include "Game.h"

InputHandler* InputHandler::m_pInstance = 0;

void InputHandler::clean()
{
}

void InputHandler::update()
{
	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			GlobalGame::Instance()->quit();
		}

		if(event.type == SDL_KEYUP)
		{
			m_keyStates = SDL_GetKeyboardState(0);
		}
		if(event.type == SDL_KEYDOWN)
		{
			m_keyStates = SDL_GetKeyboardState(0);
		}
	}
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if(m_keyStates != 0)
	{
		if(m_keyStates[key] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}