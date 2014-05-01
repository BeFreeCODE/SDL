#include "MoveEvent.h"


MoveEvent::MoveEvent(void)
	: m_targetPos(0,0),
	m_isComplete(true)
{
}


MoveEvent::~MoveEvent(void)
{
}

bool MoveEvent::SetEvent(SDLGameObject* obj,Vector2D target)
{
	m_targetObj = obj;
	m_targetPos = target;
	m_isComplete = false;
	return true;
}
void MoveEvent::Do()
{
	if(m_targetPos == m_targetObj->getPosition())
	{
		m_isComplete = true;
	}
}

bool MoveEvent::IsComplete()
{
	return m_isComplete;
}