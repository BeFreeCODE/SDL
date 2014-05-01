#pragma once
#include "Vector2D.h"
#include "SDLGameObject.h"
class MoveEvent
{
public:
	MoveEvent(void);
	~MoveEvent(void);

	bool SetEvent(SDLGameObject* obj,Vector2D target);
	void Do();
	bool IsComplete();
private:
	Vector2D m_targetPos;
	SDLGameObject* m_targetObj;

	bool m_isComplete;
};

