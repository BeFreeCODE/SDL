#include "Player.h"

Player::Player(void)
{
}


Player::~Player(void)
{
}

void Player::load(int x, int y, int width, int height, 
                            std::string textureID)
{
    GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer)
{
    GameObject::draw(pRenderer);
}

void Player::update()
{
	if(m_x > 0)
		m_x -= 1; 
}

void Player::clean()
{

}