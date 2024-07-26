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
    if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_A)) m_transform.rotation -= Math::DegToRad(100) * dt;
    if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_D)) m_transform.rotation += Math::DegToRad(100) * dt;
    if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = -m_speed;
    if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = m_speed;

    Vector2 acceleration = Vector2{ thrust,0.0f }.Rotate(m_transform.rotation) * thrust;
    m_velocity += acceleration * dt;
  
    m_transform.position.x = Math::Wrap(m_transform.position.x, (float)g_engine.GetRenderer().GetWidth());
    m_transform.position.y = Math::Wrap(m_transform.position.y, (float)g_engine.GetRenderer().GetHeight());

    //Fire
    m_fireTimer -=dt;
    if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_SPACE) && m_fireTimer <= 0)
    {
        m_fireTimer = 0.2f * m_fireModifier;
        
        Vector2 direction = g_engine.GetInput().GetMousePosition() - m_transform.position;
        float angle = direction.Angle();
    
        // actor

        Model* model = new Model{ GameData::bulletPoints, Color{ 1, 1, 1,0 } };
        Transform transform{ m_transform.position, angle, 1.0f };
        auto bullet = std::make_unique<Bullet>(400.0f, transform, model);
        bullet->SetLifespan(1);
        bullet->SetTag("PlayerBullet");
        m_scene->AddActor(std::move(bullet));
        
       
    }
    Actor::Update(dt);
}

void Player::OnCollision(Actor* actor)
{
    if (actor->GetTag() == "Enemy")
    {
    m_destroyed = true;
    dynamic_cast<SpaceGame*>(m_scene->GetGame())->OnPlayerDeath();
    }
   
}
