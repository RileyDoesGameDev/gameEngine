#pragma once
#include "Actor.h"
class PickUp : public Actor
{
public:
	PickUp() = default;
	PickUp(const Transform& transform,Model* model) :
		Actor{transform,model} {}


	void OnCollision(Actor* actor) override;
	//bool isDestroyed() { return m_destroyed; }
protected:
	
};