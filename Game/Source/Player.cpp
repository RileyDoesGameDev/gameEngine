#include "Player.h"
#include "Engine.h"
#include "Scene.h"
#include "Model.h"
#include "Bullet.h"
#include "SpaceGame.h"
#include "GameData.h"

void Player::Update(float dt)
{
    //movement
    float thrust = 0;
    Vector2 direction{ 0,0 };
    Vector2 acceleration = { 0,0 };

    if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_A))
    {
        direction.x = -1;
        thrust = direction.x * m_speed;
        acceleration = Vector2{ 1.0f,0.0f } *thrust;
    }

    if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_D))
    {
        direction.x = 1;
        thrust = direction.x * m_speed;
        acceleration = Vector2{ 1.0f,0.0f } *thrust;
    }

    if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_S))
    {
     direction.y = 1;
     thrust = direction.y * m_speed;
     acceleration = Vector2{ 0.0f,1.0f } *thrust;
    }

    if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_W))
    {
     direction.y = -1;
     thrust = direction.y * m_speed;
     acceleration = Vector2{ 0.0f,1.0f } *thrust;
    }

    

    m_velocity += acceleration * dt;
  
    m_transform.position.x = Math::Wrap(m_transform.position.x, (float)g_engine.GetRenderer().GetWidth());
    m_transform.position.y = Math::Wrap(m_transform.position.y, (float)g_engine.GetRenderer().GetHeight());

    //Fire
   
    Actor::Update(dt);
}

void Player::OnCollision(Actor* actor)
{
    if (actor->GetTag() == "Enemy"|| actor->GetTag()=="EnemyBullet")
    {
    m_destroyed = true;
    dynamic_cast<SpaceGame*>(m_scene->GetGame())->OnPlayerDeath();
    }
   
}
