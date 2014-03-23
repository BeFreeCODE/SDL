#include "Game.h"
#include <iostream>

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
		}
		else
		{
			
		}
	}
	else
	{
		return false; // SDL init fail
	}

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // draw color로 render 지우기
	SDL_RenderPresent(m_pRenderer); // 화면 제시하기
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
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break; 
		}
	} 
}

bool Game::running()
{
	return m_bRunning; 
}