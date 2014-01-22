#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "LoaderParams.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams)
{
    m_x = pParams->getX();
    m_y = pParams->getY();
    m_width = pParams->getWidth();
    m_height = pParams->getHeight();

    m_textureID = pParams->getTextureID();
    m_currentRow = 1;
    m_currentFrame = 1;
}

SDLGameObject::~SDLGameObject(void)
{
}

void SDLGameObject::update()
{
	//empty
}

void SDLGameObject::draw()
{
    TheTextureManager::Instance()->drawFrame(m_textureID, m_x, m_y,
	m_width, m_height, m_currentRow, m_currentFrame,
	GlobalGame::Instance()->getRenderer());
}
void SDLGameObject::clean()
{
}
