#include "Game.h"

Game* g_game = 0; // our Game object

int main(int argc, char* argv[])
{
	Game* instance = GlobalGame::Instance();
	instance->init("Chapter 9", 100, 100, 640, 480, false);

	while(instance->running())
	{
		instance->handleEvents();
		instance->update();
		instance->render();
		SDL_Delay(10); // add the delay
	}
	instance->clean();
	return 0; 
}