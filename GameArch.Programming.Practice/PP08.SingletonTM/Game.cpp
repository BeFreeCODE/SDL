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
			SDL_SetRenderDrawColor(m_pRenderer, 255,0,0,255);
		}
		else
		{

		}
		//SDL_Surface* pTempSurface = SDL_LoadBMP("../Assets/animate.bmp");
		if(!TheTextureManager::Instance()->load("../Assets/animate-alpha.png",
			"animate", m_pRenderer))
		{
			return false;
		}

		if(!TheTextureManager::Instance()->load("../Assets/jungle.png","jungle",m_pRenderer))
		{
			return false;
		}
		//m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

		//SDL_FreeSurface(pTempSurface);

		m_sourceRectangle.w = 128;
		m_sourceRectangle.h = 82;

		m_destinationRectangle.x = m_sourceRectangle.x = 0;
		m_destinationRectangle.y = m_sourceRectangle.y = 0;
		m_destinationRectangle.w = m_sourceRectangle.w;
		m_destinationRectangle.h = m_sourceRectangle.h;
		/*

		SDL_QueryTexture(m_pTexture, NULL, NULL, 
		&m_sourceRectangle.w, &m_sourceRectangle.h);*/

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
	TheTextureManager::Instance()->draw(m_pRenderer,"jungle",400,300,1600,622);
	TheTextureManager::Instance()->draw(m_pRenderer,"animate", 0,0, 128, 82);

	TheTextureManager::Instance()->drawFrame(m_pRenderer,"animate", 100,100, 
		128, 82, 1,   m_currentFrame);

	
	SDL_RenderPresent(m_pRenderer);
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
	const Uint8* state = SDL_GetKeyboardState(nullptr);
	
	if(state[SDL_SCANCODE_D])
	{
		printf("d input");
	}
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

bool Game::running()
{
	return m_bRunning; 
}