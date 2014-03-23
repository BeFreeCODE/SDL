#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* pParams);
	virtual ~Player();

	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	void handleInput();
};