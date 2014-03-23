#include "Enemy.h"
#include "InputHandler.h"
#include <iostream>

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

Enemy::~Enemy(void)
{
}

void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	handleInput();
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	

	SDLGameObject::update();
}
void Enemy::clean()
{

}

void Enemy::handleInput()
{
	if(TheInputHandler::getInstance()->getMouseButtonState(LEFT))
	{
		//마우스 키 다운 시 목적지 설정
		m_acceleration = *TheInputHandler::getInstance()->getMousePosition();
		//std::cout<<a->getX()<<" "<<target->getY()<<std::endl;
		m_velocity = (m_acceleration-m_position) / 1000;
	}

	//내 위치에서 목적지 까지 뺀 곳을 normalize 하고 velocity 만큼 프레임마다 이동
	
}