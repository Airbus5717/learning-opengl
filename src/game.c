/*
 * Learning OpenGL
 * */
#include "inc/game.h"
#include "inc/def.h"
#include "inc/vec.h"

#include "libs/KHR/khrplatform.h"
#include "libs/glad/glad.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

// Globals
const i32 WIDTH  = 640;
const i32 HEIGHT = 480;
const cstr TITLE = "Learning OpenGL";

// global state
SDL_Window *g_window       = NULL;
SDL_Renderer *g_renderer   = NULL;
SDL_GLContext *g_glcontext = NULL;
bool g_game_running        = true;

GLuint g_vertex_arr_obj                = 0;
GLuint g_vertex_buff_obj               = 0;
GLuint g_graphics_pipeline_shader_prog = 0;

void
get_opengl_versions()
{
    printf("Vendor: %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version: %s\n", glGetString(GL_VERSION));
    printf("Shading Lang: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
}

void
vertex_spec()
{

    GLfloat vertex_pos[] = {
        // x, y, z
        -0.8f, -0.8f, 0.0f, // vertex 1
        0.8f,  -0.8f, 0.0f, // vertex 2
        0.0f,  0.8f,  0.0f, // vertex 3
    };

    int SIZE = sizeof(vertex_pos) / sizeof(vertex_pos[0]);

    glGenVertexArrays(1, &g_vertex_arr_obj);
    glBindVertexArray(g_vertex_arr_obj);

    // generate Vertex Buffer object (VBO)
    glGenBuffers(1, &g_vertex_buff_obj);
    glBindBuffer(GL_ARRAY_BUFFER, g_vertex_buff_obj);

    glBufferData(GL_ARRAY_BUFFER, SIZE * sizeof(GLfloat), vertex_pos, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindVertexArray(0);
    glDisableVertexAttribArray(0);
}

internal GLuint
compile_shader(GLuint type, cstr src)
{
    GLuint shader_obj = 0;
    switch (type)
    {
        case GL_VERTEX_SHADER: shader_obj = glCreateShader(GL_VERTEX_SHADER); break;
        case GL_FRAGMENT_SHADER: shader_obj = glCreateShader(GL_FRAGMENT_SHADER); break;
        default: break;
    }
    glShaderSource(shader_obj, 1, &src, NULL);
    glCompileShader(shader_obj);
    return shader_obj;
}

// vs: vertex shader source
// fs: fragment shader source
internal GLuint
graphics_init_shader_prog(const cstr vs, const cstr fs)
{
    GLuint prog_obj = glCreateProgram();

    GLuint vertex_shader   = compile_shader(GL_VERTEX_SHADER, vs);
    GLuint fragment_shader = compile_shader(GL_FRAGMENT_SHADER, fs);

    glAttachShader(prog_obj, vertex_shader);
    glAttachShader(prog_obj, fragment_shader);
    glLinkProgram(prog_obj);

    glValidateProgram(prog_obj);
    // glDetachShader, glDeleteShader
    return prog_obj;
}

void
graphics_init_pipeline()
{
    const cstr vs = "#version 410 core\n"
                    "in vec4 position;\n"
                    "void main()\n"
                    "{\n"
                    "   gl_Position = vec4(position.x, position.y, position.z, position.w);\n"
                    "}\n";
    const cstr fs = "#version 410 core\n"
                    "out vec4 color;\n"
                    "void main()\n"
                    "{\n"
                    "   color = vec4(1.0f, 0.5f, 0.0f, 1.0f);\n"
                    "}\n";

    g_graphics_pipeline_shader_prog = graphics_init_shader_prog(vs, fs);
}

void
game_init()
{
    ASSERT(SDL_Init(SDL_INIT_VIDEO) >= 0, "SDL2 could not init video");

    // Setup versions
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    // Create a window
    g_window =
        SDL_CreateWindow(TITLE, 1, 0, WIDTH, HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    ASSERT_NULL(g_window, "window didnt create");

    // Create Context
    g_glcontext = SDL_GL_CreateContext(g_window);
    ASSERT_NULL(g_glcontext, "GL context didnt create");

    ASSERT(gladLoadGLLoader(SDL_GL_GetProcAddress), "Glad was not initialized");

    get_opengl_versions();
}

void
game_loop()
{
    while (g_game_running)
    {
        input();
        pre_draw();
        draw();
        SDL_GL_SwapWindow(g_window);
    }
}

void
game_deinit()
{
    SDL_DestroyWindow(g_window);
    SDL_Quit();
}

// Game loop specific
void
input()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
        {
            g_game_running = false;
        }
    }
}

void
pre_draw()
{
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(1.0f, 1.f, 0.0f, 1.f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glUseProgram(g_graphics_pipeline_shader_prog);
}

void
draw()
{
    glBindVertexArray(g_vertex_arr_obj);
    glBindBuffer(GL_ARRAY_BUFFER, g_vertex_buff_obj);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}
