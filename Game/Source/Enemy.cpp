#include "Enemy.h"
#include "Player.h"
#include "Scene.h"
#include "Game.h"
#include "random.h"
#include "ParticleSystem.h"
#include"Engine.h"
#include "GameData.h"
#include "Bullet.h"
void Enemy::Update(float dt)
{
	Player* player = m_scene->GetActor<Player>();

	if (player)
	{
		Vector2 direction = player->GetTransform().position - m_transform.position;
		m_velocity += direction.Normalized() * m_speed * dt;
		m_transform.rotation = direction.Angle();
	}
	Actor::Update(dt);


	m_fireTimer -= dt;

	if (m_fireTimer <= 0)
	{
		m_fireTimer = 5.0f;

		if (player)
		{
			Vector2 direction = player->GetTransform().position;
			float angle = direction.Angle();
			
		


			// actor

			Model* model = new Model{ GameData::bulletPoints, Color{ 1, 1, 1,0 } };
			Transform transform{ m_transform.position, angle, 1.0f };
			auto bullet = std::make_unique<Bullet>(200.0f, transform, model);
			bullet->SetLifespan(2);
			bullet->SetTag("EnemyBullet");
			m_scene->AddActor(std::move(bullet));
		}

	}





}


void Enemy::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Player")
	{
		
		m_destroyed = true;
		
	}
}
