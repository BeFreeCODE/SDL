#include <SDL.h>
#include <string>

#pragma once

class LoaderParams;
class GameObject
{
public:
	GameObject();
	
	virtual void load(int x, int y, int width, int height, 
                                std::string textureID);
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean();
protected:
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject();
	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};
