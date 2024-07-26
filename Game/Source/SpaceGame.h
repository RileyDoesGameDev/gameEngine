#pragma once
#include "Game.h"
class Font;
class Text;
class Auido;
class SpaceGame : public Game
{
public:
	enum class eState : char
	{
		Title,
		StartGame,
		StartLevel,
		Game,
		PlayerDead,
		GameOver
	};

public:
	SpaceGame(Engine* engine): Game{engine} {}
	bool Initialize() override;

	void Shutdown() override;

	void Update(float dt) override;

	void Draw(Renderer& renderer) override;

	void OnPlayerDeath();


	
private:

	eState m_state{ eState::Title };
	float m_stateTimer{ 0 };
	float m_spawnTimer{ 0 };
	float m_spawnTime{ 0 };
	int m_pickupSpawnCount{ 0 };
	int m_enemySpawnCount{ 0 };

	int m_liveTime{ 0 };

	Font* m_font{ nullptr };
	Font* m_largeFont{ nullptr };
	Text* m_textScore{ nullptr };
	Text* m_textLives{ nullptr };
	Text* m_textTitle{ nullptr };
	Text* m_textLiveTime{ nullptr };
	Text* m_textGameOver{ nullptr };

	

};
