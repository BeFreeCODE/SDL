#include "Game.h"
#include <SDL_image.h>
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
		m_textureManager.load("../Assets/animate-alpha.png","animate",m_pRenderer);

		//SDL_SetRenderDrawColor(m_pRenderer,255,0,0,255);
		m_currentFrame = 0;
	}
	else
	{
		return false; // SDL init fail
	}

	return true;
}

void Game::render()
{
	// clear the renderer to the draw color
	SDL_RenderClear(m_pRenderer);
	m_textureManager.draw("animate",0,0,128,82,m_pRenderer);
	m_textureManager.drawFrame("animate",100,100,128,82,1,m_currentFrame,m_pRenderer);
	
	SDL_RenderPresent(m_pRenderer); // draw to the screen
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

void Game::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

bool Game::running()
{
	return m_bRunning; 
}