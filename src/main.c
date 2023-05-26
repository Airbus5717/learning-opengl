#include "inc/def.h"
#include "inc/game.h"

i32
main(void)
{
    game_init();
    game_loop();
    game_deinit();

    return (0);
}
