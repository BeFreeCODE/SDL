#pragma once
#include <SDL.h>
#include <map>
#include <string>



class TextureManager
{
public:
	static TextureManager* s_pInstance;
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
	std::map<std::string, SDL_Texture*> m_textureMap;

	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	void draw(std::string id, int x, int y, int width, int height, 
		SDL_Renderer* pRenderer, 
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height, 
		int currentRow, int currentFrame, 
		SDL_Renderer* pRenderer, 
		SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
	TextureManager(void);


};

typedef TextureManager TheTextureManager;