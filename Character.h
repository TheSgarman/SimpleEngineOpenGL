#pragma once
#include "Actor.h"
#include <SDL_stdinc.h>

class Character : public Actor
{
public:
	Character();

	void actorInput(const Uint8* keyState) override;
	void updateActor(float dt) override;

private:
	float laserCooldown;
};
