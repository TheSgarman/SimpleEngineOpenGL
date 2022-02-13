
#include "Character.h"
#include "SpriteComponent.h"
#include "Assets.h"
#include "InputComponent.h"
#include "Maths.h"
#include "Laser.h"

Character::Character() : Actor(), laserCooldown(0.0f)
{
	SpriteComponent* sc = new SpriteComponent(this, Assets::getTexture("Character"));
	InputComponent* ic = new InputComponent(this);
	ic->setMaxForwardSpeed(300.0f);
	ic->setMaxAngularSpeed(Maths::twoPi);
	ic->setMaxWarpDistance(500.0f);
}

void Character::actorInput(const Uint8* keyState)

{
	if (keyState[SDL_SCANCODE_SPACE] && laserCooldown <= 0.0f)
	{
		Laser* laser = new Laser();
		laser->setPosition(getPosition());
		laser->setRotation(getRotation());
		laserCooldown = 0.5f;
	}
}

void Character::updateActor(float dt)
{
	laserCooldown -= dt;
	
}