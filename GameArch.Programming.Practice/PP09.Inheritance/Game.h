#pragma once
#include "SDL.h"
#include "Player.h"
#include "BackGround.h"

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

	BackGround m_bg;
	GameObject m_go;
	Player m_player;
};