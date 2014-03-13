#pragma once
#include "GameState.h"
class PlayState : public GameState
{
public:
	PlayState(void);
	virtual ~PlayState(void);

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }
private:
	static const std::string s_playID;
};

