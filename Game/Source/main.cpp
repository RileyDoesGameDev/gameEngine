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
#include "Enamy.h"
#include "SpaceGame.h"

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

    while (!g_engine.IsQuit())
    {
        g_engine.Update();
        game->Update(g_engine.GetTime().GetDeltaTime()); 
        g_engine.GetRenderer().SetColor(1,0,0,0);
        g_engine.GetRenderer().BegineFrame();
        game->Draw(g_engine.GetRenderer());
       // g_engine.GetPs().Draw(g_engine.GetRenderer());

        g_engine.GetRenderer().EndFrame();


    }
    g_engine.Shutdown();
    return 0;
}