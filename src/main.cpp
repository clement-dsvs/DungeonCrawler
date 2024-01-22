#include <cstdlib>
#include <exception>

#include "core/Game.h"

int main()
{
    try {
        Game game;
        game.o_vInit();
        game.o_vStart();
        return EXIT_SUCCESS;
    }
    catch (const std::exception& exception) {
        return EXIT_FAILURE;
    }
}
