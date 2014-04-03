///
/// created by GiHeon Han
///
/// 2014.04.03
///
#pragma once

#include <SDL.h>
#include <string>
class Sprite
{
public:
	Sprite(void);
	virtual ~Sprite(void);

	SDL_Rect getRect();
public:
	std::string m_id;
	int m_currentFrame;
	SDL_Texture* m_pTexture;
	SDL_Rect m_rect;
};

