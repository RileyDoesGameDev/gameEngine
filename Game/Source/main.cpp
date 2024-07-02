#include "Renderer.h"
#include "Vector2.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <SDL.h>
#include"input.h"
using namespace std;

int main(int argc, char* argv[])
{

    // create systems
    Renderer renderer;
    renderer.Initialize();
    renderer.CreateWindow("Engine", 800, 600);

    Input input;
    input.Initialize();
   // Vector2 v1{ 400, 300 };
   // Vector2 v2{ 700, 500 };

    std::vector<Vector2> points;
    //for (int i = 0; i < 100; i++) {
     //   points.push_back(Vector2{ rand() % 800, rand() % 600 });
    //}
    bool quit = false;
   
    while (!quit)
    {
       
        


     \
            if (input.GetKeyDown(SDL_SCANCODE_ESCAPE))
            {
                quit = true;
            }
       
        //input
        input.update();
        Vector2 mousePosition = input.GetMousePosition();
      //  std::cout << mousePosition.x << " " << mousePosition.y << std::endl;

        if (input.GetMouseButtonDown(0) && !input.GetPreviousMouseButtonDown(0))
        {
            std::cout << "mouse pressed\n";
            points.push_back(mousePosition);
        }

        if (input.GetMouseButtonDown(0) && input.GetPreviousMouseButtonDown(0))
        {
            float distance = (points.back() - mousePosition).Length();
            if (distance > 5) points.push_back(mousePosition);
        }
        //update
        //draw
       // renderer.SetColor(0, 0, 0, 255);
       // renderer.BegineFrame();
        

        for (int i = 0; points.size() > 1 && i < points.size() - 1; i++)
        {
            renderer.SetColor(255,255, 255, 255);
            renderer.DrawLine(points[i].x, points[i].y, points[i+1].x, points[i+1].y);

        }

       // renderer.SetColor(255,255, 255, 255);
       // renderer.DrawLine(100,100,600,600);
        

        //UPDATE
        //Vector2 speed{ 0.1f, -0.1f };
        //for (Vector2& point : points) {
       //     point = point + 0.002f;
       // }
        renderer.EndFrame();
       
    }
    return 0;
}