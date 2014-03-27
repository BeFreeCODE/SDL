#include "TextureManager.h"
#include <SDL_image.h>


TextureManager* TextureManager::s_pInstance = 0;


TextureManager::TextureManager(void)
{
}


TextureManager::~TextureManager(void)
{
}


bool TextureManager::load(std::string fileName, std::string   id,  
	SDL_Renderer* pRenderer)
{
	Sprite tempSprite;
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
	if(pTempSurface == 0) {
		return false;
	}
	tempSprite.m_rect.x =0;
	tempSprite.m_rect.y =0;
	tempSprite.m_rect.w = pTempSurface->w;
	tempSprite.m_rect.h = pTempSurface->h;

	SDL_Texture* pTexture =
		SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	
	if(pTexture != 0) 
	{
		tempSprite.m_id = id;
		tempSprite.m_pTexture = pTexture;
		tempSprite.m_currentFrame = 0;
		m_textureMap[id] = tempSprite;
		return true;
	}

	return false;
}

void TextureManager::draw(SDL_Renderer* pRenderer,std::string id, 
	int x, int y, int width, int height,  
	 SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id].m_pTexture, 
		&srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(SDL_Renderer* pRenderer,std::string id, int x, int y, 
	int width, int height, int currentRow, int currentFrame, 
	 SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id].m_pTexture, &srcRect,
		&destRect, 0, 0, flip);
}