#include "Renderer.h"
#include "Vector2.h"
#include "Particle.h"
#include "Etimer.h"
#include "input.h"
#include "Random.h"
#include "MathUtils.h"
#include "Model.h"
#include "Color.h"
#include "Transform.h"
#include "Engine.h"
#include "Player.h"
#include "Scene.h"
#include "Enemy.h"
#include "SpaceGame.h"
#include "Font.h"
#include "Text.h"


#include <fmod.hpp>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <SDL.h>

using namespace std;




int main(int argc, char* argv[])
{

    g_engine.Initialize();
    SpaceGame* game = new SpaceGame(&g_engine);
    game->Initialize();



    Font* font = new Font();
    font->Load("Quick Dragon.otf", 50);

    Text* text = new Text(font);
    text->Create(g_engine.GetRenderer(), "Hello World", Color{ 1, 1, 1, 1 });

    while (!g_engine.IsQuit())
    {
        g_engine.Update();
        game->Update(g_engine.GetTime().GetDeltaTime()); 
        g_engine.GetRenderer().SetColor(1,0,0,0);
        g_engine.GetRenderer().BegineFrame();
        text->Draw(g_engine.GetRenderer(), 200, 200);
        game->Draw(g_engine.GetRenderer());
        g_engine.GetPS().Draw(g_engine.GetRenderer());

        g_engine.GetRenderer().EndFrame();

    }
    g_engine.Shutdown();
    return 0;
}