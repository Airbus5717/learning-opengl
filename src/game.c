/*
 * Learning OpenGL 
 * */
#include "inc/game.h"
#include "inc/def.h"

#include "libs/KHR/khrplatform.h"
#include "libs/glad/glad.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

// Globals
const i32 WIDTH = 640;
const i32 HEIGHT = 480;
const cstr TITLE = "Learning OpenGL";

// global state
SDL_Window *g_window = nullptr;
SDL_Renderer *g_renderer = nullptr;
SDL_GLContext *g_glcontext = nullptr;
bool g_game_running = true;

void get_opengl_versions() {
    printf("Vendor: %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version: %s\n", glGetString(GL_VERSION));
    printf("Shading Lang: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
}

void game_init() {
    ASSERT(SDL_Init(SDL_INIT_VIDEO) >= 0, "SDL2 could not init video");
    
    // Setup versions
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    
    // Create a window
    g_window = SDL_CreateWindow(TITLE, 1, 0, WIDTH, HEIGHT,
                                SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    
    ASSERT_NULL(g_window, "window didnt create");
    
    // Create Context
    g_glcontext = SDL_GL_CreateContext(g_window);
    ASSERT_NULL(g_glcontext, "GL context didnt create");
    
    ASSERT(gladLoadGLLoader(SDL_GL_GetProcAddress), "Glad was not initialized");
    get_opengl_versions();
}

void game_loop() {
    while (g_game_running) {
        input();
        pre_draw();
        draw();
        SDL_GL_SwapWindow(g_window);
    }
}

void game_deinit() {
    SDL_DestroyWindow(g_window);
    SDL_Quit();
}

// Game loop specific
void input() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            g_game_running = false;
        }
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
            g_game_running = false;
        }
    }
}

// TODO: 
void pre_draw() {}
// TODO: 
void draw() {}
