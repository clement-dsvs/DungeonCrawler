#include <cstdlib>
#include <exception>

#include "core/Game.h"
#include "core/Logger.h"

int main()
{
    try {
        Game game;
        game.o_vInit();
        game.o_vStart();
        return EXIT_SUCCESS;
    }
    catch (const std::exception& exception) {
        Logger::Error(exception.what());
        return EXIT_FAILURE;
    }
}
