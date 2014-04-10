#pragma once
#include "SDLGameObject.h"
class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);
	virtual ~Enemy(void);

public:
	void draw();
	void update();
	void clean();
};

