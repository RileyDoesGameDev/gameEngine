#include "Particle.h"



void Particle::Initialize(const Data& data)
{
	isActive = true;
	position = data.position;
	velocity = data.velocity;
	lifespan = data.lifespan;
	red		 = data.red;
	green    = data.green;
	blue     = data.blue;
	alpha    = data.alpha;
}

void Particle::update(float deltaTime)
{
	position = position + (velocity * deltaTime);


	if (lifespan != 0)
	{
		lifespan -= deltaTime;
	}


}

void Particle::Draw(Renderer& renderer)
{
	if (lifespan > 0)
	{
		renderer.SetColor(red, green, blue, alpha);
		renderer.DrawRect(position.x, position.y,4.0f,4.0f);
	}
}
