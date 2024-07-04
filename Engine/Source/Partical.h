#pragma once
#include "Vector2.h"
#include"Renderer.h"
struct Particle
{
	Vector2 position{ 0, 0 };
	Vector2 velocity{ 0, 0 };;
	float lifespan{ 0 };
	uint8_t red{ 0 }, green{ 0 }, blue{ 0 }, alpha{0};

	Particle() = default;
	


	Particle(Vector2 position, Vector2 velocity) : 
		position{ position }, 
		velocity{velocity} 
	{}
	Particle(Vector2 position, Vector2 velocity, float lifespan) : 
		position{ position }, 
		velocity{velocity}, 
		lifespan{lifespan}
	{}
	Particle(Vector2 position, Vector2 velocity, float lifespan, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) :
		position{ position },
		velocity{ velocity },
		lifespan{ lifespan },
		red{ red },
		green{ green },
		blue{blue},
		alpha{alpha}
	{}

	void update(float deltaTime);
	void Draw(Renderer& renderer);
	

};