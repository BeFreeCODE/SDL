#pragma once
#include <SDL.h>
#include <map>
#include <string>

#include "Sprite.h"

class TextureManager
{
private:
	static TextureManager* s_pInstance;
public:
	static TextureManager* Instance()
	{
		if(s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

	~TextureManager(void);
	std::map<std::string, Sprite> m_textureMap;

	bool load(std::string fileName, std::string id, 
		SDL_Renderer* pRenderer);

	void draw(SDL_Renderer* pRenderer, std::string id, int x, int y, int width, int height, 
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(SDL_Renderer* pRenderer,std::string id, int x, int y, int width, int height, 
		int currentRow, int currentFrame, 
		SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	TextureManager(void);


};

typedef TextureManager GlobalTextureManager;