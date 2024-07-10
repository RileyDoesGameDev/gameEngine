#include "Renderer.h"
#include "Vector2.h"
#include "Partical.h"
#include "Etimer.h"
#include"input.h"
#include "Random.h"
#include "MathUtils.h"
#include "Model.h"
#include "Color.h"

#include <fmod.hpp>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <SDL.h>

using namespace std;




int main(int argc, char* argv[])
{




    // Audio

      // create audio system
    FMOD::System* audio;
    FMOD::System_Create(&audio);

    void* extradriverdata = nullptr;
    audio->init(32, FMOD_INIT_NORMAL, extradriverdata);


   FMOD::Sound* sound = nullptr;
   
   std::vector<FMOD::Sound*> sounds;

   audio->createSound("bass.wav", FMOD_DEFAULT, 0, &sound);
   sounds.push_back(sound);

   audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound);
   sounds.push_back(sound);

   audio->createSound("open-hat.wav", FMOD_DEFAULT, 0, &sound);
   sounds.push_back(sound);

   audio->createSound("cowbell.wav", FMOD_DEFAULT, 0, &sound);
   sounds.push_back(sound);

   audio->createSound("clap.wav", FMOD_DEFAULT, 0, &sound);
   sounds.push_back(sound);

   audio->createSound("close-hat.wav", FMOD_DEFAULT, 0, &sound);
   sounds.push_back(sound);

 




    //audio->createSound("test.wav", FMOD_DEFAULT, 0, &sound);

   
    //audio->playSound(sound, 0, false, nullptr);


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

   // std::vector<Vector2> points;
   // points.push_back(Vector2{ -5, 5 });
   // points.push_back(Vector2{ 0, -5 });
   // points.push_back(Vector2{ 5, 5 });
   // points.push_back(Vector2{ -5, 5 });
   // Model model{ points, Color{1, 1, 1, 0} };
   // Vector2 position{ 400, 300 };



    bool quit = false;
    while (!quit)
    {




        //Draw model
      //  model.Draw(renderer, { 400,300 }, 0, 1);


        time.Tick();
      
        // INPUT
        input.update();
        if (input.GetKeyDown(SDL_SCANCODE_ESCAPE))
        {
            quit = true;
        }

        if (input.GetKeyDown(SDL_SCANCODE_Q) && !input.GetPrevKeyDown(SDL_SCANCODE_Q))
    
    {
            audio->playSound(sounds[0], 0, false, nullptr);
    }
        
        if (input.GetKeyDown(SDL_SCANCODE_W) && !input.GetPrevKeyDown(SDL_SCANCODE_W))
    
    {
            audio->playSound(sounds[1], 0, false, nullptr);
    }
         
        if (input.GetKeyDown(SDL_SCANCODE_E) && !input.GetPrevKeyDown(SDL_SCANCODE_E))
    
    {
            audio->playSound(sounds[2], 0, false, nullptr);
    }

          if (input.GetKeyDown(SDL_SCANCODE_R) && !input.GetPrevKeyDown(SDL_SCANCODE_R))
    
    {
            audio->playSound(sounds[3], 0, false, nullptr);
    }

          if (input.GetKeyDown(SDL_SCANCODE_T) && !input.GetPrevKeyDown(SDL_SCANCODE_T))
    
    {
            audio->playSound(sounds[4], 0, false, nullptr);
    }

          if (input.GetKeyDown(SDL_SCANCODE_Y) && !input.GetPrevKeyDown(SDL_SCANCODE_Y))
    
    {
            audio->playSound(sounds[5], 0, false, nullptr);
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



        audio->update();

        renderer.EndFrame();

    }
    return 0;
}