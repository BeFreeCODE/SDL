#pragma once
#include "GameObject.h"
#include <SDL.h>
#include <string>

//SDL library�� �̿��ϴ� ���ӿ�����Ʈ
class SDLGameObject : public GameObject
{
public:
	
	virtual void draw();
	virtual void update();
	virtual void clean();
protected:
	SDLGameObject(const LoaderParams* pParams);
	~SDLGameObject(void);

	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;
};

