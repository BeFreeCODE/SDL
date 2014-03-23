#pragma once
#include "GameObject.h"
#include <SDL.h>
#include <string>
#include "Vector2D.h"

//SDL library를 이용하는 게임오브젝트
class SDLGameObject : public GameObject
{
public:
	virtual void draw();
	virtual void update();
	virtual void clean();

protected:
	SDLGameObject(const LoaderParams* pParams);
	~SDLGameObject(void);

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;
};

