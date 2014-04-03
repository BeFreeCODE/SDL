#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
GameObject::GameObject(void)
{
}


GameObject::~GameObject(void)
{
}


void GameObject::load(int x, int y, int width, int height, 
                                     std::string textureID)
{
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
    m_textureID = textureID;
    m_currentRow = 1;
    m_currentFrame = 1;
}

void GameObject::draw(SDL_Renderer* pRenderer)
{
    GlobalTextureManager::Instance()->drawFrame(m_textureID,    
           m_x, m_y, m_width, m_height, 
           m_currentRow, m_currentFrame, pRenderer);
}

void GameObject::update()
{
	m_currentFrame = int((SDL_GetTicks() / 100) % 6);
	bool IsBound = false;// = GlobalGame::Instance()->CheckBound(m_x,m_y,m_width,m_height);

	if(IsBound)
		m_x -= 1;
	else
		m_x += 1;
	/*if(m_x + m_width < 640)
		m_x += 1; 
	else if(m_x > 0)
		m_x -= 1;*/
}

void GameObject::clean()
{

}