
#pragma once
#include "Actor.h"
class Enamy : public Actor
{
public:
	Enamy() = default;
	Enamy(const Transform& transform) : Actor{ transform } {}
	Enamy(const Transform& transform, Model* model) :
		Actor{ transform ,model }
	{}

	Enamy(float speed, const Transform& transform, Model* model) :
		Actor{ transform ,model },
		m_speed{ speed }
	{}
	void Update(float dt);
	virtual void OnCollision(Actor* actor);

private:

	float m_speed = 0;
	float m_fireTimer = 0;
};