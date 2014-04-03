#include "BackGround.h"
#include "TextureManager.h"

BackGround::BackGround(void)
{
}


BackGround::~BackGround(void)
{
}

void BackGround::load(int x, int y, int width, int height, 
                            std::string textureID)
{
    GameObject::load(x, y, width, height, textureID);
	m_currentRow = 0;
	m_currentFrame = 0;
}

void BackGround::draw(SDL_Renderer* pRenderer)
{
   GlobalTextureManager::Instance()->draw("jungle",m_x,m_y,m_width,m_height,pRenderer);
}

void BackGround::update()
{
}

void BackGround::clean()
{
}
