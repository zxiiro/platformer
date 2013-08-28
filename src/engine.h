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

#ifndef _ENGINE_H_
#define _ENGINE_H_

#ifdef ANDROID
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "animation.h"
#include "global.h"
#include "painter.h"

class Engine
{
private:
    bool            running;

    SDL_Renderer*   renderer;
    SDL_Window*     window;

    Animation       animation;

    bool Initialize();
    void Cleanup();

    // Events
    void OnEvent(SDL_Event* event);
    void OnLoop();
    void OnRender();

public:
    Engine();

    int Execute();
};

#endif
