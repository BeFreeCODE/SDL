#include "Game.h"
#include <iostream>
#include "TextureManager.h"
#include "Enemy.h"

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

		if(!GlobalTextureManager::Instance()->load("../Assets/animate.png",
			"animate", m_pRenderer))
		{
			return false;
		}

		m_go = new GameObject;
		m_player = new Player;
		m_enemy = new Enemy;

		m_go->load(100, 100, 128, 82, "animate");
		m_player->load(300, 300, 128, 82, "animate");
		m_enemy->load(0, 0, 128, 82, "animate");

		m_gameObjects.push_back(m_go);
		m_gameObjects.push_back(m_player);
		m_gameObjects.push_back(m_enemy);

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
	SDL_RenderClear(m_pRenderer); // clear to the draw colour
	for(std::vector<GameObject*>::size_type i = 0; 
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(m_pRenderer);
	}
	SDL_RenderPresent(m_pRenderer); // draw to the screen
}
void Game::update()
{
	for(std::vector<GameObject*>::size_type i = 0; 
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
void Game::clean()
{
	for(std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		delete m_gameObjects[i];
		m_gameObjects[i] = nullptr;
	}
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