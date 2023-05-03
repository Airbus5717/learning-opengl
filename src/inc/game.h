#pragma once

#include "def.h"

#include <SDL2/SDL.h>
// opengl
void get_opengl_versions();

// game
void game_init();
void game_loop();
void game_deinit();

// game loop specific
void input();
void pre_draw();
void draw();
