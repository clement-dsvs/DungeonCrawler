//
// Created by Clément Desavis on 12/01/2024.
//

#include "Game.h"

#include <imgui.h>
#include <raylib.h>
#include <rlImGui/rlImGui.h>

Game::Game() {
    m_registry = entt::registry();
}

void Game::o_vInit() {
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    SetExitKey(KEY_NULL);
    InitWindow(1280, 800, "Dungeon Crawler");
    SetTargetFPS(144);
    rlImGuiSetup(true);
}

void Game::o_vStart() {
    while (!WindowShouldClose())
    {
        o_vUpdate(GetFrameTime());
        o_vDraw();
    }
}

void Game::o_vUpdate(float delta) {
    // Update stuff
}

void Game::o_vDraw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    {
        // Draw stuff

        //TODO: à mettre dans le système ImGui
        rlImGuiBegin();

        rlImGuiEnd();

    }

    EndDrawing();
}

void Game::o_vClose() {
    rlImGuiShutdown();
    CloseWindow();
}
