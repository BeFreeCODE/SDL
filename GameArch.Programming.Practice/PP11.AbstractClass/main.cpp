#include "Game.h"
#include <iostream>

Game* g_game = 0; // our Game object

int main(int argc, char* argv[])
{
	std::cout<<"game init attempt...\n";
	Game* instance = GlobalGame::Instance();
	if(instance->init("Chapter 8", 100, 100, 640, 480, false))
	{
		std::cout<<"game init success!\n";
		while(instance->running())
		{
			instance->handleEvents();
			instance->update();
			instance->render();
			SDL_Delay(10); // add the delay
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