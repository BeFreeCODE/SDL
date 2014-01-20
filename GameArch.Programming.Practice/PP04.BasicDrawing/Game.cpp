#include "Game.h"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, 
	int width, int height, bool fullscreen)
{
	// ���� �߰��� �� �� 
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
		SDL_Surface* pTempSurface = SDL_LoadBMP("../Assets/rider.bmp");
		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,  
			pTempSurface);
		SDL_FreeSurface(pTempSurface);

		SDL_QueryTexture(m_pTexture, NULL, NULL, 
			&m_sourceRectangle.w, &m_sourceRectangle.h);

	}
	else
	{
		return false; // SDL init fail
	}

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // draw color�� render �����
	SDL_RenderPresent(m_pRenderer); // ȭ�� �����ϱ�

	m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	// clear the renderer to the draw color
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer,  m_pTexture,
		&m_sourceRectangle, &m_destinationRectangle);
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

bool Game::running()
{
	return m_bRunning; 
}