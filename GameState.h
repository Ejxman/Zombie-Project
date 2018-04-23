#pragma once

//enum direction : char { left = 'l', right = 'r' };

enum class State { MENU, LEVEL, PAUSE, CREDITS };

class GameState
{
public:
	//GameState();

	void setCurrentState(State s);
	State getCurrentState();

	enum GState { MENU, LEVEL, PAUSE, CREDITS };

protected:
	State currentState;
};