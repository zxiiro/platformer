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

#include "animation.h"

Animation::Animation()
{
    current_frame = 0;
    max_frames = 4;

    framerate = 100; // Milliseconds
    previous_time = 0;
};

void Animation::OnAnimate()
{
    if (previous_time + framerate > SDL_GetTicks()) return;

    previous_time = SDL_GetTicks();

    current_frame++;
    if (current_frame >= max_frames) current_frame = 0;
}

int Animation::GetCurrentFrame()
{
    return current_frame;
}
