#include "Renderer.h"
#include "Vector2.h"
#include "Partical.h"
#include "Etimer.h"
#include"input.h"
#include "Random.h"
#include "MathUtils.h"

#include <fmod.hpp>
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
    float offset = 0;
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
            particles.push_back(Particle
                { mousePosition, 
                randomOnUnitCircle() * randomf(50,200),
                randomf(5), 
                (uint8_t)random(1,255),
                (uint8_t)random(1,255),
                (uint8_t)random(1,255),
                (uint8_t)random(1,255)
                });
            
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

       //s renderer.SetColor(255, 255, 255, 255);
        for (Particle particle : particles)
        {
            particle.Draw(renderer);

        }

        renderer.SetColor(255, 255, 255, 0);
        float radious = 60;
        offset += (1 * time.GetDeltaTime());
        for (float angle = 0; angle < 360; angle += 360 / 30)
        {

            
            float x = Math::Cos(Math::DegToRad(angle))* Math::Sin(offset+ .05)* radious;
            float y = Math::Sin(Math::DegToRad(angle)) * Math::Sin(offset+ .05)* radious;
                renderer.DrawRect(400 + x, 300+ y, 4.0f, 4.0f);
        }



        renderer.EndFrame();

    }
    return 0;
}