#pragma once
#include "SDLGameObject.h"

class BackGround : public SDLGameObject
{
public:
	BackGround(const LoaderParams* pParams);
	virtual ~BackGround(void);

    void draw();
    void update();
    void clean();
};

