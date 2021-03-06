#include "Game.h"
#include <iostream>
#include "TextureManager.h"

Game* Game::m_pGame = 0;
bool Game::init(const char* title, int xpos, int ypos, 
	int width, int height, bool fullscreen)
{
	// 각자 추가해 볼 것 
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title,xpos,ypos,width,height,fullscreen);
		
		if(m_pWindow != nullptr)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1 , 0 );
			SDL_SetRenderDrawColor(m_pRenderer, 255,255,255,255);
		}
		else
		{

		}

		if(!GlobalTextureManager::Instance()->load("../Assets/animate-alpha.png",
			"animate", m_pRenderer))
		{
			return false;
		}
		if(!GlobalTextureManager::Instance()->load("../Assets/jungle.png","jungle",m_pRenderer))
		{
			return false;
		}
		m_bg.load(0,0,1600,622,"jungle");
		m_go.load(100, 100, 128, 82, "animate");
		m_player.load(300, 300, 128, 82, "animate");
	}
	else
	{
		return false; // SDL init fail
	}

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // draw colour로 지움
	m_bg.draw(m_pRenderer);
	m_go.draw(m_pRenderer);
	m_player.draw(m_pRenderer);
	SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::update()
{
	m_bg.update();
	m_go.update();
	m_player.update();
}
void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
void Game::handleEvents()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			{
				m_bRunning = false;
			}break;
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break; 
		}
	} 
}
bool Game::CheckBound(int x, int y, int width, int height)
{
	//width 640
	//height 480

	if(x < 0)
	{
		return true;
	}
	if(x + width > 640)
	{
		return true;
	}
	if(y < 0)
	{
		return true;
	}
	if(y + height > 480)
	{
		return true;
	}
	
	return false;
}

bool Game::running()
{
	return m_bRunning; 
}