#include "Renderer.h"
#include "Vector2.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <SDL.h>

using namespace std;

int main(int argc, char* argv[])
{
    Renderer renderer;
    renderer.Initialize();
    renderer.CreateWindow("Engine", 800, 600);

   // Vector2 v1{ 400, 300 };
   // Vector2 v2{ 700, 500 };

    //std::vector<Vector2> points;
    //for (int i = 0; i < 100; i++) {
     //   points.push_back(Vector2{ rand() % 800, rand() % 600 });
    //}
    bool quit = false;
    SDL_Event event;
    while (quit == false)
    {
       
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
        //input
        //update
        //draw
        renderer.SetColor(0, 0, 0, 255);
        renderer.BegineFrame();
        
        renderer.SetColor(255,255, 255, 255);
        renderer.DrawLine(100,100,600,600);
        

        //UPDATE
        //Vector2 speed{ 0.1f, -0.1f };
        //for (Vector2& point : points) {
       //     point = point + 0.002f;
       // }
        renderer.EndFrame();
       
    }
    return 0;
}