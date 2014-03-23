#include "InputHandler.h"
#include <SDL.h>
#include "Game.h"

InputHandler* InputHandler::m_pInstance = 0;

InputHandler::InputHandler()
 : m_keyStates(0) 
{
	m_mousePosition = new Vector2D(0,0);
	for(int i =0; i < 3; ++i)
	{
	m_mouseButtonStates.push_back(false);
	}
}

void InputHandler::clean()
{
	delete m_mousePosition;
	m_mousePosition = nullptr;
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

		if(event.type == SDL_MOUSEMOTION)
		{
			m_mousePosition->setX(event.motion.x);
			m_mousePosition->setX(event.motion.y);
		}

		if(event.type == SDL_MOUSEBUTTONDOWN)
		{
			if(event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseButtonStates[LEFT] = true;
			}
			if(event.button.button == SDL_BUTTON_MIDDLE)
			{
				m_mouseButtonStates[MIDDLE] = true;
			}
			if(event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouseButtonStates[RIGHT] = true;
			}
		}
		if(event.type == SDL_MOUSEBUTTONUP)
		{
			if(event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseButtonStates[LEFT] = false;
			}
			if(event.button.button == SDL_BUTTON_MIDDLE)
			{
				m_mouseButtonStates[MIDDLE] = false;
			}
			if(event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouseButtonStates[RIGHT] = false;
			}
		}
	}
}
bool InputHandler::getMouseButtonState(int buttonNumber)
{
	return m_mouseButtonStates[buttonNumber];
}
Vector2D* InputHandler::getMousePosition()
{
	return m_mousePosition;
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