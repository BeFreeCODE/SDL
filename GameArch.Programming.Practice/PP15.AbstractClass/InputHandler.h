#pragma once
#include <SDL.h>
#include <vector>
#include "Vector2D.h"
enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};
class InputHandler
{
public:
	static InputHandler* getInstance()
	{
		if(m_pInstance == nullptr)
		{
			m_pInstance = new InputHandler;
		}

		return m_pInstance;
	}

	void update();
	void clean();
	bool isKeyDown(SDL_Scancode key);
	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();
private:
	InputHandler(void);
	~InputHandler(void) {}
	static InputHandler* m_pInstance;

	const Uint8* m_keyStates;

	std::vector<bool> m_mouseButtonStates;

	Vector2D* m_mousePosition;
};

typedef InputHandler TheInputHandler;