#include<SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{
    // SDL 초기화
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
	// 초기화 성공하면, window 생성
	g_pWindow = SDL_CreateWindow("PP01.HelloSDL",
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED,
		640, 480, SDL_WINDOW_SHOWN);
  	// window 생성을 성공하면, renderer 생성 
	if(g_pWindow != 0) {	
	      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
	}
    } else {
	return 1; // sdl could not initialize
    }

     // 색 (R,G,B,A) 지정 
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);           
    SDL_RenderClear(g_pRenderer);      // 윈도우를 지정된 색으로 지움 
    SDL_RenderPresent(g_pRenderer);   // 윈도우 보이기
    SDL_Delay(5000);                          // 5초 동안 지연
    SDL_Quit();                                   //  SDL 정리 
    return 0;
}
