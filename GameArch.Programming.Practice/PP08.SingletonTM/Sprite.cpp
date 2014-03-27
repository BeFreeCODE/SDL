#include "Sprite.h"


Sprite::Sprite(void)
	: m_id(),m_currentFrame(0),m_rect()
{
}


Sprite::~Sprite(void)
{
}

SDL_Rect Sprite::getRect()
{
	return m_rect;
}