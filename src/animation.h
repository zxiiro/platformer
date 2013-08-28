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

#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#ifdef ANDROID
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "painter.h"

class Animation {
private:
    int current_frame;
    int max_frames;

    int framerate;
    int previous_time;

public:
    Animation();

    // Events
    void OnAnimate();

    int GetCurrentFrame();
};


#endif
