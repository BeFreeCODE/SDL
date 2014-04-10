#include "Player.h"


Player::Player(const LoaderParams* pParams)
	:SDLGameObject(pParams)
{
}


Player::~Player(void)
{
}


void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
	if(m_x > 0)
		m_x -= 1; 

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean()
{

}