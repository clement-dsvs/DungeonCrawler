//
// Created by Clément Desavis on 12/01/2024.
//

#ifndef GAME_H
#define GAME_H

#include <entt/entity/registry.hpp>


class Game {

public:
    Game();

    /**
     * @brief Initialize Game
     * @return void
     */
    void o_vInit();

    void o_vStart();

    void o_vClose();

private:
    /**
     * \brief Update systems
     * \param delta Time passed since last call
     */
    void o_vUpdate(float delta);

    /**
     * \brief Render systems
     */
    void o_vDraw();

private:
    entt::registry m_registry;

};



#endif //GAME_H