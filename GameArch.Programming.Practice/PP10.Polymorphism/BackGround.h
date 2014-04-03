#pragma once
#include "GameObject.h"

class BackGround : public GameObject
{
public:
	BackGround(void);
	~BackGround(void);

	void load(int x, int y, int width, int height, 
                   std::string textureID);
    void draw(SDL_Renderer* pRenderer);
    void update();
    void clean();
};

