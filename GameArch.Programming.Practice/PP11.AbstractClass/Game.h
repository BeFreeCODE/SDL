#pragma once
#include "SDL.h"
#include "Player.h"
#include <vector>

class Game;
typedef Game GlobalGame;
class Game
{
public:
	static Game* Instance()
	{
		if(m_pGame == 0)
		{
			m_pGame = new Game;
			return m_pGame;
		}
		return m_pGame;
	}
	~Game() {}
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	bool init(const char* title, int xpos, int ypos, 
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running();
	bool CheckBound(int x, int y, int width, int height);


private:
	static Game* m_pGame;
	Game() {}
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	int m_currentFrame;

	
	std::vector<GameObject*> m_gameObjects;

	SDL_Texture* m_pTexture; // the new SDL_Texture variable
	SDL_Rect m_sourceRectangle; // 원본 사각형 
	SDL_Rect m_destinationRectangle; // 대상 사각형 

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
};