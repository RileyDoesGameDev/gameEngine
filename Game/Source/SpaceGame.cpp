#include "SpaceGame.h"
#include "GameData.h"
#include "Enemy.h"
#include "Scene.h"
#include "Engine.h"
#include "Player.h"
#include "PickUp.h"
#include "Font.h"
#include "Text.h"
#include "Model.h"

#include "Random.h"
#include <string>
#include <iostream>


bool SpaceGame::Initialize()
{
   m_scene = new Scene(this);
  m_font = new Font();
  m_largeFont = new Font();

  


  g_engine.GetAudio().AddSound("Title.mp3");
  g_engine.GetAudio().AddSound("gameOver.mp3");
  g_engine.GetAudio().AddSound("playerDeath.mp3");
  g_engine.GetAudio().AddSound("laser.mp3");
  g_engine.GetAudio().AddSound("background music.mp3");
  g_engine.GetAudio().AddSound("pointCollect.mp3");

 m_font-> Load("Quick Dragon.otf", 50);
 m_largeFont-> Load("Quick Dragon.otf",100);

 m_textScore = new Text(m_font);
 m_textLives = new Text(m_font);
 m_textTitle = new Text(m_largeFont);
 m_textLiveTime = new Text(m_font);
 m_textGameOver = new Text(m_largeFont);



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
    {
        std::string Title = "Title.mp3";
        g_engine.GetAudio().PlaySound(Title);
        if (m_engine->GetInput().GetKeyDown(SDL_SCANCODE_SPACE))
        {
            m_state = eState::StartGame;
        }
    }
        break;
    case eState::StartGame:
        m_score = 0;
        m_lives = 3;
        m_liveTime = 0;
        
        m_state = eState::StartLevel;
        break;
    case eState::StartLevel:
        m_scene->RemoveAll();
    {
            m_enemySpawnCount = 0;
            m_pickupSpawnCount = 0;
            auto scene = std::make_unique<Scene>();
            Transform transform{ {g_engine.GetRenderer().GetWidth() >> 1,g_engine.GetRenderer().GetHeight() >> 1}, 0,5 };

            auto* playerModel = new Model{ GameData::shipPoints, Color{1,1,0,0} };
            auto player = std::make_unique<Player>(800, transform, playerModel);
            player->SetDamping(1.7f);
            player->SetTag("Player");
            m_scene->AddActor(std::move(player));
         
    }
   
    m_spawnTime = 1;
    m_spawnTimer = m_spawnTime;
        m_state = eState::Game;
        break;
    case eState::Game:
        m_spawnTimer -= dt;
       
        if (m_spawnTimer <= 0)
        {
           
            m_liveTime += 1;
            m_spawnTimer -= 0.2f;
            m_spawnTimer = m_spawnTime;

            // crate enemy
            if (m_enemySpawnCount < 5)
            {
                auto* enemyModel = new Model{ GameData::bulletPoints, Color{1,0,0,0} };
                auto enemy = std::make_unique<Enemy>(80, Transform{ {random(g_engine.GetRenderer().GetWidth()),random(g_engine.GetRenderer().GetHeight())},0,3 }, enemyModel);
                enemy->SetTag("Enemy");
                enemy->SetDamping(1.0f);
                m_scene->AddActor(std::move(enemy));
                m_enemySpawnCount++;
            }
            // create pickup
            if (m_pickupSpawnCount <5)
            {
            auto* pickupModel = new Model{GameData::bulletPoints, Color{0,1,1,0}};
            auto pickup = std::make_unique<PickUp>(Transform{ {random(g_engine.GetRenderer().GetWidth()),random(g_engine.GetRenderer().GetHeight())},0,3 }, pickupModel);
            pickup->SetTag("Pickup");
            pickup->SetDamping(1.0f);
            m_scene->AddActor(std::move(pickup));

            
                m_pickupSpawnCount++;
            }
            
          
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
        
        m_scene->RemoveAll();
        if (m_engine->GetInput().GetKeyDown(SDL_SCANCODE_R))
        {
        m_state = eState::StartGame;
        }
        else if (m_engine->GetInput().GetKeyDown(SDL_SCANCODE_TAB))
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
        m_textTitle->Create(renderer, "The Most Amazing Space Game", Color{ 1,0,0,0 });
        m_textTitle->Draw(renderer, g_engine.GetRenderer().GetWidth()/15, g_engine.GetRenderer().GetHeight()/15);
        //draw titel
        break;
    case SpaceGame::eState::GameOver:
        m_textGameOver->Create(renderer, "Game Over", Color(0, 1, 0, 0));
        m_textGameOver->Draw(renderer, g_engine.GetRenderer().GetWidth()/5, g_engine.GetRenderer().GetHeight()/3);

        break;
    case SpaceGame::eState::Game:
        {
            // draw score
        std::string text = "Score: " + std::to_string(m_score);
        m_textScore->Create(renderer, text,Color (1, 1, 0, 0));
        m_textScore->Draw(renderer, 20, 20);
        //draw lives
        text = "Lives: " + std::to_string(m_lives);
        m_textLives->Create(renderer, text, Color(0, 1, 0, 0));
        m_textLives->Draw(renderer, 200, 20);

        text = "Time: " + std::to_string(m_liveTime);
        m_textLiveTime->Create(renderer, text, Color(0, 1, 0, 0));
        m_textLiveTime->Draw(renderer, 400, 20);
    }
        break;

    default:
        break;
    }


    
    
    m_scene->Draw(renderer);
}

void SpaceGame::OnPlayerDeath()
{
    m_lives--;
    m_state =(m_lives <= 0) ? eState::GameOver : eState::PlayerDead;
    m_stateTimer = 3;
}
