#include "Partical.h"



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
