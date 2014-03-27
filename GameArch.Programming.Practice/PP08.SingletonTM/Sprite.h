#pragma once
#include <SDL.h>
#include <string>
class Sprite
{
public:
	Sprite(void);
	virtual ~Sprite(void);

	SDL_Rect getRect();
private:
	std::string m_id;
	int m_currentFrame;
	SDL_Rect m_rect;
};

