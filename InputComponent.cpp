#pragma once
#include "InputComponent.h"
#include <SDL_scancode.h>

InputComponent::InputComponent(Actor* ownerP) :
	MoveComponent(ownerP),
	maxForwardSpeed(100.0f),
	maxWarpDistance(150.0f),
	maxAngularSpeed(1.0f),
	forwardKey(SDL_SCANCODE_W),
	backKey(SDL_SCANCODE_S),
	clockwiseKey(SDL_SCANCODE_D),
	counterClockwiseKey(SDL_SCANCODE_A),
	warpKey(SDL_SCANCODE_LSHIFT)

	
{
}

void InputComponent::addObserver(Observer* observer) {
	observers.push_back(observer);

}

void InputComponent::removeObserver(Observer* observer) {
	auto iter = find(begin(observers), end(observers), observer);
	if (iter != end(observers)) {
		iter_swap(iter, end(observers) - 1);
		observers.pop_back();
	}
}

void InputComponent::notify(int event) {
	for (int i = 0; i < observers.size(); i++) {
		observers[i]->onNotify(event);
	}
}



void InputComponent::processInput(const Uint8* keyState)
{
	float forwardSpeed = 0.0f;
	if (keyState[forwardKey])
	{
		forwardSpeed += maxForwardSpeed;
	}
	if (keyState[backKey])
	{
		forwardSpeed -= maxForwardSpeed;
	}
	setForwardSpeed(forwardSpeed);

	float angularSpeed = 0.0f;
	if (keyState[clockwiseKey])
	{
		angularSpeed -= maxAngularSpeed;
	}
	if (keyState[counterClockwiseKey])
	{
		angularSpeed += maxAngularSpeed;
	}
	setAngularSpeed(angularSpeed);

	float warpDistance = 10.0f;
	if (keyState[warpKey])
	{
		
		warpDistance += maxWarpDistance;
		
		notify(0);
		
		
		
	}
	setWarpSpeed(warpDistance);
}

void InputComponent::setMaxForwardSpeed(float maxForwardSpeedP)
{
	maxForwardSpeed = maxForwardSpeedP;
}

void InputComponent::setMaxAngularSpeed(float maxAngularSpeedP)
{
	maxAngularSpeed = maxAngularSpeedP;
}

void InputComponent::setMaxWarpDistance(float maxWarpDistanceP)
{
	maxWarpDistance= maxWarpDistanceP;
}

void InputComponent::setForwardKey(int key)
{
	forwardKey = key;
}

void InputComponent::setBackKey(int key)
{
	backKey = key;
}

void InputComponent::setClockwiseKey(int key)
{
	clockwiseKey = key;
}

void InputComponent::setCounterClockwiseKey(int key)
{
	counterClockwiseKey = key;
}

void InputComponent::setWarpKey(int key)
{
	warpKey = key;
}


