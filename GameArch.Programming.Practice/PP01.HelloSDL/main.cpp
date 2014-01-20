#include<SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{
    // SDL �ʱ�ȭ
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
	// �ʱ�ȭ �����ϸ�, window ����
	g_pWindow = SDL_CreateWindow("PP01.HelloSDL",
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED,
		640, 480, SDL_WINDOW_SHOWN);
  	// window ������ �����ϸ�, renderer ���� 
	if(g_pWindow != 0) {	
	      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
	}
    } else {
	return 1; // sdl could not initialize
    }

     // �� (R,G,B,A) ���� 
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);           
    SDL_RenderClear(g_pRenderer);      // �����츦 ������ ������ ���� 
    SDL_RenderPresent(g_pRenderer);   // ������ ���̱�
    SDL_Delay(5000);                          // 5�� ���� ����
    SDL_Quit();                                   //  SDL ���� 
    return 0;
}
