#include "inc/def.h"
#include "inc/game.h"

i32
main(void)
{
    game_init();

    {
        vertex_spec();
        graphics_init_pipeline();
    }

    game_loop();
    game_deinit();

    return (0);
}
