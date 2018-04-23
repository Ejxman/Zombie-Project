#pragma once
#include "Mysprite.h"

class Player : public Mysprite
{
public:
	Player();
	~Player();

	void update(float dt);
};