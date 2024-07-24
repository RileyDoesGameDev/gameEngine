#pragma once
#include "Renderer.h"
#include "Input.h"
#include "Etimer.h"
#include "Audio.h"
#include <memory>
#include "ParticleSystem.h"



class Engine
{
public:
	Engine() = default;
	~Engine() = default;
	Renderer& GetRenderer() { return *m_renderer; }
	Input& GetInput() { return *m_input; }
	Audio& GetAudio() { return *m_audio; }
	Time& GetTime () { return *m_time; }
	ParticleSystem& GetPS() { return *m_particleSystem; }
	bool Initialize();
	void Shutdown();
	void Update();
	bool IsQuit() const{ return quit; }
private:
	std::unique_ptr<Time> m_time;
	std::unique_ptr<ParticleSystem> m_particleSystem;


	std::unique_ptr<Renderer> m_renderer;
	std::unique_ptr<Input> m_input;
	std::unique_ptr<Audio> m_audio;
	
	bool quit{ false };
};

extern Engine g_engine;

