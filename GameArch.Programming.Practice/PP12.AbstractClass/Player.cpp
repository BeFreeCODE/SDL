#include "Player.h"

#define ACCEL 0.1f
Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
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
	m_currentFrame = int((SDL_GetTicks() / 100) % 6);
	m_acceleration.setX(ACCEL);

	SDLGameObject::update();
//	bool IsBound = false;// = GlobalGame::Instance()->CheckBound(m_x,m_y,m_width,m_height);

	//if(IsBound)
	//	m_x -= 1;
	//else
	//	m_x += 1;
	///*if(m_x + m_width < 640)
	//	m_x += 1; 
	//else if(m_x > 0)
	//	m_x -= 1;*/
	//if(m_x > 0)
	//	m_x -= 1; 

}

void Player::clean()
{

}