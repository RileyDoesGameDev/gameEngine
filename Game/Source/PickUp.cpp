#include "PickUp.h"
#include "Player.h"
#include "Scene.h"
#include "Game.h"
#include "Engine.h"
#include <string>


void PickUp::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Player")
	{ 
	m_scene->GetGame()->AddPoints(100);
	std::string str = "pointCollect.mp3";
	g_engine.GetAudio().PlaySound(str);
	m_destroyed = true;
		
	}
}     