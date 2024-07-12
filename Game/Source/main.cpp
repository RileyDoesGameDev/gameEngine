#include "Renderer.h"
#include "Vector2.h"
#include "Partical.h"
#include "Etimer.h"
#include "input.h"
#include "Random.h"
#include "MathUtils.h"
#include "Model.h"
#include "Color.h"
#include "Transform.h"

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
    int width = 800;
    int height = 600;
    Input input;
    input.Initialize();

    Time time;


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

 


   //std::vector<Particle> particles;

    
    


    std::vector<Vector2> points;
    points.push_back(Vector2{3,2});
    points.push_back(Vector2{2,2});
    points.push_back(Vector2{0,1});
    points.push_back(Vector2{-2,2});
    points.push_back(Vector2{-1,0});
    points.push_back(Vector2{-2,-2});
    points.push_back(Vector2{0,-1});
    points.push_back(Vector2{2,-2});
    points.push_back(Vector2{4,-2});
    points.push_back(Vector2{6,-3});
    points.push_back(Vector2{6,-2});
    points.push_back(Vector2{10,-1});

    points.push_back(Vector2{9.9f,-0.975f});
    points.push_back(Vector2{9.8f,-0.7f});
    points.push_back(Vector2{9.5f,-0.875f});
    points.push_back(Vector2{9.2f,-0.8f});
    points.push_back(Vector2{9.1f,-0.525f});
    points.push_back(Vector2{8.8f,-0.7f});
    points.push_back(Vector2{8.5f,-0.625f});
    points.push_back(Vector2{8.4f,-0.35f});
    points.push_back(Vector2{8.1f,-0.525f});
    points.push_back(Vector2{7.8f,-0.45f});
    points.push_back(Vector2{7.7f,-0.175f});
    points.push_back(Vector2{7.4f,-0.35f});
    points.push_back(Vector2{7.1f,-0.275f});
    points.push_back(Vector2{7,0});
    points.push_back(Vector2{6.7f,-0.175f});


    points.push_back(Vector2{6,0});

    points.push_back(Vector2{ 6.7f,0.175f });
    points.push_back(Vector2{ 7,0 });
    points.push_back(Vector2{ 7.1f,0.275f });
    points.push_back(Vector2{ 7.4f,0.35f });
    points.push_back(Vector2{ 7.7f,0.175f });
    points.push_back(Vector2{ 7.8f,0.45f });
    points.push_back(Vector2{ 8.1f,0.525f });
    points.push_back(Vector2{ 8.4f,0.35f });
    points.push_back(Vector2{ 8.5f,0.625f });
    points.push_back(Vector2{ 8.8f,0.7f });
    points.push_back(Vector2{ 9.1f,0.525f });
    points.push_back(Vector2{ 9.2f,0.8f });
    points.push_back(Vector2{ 9.5f,0.875f });
    points.push_back(Vector2{ 9.8f,0.7f });
    points.push_back(Vector2{ 9.9f,0.975f });
   

    points.push_back(Vector2{10,1});
    points.push_back(Vector2{6,2});

    points.push_back(Vector2{7.0f,1.5f});
    points.push_back(Vector2{6.75f,1.6f});
    points.push_back(Vector2{6.5f,1.5f});
    points.push_back(Vector2{6.45f,1.25f});
    points.push_back(Vector2{6.5f,1.0f});
    points.push_back(Vector2{6.75f,0.9f});
    points.push_back(Vector2{7,1});
    points.push_back(Vector2{7.05f,1.25f});
    points.push_back(Vector2{7.0f,1.5f});



    points.push_back(Vector2{ 6,2 });
    points.push_back(Vector2{5,4});
    points.push_back(Vector2{4,2});
    points.push_back(Vector2{3,2});
    points.push_back(Vector2{2.5f,0.0f});
    points.push_back(Vector2{3,-2});
    



    Model model{ points, Color{0,1,0,0} };
    
    Transform transform{ {renderer.GetWidth() >> 1,renderer.GetHeight() >> 1}, 0,15 };

   
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

        //Audio
        if (input.GetKeyDown(SDL_SCANCODE_Q) && !input.GetPrevKeyDown(SDL_SCANCODE_Q))
        {audio->playSound(sounds[0], 0, false, nullptr);}
        
        if (input.GetKeyDown(SDL_SCANCODE_W) && !input.GetPrevKeyDown(SDL_SCANCODE_W))
    {audio->playSound(sounds[1], 0, false, nullptr);}
         
        if (input.GetKeyDown(SDL_SCANCODE_E) && !input.GetPrevKeyDown(SDL_SCANCODE_E))
    {audio->playSound(sounds[2], 0, false, nullptr);}

          if (input.GetKeyDown(SDL_SCANCODE_R) && !input.GetPrevKeyDown(SDL_SCANCODE_R))
    {audio->playSound(sounds[3], 0, false, nullptr);}

          if (input.GetKeyDown(SDL_SCANCODE_T) && !input.GetPrevKeyDown(SDL_SCANCODE_T))
    {audio->playSound(sounds[4], 0, false, nullptr);}

          if (input.GetKeyDown(SDL_SCANCODE_Y) && !input.GetPrevKeyDown(SDL_SCANCODE_Y))
    {audio->playSound(sounds[5], 0, false, nullptr);}


          //Move Player
          float thrust = 0;
          if (input.GetKeyDown(SDL_SCANCODE_LEFT)) transform.rotation -= Math::DegToRad(100) * time.GetDeltaTime();
          if (input.GetKeyDown(SDL_SCANCODE_RIGHT)) transform.rotation += Math::DegToRad(100) * time.GetDeltaTime();
          if (input.GetKeyDown(SDL_SCANCODE_DOWN)) thrust = -400;
          if (input.GetKeyDown(SDL_SCANCODE_UP)) thrust = 400;


          Vector2 velocity = Vector2{ thrust,0.0f }.Rotate(transform.rotation);
          transform.position += velocity * time.GetDeltaTime();
          transform.position.x = Math::Wrap(transform.position.x, (float)renderer.GetWidth());
          transform.position.y = Math::Wrap(transform.position.y, (float)renderer.GetHeight());

          Vector2 mousePosition = input.GetMousePosition();


         // if (input.GetMouseButtonDown(0))
         // {
         //     particles.push_back(Particle
         //         { mousePosition,
         //         randomOnUnitCircle() * randomf(50,200),
         //         randomf(5),
         //         (uint8_t)random(1,255),
         //         (uint8_t)random(1,255),
         //         (uint8_t)random(1,255),
         //         (uint8_t)random(1,255)
         //         });
         //
         // }

        // UPDATE
        

       
          audio->update();
        

       // for (Particle& particle : particles)
       // {
       //     particle.update(time.GetDeltaTime());
       // 
       //     if (particle.position.x > 800) particle.position.x = 0;
       //     if (particle.position.x < 0) particle.position.x = 800;
       // }

        

        //DRAW
        //clear screen
        renderer.SetColor(0, 0, 0, 0);
        renderer.BegineFrame();

       //s renderer.SetColor(255, 255, 255, 255);
        //for (Particle particle : particles)
        //{
        //    particle.Draw(renderer);
        //
        //}

        //renderer.SetColor(255, 255, 255, 0);
        //float radious = 60;
        //offset += (1 * time.GetDeltaTime());
        //for (float angle = 0; angle < 360; angle += 360 / 30)
        //{
        //    float x = Math::Cos(Math::DegToRad(angle))* Math::Sin(offset+ .05)* radious;
        //    float y = Math::Sin(Math::DegToRad(angle)) * Math::Sin(offset+ .05)* radious;
        //        renderer.DrawRect(400 + x, 300+ y, 4.0f, 4.0f);
        //}


        //renderer.SetColor(255, 255, 255, 0);
        model.Draw(renderer, transform);
       

        renderer.EndFrame();

    }
    return 0;
}