#pragma once
#include <SDL.h>
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
	
private:
	InputHandler(void) : m_keyStates(0) {}
	~InputHandler(void) {}
	static InputHandler* m_pInstance;

	const Uint8* m_keyStates;
};

typedef InputHandler TheInputHandler;