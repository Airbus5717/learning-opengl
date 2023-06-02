#pragma once

#include "def.h"

#include <SDL2/SDL.h>
// opengl
void get_opengl_versions();


void vertex_spec();
void graphics_init_pipeline();

// game
void game_init();
void game_loop();
void game_deinit();

// game loop specific
void input();
void pre_draw();
void draw();
