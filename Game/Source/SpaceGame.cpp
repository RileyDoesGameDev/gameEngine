#include "SpaceGame.h"
#include "GameData.h"
#include "Enamy.h"
#include "Scene.h"
#include "Engine.h"
#include "Player.h"
#include "PickUp.h"
#include "Font.h"
#include "Text.h"
#include "Model.h"


bool SpaceGame::Initialize()
{
    m_scene = new Scene(this);
   m_font = new Font();
 m_font-> Load("arcaseClassic.ttg", 20);
 m_font->Load("Putfontherer",1);

 m_textLives;
    return true;
}

void SpaceGame::Shutdown()
{
}

void SpaceGame::Update(float dt)
{

    switch (m_state)
    {
    case eState::Title:
        m_textTitle->Create(g_engine.GetRenderer(), "", Color{1,0,0,0});
        if (m_engine->GetInput().GetKeyDown(SDL_SCANCODE_SPACE))
        {
            m_state = eState::StartGame;
        }

        break;
    case eState::StartGame:
        m_score = 0;
        m_lives = 3;

        m_state = eState::StartLevel;
        break;
    case eState::StartLevel:
        m_scene->RemoveAll();
    {
        
        Transform transform{ {g_engine.GetRenderer().GetWidth() >> 1,g_engine.GetRenderer().GetHeight() >> 1}, 0,5 };
        auto model = std::make_unique<Model>( GameData::shipPoints, Color{0,1,0,0} );
        auto player = std::make_unique<Player>(50, transform, model);
        player->SetDamping(1.7f);

        player->SetTag("Player");
        Scene* scene = new Scene();
        scene->AddActor(std::move(player));
    }
        m_spawnTime = 3;
        m_spawnTimer = m_spawnTime;
        m_state = eState::Game;
        break;
    case eState::Game:
        m_spawnTimer -= dt;
        if (m_spawnTimer <= 0)
        {
            m_spawnTimer -= 0.2f;
            m_spawnTimer = m_spawnTime;
            // crate enemy
            auto* enemyModel = new Model{ GameData::shipPoints, Color{1,0,0,0} };
            auto enemy = std::make_unique<Enamy>(800, Transform{ {300,300},0,3 }, enemyModel);
            enemy->SetTag("Enemy");
            enemy->SetDamping(1.0f);
            m_scene->AddActor(std::move(enemy));

            // create pickup

            auto* pickupModel = new Model{GameData::shipPoints, Color{0,1,1,0}};
            auto pickup = std::make_unique<PickUp>(Transform{ {300,300},0,3 }, pickupModel);
            pickup->SetTag("Pickup");
            pickup->SetDamping(1.0f);
            m_scene->AddActor(std::move(pickup));
        }
        break;
    case eState::PlayerDead:
        m_stateTimer -= dt;
        if (m_stateTimer <= 0)
        {
        m_state = eState::StartLevel;
        }

        break;
    case eState::GameOver:
        m_stateTimer -= dt;
        if (m_stateTimer <= 0)
        {
        m_state = eState::Title;
        }
        break;
    default:
        break;
    }
    m_scene->Update(dt);
}

void SpaceGame::Draw(Renderer& renderer)
{

    switch (m_state)
    {
    case SpaceGame::eState::Title:
        //draw titel
        break;
    case SpaceGame::eState::GameOver:
        // draw Game over
        break;
    default:
        break;
    }


    // draw score 
    std::string text = "Score" + std::to_string(m_score);
    m_textScore->Create(renderer, text,Color (1, 1, 0, 0));
    m_textScore->Draw(renderer, 20, 20);
    //draw lives
    text = "Lives" + std::to_string(m_score);
    m_textLives->Create(renderer, text, Color(0, 1, 0, 0));
    m_textLives->Draw(renderer, 20, 20);
    m_scene->Draw(renderer);
}

void SpaceGame::OnPlayerDeath()
{
    m_lives--;
    m_state =(m_lives == 0) ? eState::GameOver : eState::PlayerDead;
    m_stateTimer = 3;
}
