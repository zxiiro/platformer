/**********************************************************************

    Copyright (c) 2013 Thanh Ha

    This file is part of platformer-sdl2.

    platformer-sdl2 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    platformer-sdl2 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with platformer-sdl2.  If not, see <http://www.gnu.org/licenses/>.

**********************************************************************/

#include "engine.h"

Engine::Engine()
{
    running = true;
    //animation.max_frames = 4;
};

/**************************************
    Initialization and Cleanup
 **************************************/

bool Engine::Initialize()
{
    // Initialize SDL or fail if initialization issue
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION,
        "Initializing SDL...");
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
            "Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }


    /****************************************
        Initialize Displayer and Renderer
     ****************************************/

    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION,
        "Initializing window...");
    window = SDL_CreateWindow("SDL2 Tic Tac Toe",
                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // x, y
                WWIDTH, WHEIGHT,    // Window width and height
                SDL_WINDOW_RESIZABLE);

    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION,
        "Initializing renderer...");
    renderer = SDL_CreateRenderer(window, -1,
                    SDL_RENDERER_TARGETTEXTURE |
                    SDL_RENDERER_PRESENTVSYNC |
                    SDL_RENDERER_ACCELERATED);

    /****************
        Finish up
     ****************/

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
        "Game initialized.");
    return true;
}

void Engine::Cleanup()
{

    // Cleanup items created by Initialize()
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int Engine::Execute()
{
    if (Initialize() == false) {
        return -1;
    }

    SDL_Event event;

    // Game loop
    while (running) {
        // Poll for SDL Events
        while (SDL_PollEvent(&event)) {
            OnEvent(&event);
        }

        OnLoop();
        OnRender();
    }

    // Cleanup and return
    Cleanup();
    return 0;
}

/*****************************
    Events
 *****************************/

void Engine::OnEvent(SDL_Event* event)
{
    // User clicked the close button
    if(event->type == SDL_QUIT) {
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
            "Exiting Platformer SDL2");
        running = false;
    }
}

void Engine::OnLoop()
{
    animation.OnAnimate();
}

void Engine::OnRender()
{
    SDL_RenderClear(renderer);

    SDL_Texture* tex = Painter::LoadImage(renderer, "gfx/ball.png");

    SDL_Rect pos;
    pos.x=0;
    pos.y=0;
    pos.w=32 * 4;
    pos.h=32 * 4;

    SDL_Rect clip[4];
    for (int i=0; i<4; i++) {
        clip[i].x = i*32;
        clip[i].y = 0;
        clip[i].w = 32;
        clip[i].h = 32;
    }
    Painter::DrawImage(renderer, tex, &pos, &clip[animation.GetCurrentFrame()]);

    SDL_DestroyTexture(tex);

    SDL_RenderPresent(renderer);
}
