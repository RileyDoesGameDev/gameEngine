#include "Enamy.h"
#include "Player.h"
#include "Scene.h"
#include "Game.h"

void Enamy::Update(float dt)
{
	Player* player = m_scene->GetActor<Player>();

	if (player)
	{
		Vector2 direction = player->GetTransform().position - m_transform.position;
		m_velocity += direction.Normalized() * m_speed * dt;
		m_transform.rotation = direction.Angle();
	}
	Actor::Update(dt);
}

void Enamy::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Player")
	{
		m_scene->GetGame()->AddPoints(100);
		m_destroyed = true;
		
	}
}
