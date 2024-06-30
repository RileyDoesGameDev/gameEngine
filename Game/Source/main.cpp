#include <SDL.h>
#include <iostream>




int main(int argc, char* argv[])
{
	bool quit = false;
	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
		return 1;
	}
	// create window
	// returns pointer to window if successful or nullptr if failed
	SDL_Window* window = SDL_CreateWindow("Game Engine",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600,
		SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	// create renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	while (!quit)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		// clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		// draw grid
	/*	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		SDL_RenderDrawLine(renderer, 800 / 3, 0, 800 / 3, 600);
		SDL_RenderDrawLine(renderer, 800 / 3 * 2, 0, 800 / 3 * 2, 600);
		SDL_RenderDrawLine(renderer, 0, 600 / 3, 800, 600 / 3);
		SDL_RenderDrawLine(renderer, 0, 600 / 3 * 2, 800, 600 / 3 * 2);*/
		//L_RenderDrawLine(renderer, 0, 600 / 5 * 3, 800, 600 / 5 * 3);
		int wtd = 1;
		if (wtd == 0)
		{
			//draw shape
			SDL_SetRenderDrawColor(renderer, 255, 12, 255, 0);
			SDL_RenderDrawLine(renderer, 800 / 3, 600 / 3 * 2, 800 / 3 * 2, 600 / 3 * 2);
			SDL_RenderDrawLine(renderer, 800 / 2, 600 / 3, 800 / 2, 600 / 5 * 3);
			SDL_RenderDrawLine(renderer, 800 / 3 * 2, 600 / 3 * 2, 800 / 2, 600 / 3);
			SDL_RenderDrawLine(renderer, 800 / 3, 600 / 3 * 2, 800 / 2, 600 / 3);
			SDL_RenderDrawLine(renderer, 800 / 2, 600 / 5 * 3, 800 / 3, 600 / 3 * 2);
			SDL_RenderDrawLine(renderer, 800 / 2, 600 / 5 * 3, 800 / 3 * 2, 600 / 3 * 2);
			int num = 0;
			int num2 = 0;
			for (int i = 0; i < 8; i++)
			{
				num += 5;
				num2 += 16;
				SDL_RenderDrawLine(renderer, 800 / 3 + num2, 600 / 3 * 2 - num, 800 / 3 * 2 - num2, 600 / 3 * 2 - num);
			}
		}else if(wtd == 1)
		{
			//draw random lines
			for (int i = 0; i < 900; i++)
			{
				SDL_SetRenderDrawColor(renderer, rand() % 256, rand() % 256, rand() % 256, 0); // create random color
				int randValue = rand() % 801;
				int randValue2 = rand() % 601;
				SDL_RenderDrawLine(renderer, randValue,randValue2,800/2,0);
				SDL_RenderDrawLine(renderer, randValue,randValue2,randValue,600);
			}
		}
		SDL_RenderPresent(renderer);
	}

	return 0;
}


