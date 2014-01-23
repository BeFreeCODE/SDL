#include "Game.h"
#include <iostream>

Game* g_game = 0; // our Game object

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int DELAY_TIME = 1000.0f/FPS;

	std::cout<<"game init attempt...\n";
	Game* instance = GlobalGame::Instance();

	Uint32 frameStart, frameTime;

	if(instance->init("Chapter 8", 100, 100, 640, 480, false))
	{
		std::cout<<"game init success!\n";
		while(instance->running())
		{
			frameStart = SDL_GetTicks();
			instance->handleEvents();
			instance->update();
			instance->render();
			frameTime = SDL_GetTicks() - frameStart;
			
			if(frameTime <DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime)); // add the delay
			}
		}
	}
	else
	{
		std::cout<<"game init failed - "<<SDL_GetError() << "\n";
		return -1;
	}
	std::cout<<"game closing...\n";
	instance->clean();
	return 0; 
}