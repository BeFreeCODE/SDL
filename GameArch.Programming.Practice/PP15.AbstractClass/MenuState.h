#pragma once
#include "GameState.h"
class MenuState :public GameState
{
public:
	MenuState(void);
	virtual ~MenuState(void);

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_menuID; }
private:
	static const std::string s_menuID;
};

