#pragma once
#include "SDLGameObject.h"
#include "MoveEvent.h"
class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);
	virtual ~Enemy(void);

	void handleInput();
	void draw();
	void update();
	void clean();

	MoveEvent m_moveEvent;
};

