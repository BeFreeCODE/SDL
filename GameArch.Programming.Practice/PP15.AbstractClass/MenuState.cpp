#include "MenuState.h"

const std::string MenuState::s_menuID = "MENU";

MenuState::MenuState(void)
{
}


MenuState::~MenuState(void)
{
}


void MenuState::update()
{
}

void MenuState::render()
{
}

bool MenuState::onEnter()
{
	std::cout<<"entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	std::cout<<"exiting MenuState\n";
	return true;
}