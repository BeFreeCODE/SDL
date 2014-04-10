#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* pParams);
	virtual ~Player();

    void draw();;
    void update();
    void clean();
};