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

	
	if(!m_moveEvent.IsComplete())
	{
		m_moveEvent.Do();
		SDLGameObject::update();
	}
}
void Enemy::clean()
{

}

void Enemy::handleInput()
{
	if(TheInputHandler::getInstance()->getMouseButtonState(LEFT))
	{
		//���콺 Ű �ٿ� �� ������ ����
		Vector2D target = *TheInputHandler::getInstance()->getMousePosition();
		//std::cout<<a->getX()<<" "<<target->getY()<<std::endl;
		m_acceleration = target-m_position;
		m_acceleration.normalize();
		m_acceleration *= 0.001;

		m_moveEvent.SetEvent(this,target);
	}

	//�� ��ġ���� ������ ���� �� ���� normalize �ϰ� velocity ��ŭ �����Ӹ��� �̵�
	
}