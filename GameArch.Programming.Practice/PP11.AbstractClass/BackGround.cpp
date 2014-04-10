#include "BackGround.h"
#include "TextureManager.h"
#include "Game.h"
BackGround::BackGround(const LoaderParams* pParams)
	:SDLGameObject(pParams)
{
	m_currentFrame = 0;
	m_currentRow = 0;
}


BackGround::~BackGround(void)
{
}



void BackGround::draw()
{
	GlobalTextureManager::Instance()->draw(m_textureID,m_x,m_y,m_width,m_height,GlobalGame::Instance()->getRenderer());
}

void BackGround::update()
{
}

void BackGround::clean()
{
}
