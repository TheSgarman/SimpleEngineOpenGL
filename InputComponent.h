#pragma once
#include "MoveComponent.h"
#include "Subject.h"
#include <SDL_stdinc.h>

class InputComponent : public MoveComponent, Subject
{
public:


	InputComponent(Actor* ownerP);
	InputComponent() = delete;
	InputComponent(const InputComponent&) = delete;
	InputComponent& operator=(const InputComponent&) = delete;

	void processInput(const Uint8* keyState);

	void setMaxForwardSpeed(float maxForwardSpeedP);
	void setMaxAngularSpeed(float maxAngularSpeedP);
	void setMaxWarpDistance(float maxWarpDistancep);
	void setForwardKey(int key);
	void setBackKey(int key);
	void setClockwiseKey(int key);
	void setCounterClockwiseKey(int key);
	void setWarpKey(int key);
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	void notify(int event);


private:
	float maxForwardSpeed;
	float maxAngularSpeed;
	float maxWarpDistance;

	int forwardKey;
	int backKey;
	int clockwiseKey;
	int counterClockwiseKey;
	int warpKey;




};

