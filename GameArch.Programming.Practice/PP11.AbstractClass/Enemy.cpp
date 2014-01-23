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
		//���콺 Ű �ٿ� �� ������ ����
		m_acceleration = *TheInputHandler::getInstance()->getMousePosition();
		//std::cout<<a->getX()<<" "<<target->getY()<<std::endl;
		m_velocity = (m_acceleration-m_position) / 1000;
	}

	//�� ��ġ���� ������ ���� �� ���� normalize �ϰ� velocity ��ŭ �����Ӹ��� �̵�
	
}