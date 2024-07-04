#include "Renderer.h"
#include "Vector2.h"
#include "Partical.h"
#include "Etimer.h"
#include"input.h"
#include "Random.h"

#include <vector>
#include <iostream>
#include <cstdlib>
#include <SDL.h>

using namespace std;

int main(int argc, char* argv[])
{

    // create systems
    Renderer renderer;
    renderer.Initialize();
    renderer.CreateWindow("Engine", 800, 600);

    Input input;
    input.Initialize();

    Time time;


    std::vector<Particle> particles;
    
       // particles.push_back(Particle{ {rand() % 800, rand() % 600},{randomf(0.1f,1.0f), 0.0f} });
       // particles.clear();

    bool quit = false;
    while (!quit)
    {
        time.Tick();
      
        // INPUT
        input.update();
        if (input.GetKeyDown(SDL_SCANCODE_ESCAPE))
        {
            quit = true;
        }


        // UPDATE
        Vector2 mousePosition = input.GetMousePosition();

        if (input.GetMouseButtonDown(0))
        {
            particles.push_back(Particle{ mousePosition, {randomf(-100,100),randomf(-100,100)}, randomf(5) });
            
        }

        for (Particle& particle : particles)
        {
            particle.update(time.GetDeltaTime());

            if (particle.position.x > 800) particle.position.x = 0;
            if (particle.position.x < 0) particle.position.x = 800;
        }

        

        //DRAW

        renderer.SetColor(0, 0, 0, 0);
        renderer.BegineFrame();

        renderer.SetColor(255, 255, 255, 255);
        for (Particle particle : particles)
        {
            particle.Draw(renderer);

        }

        renderer.EndFrame();

    }
    return 0;
}