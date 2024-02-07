//
// Created by Clément Desavis on 12/01/2024.
//

#include "Game.h"

#include <imgui.h>
#include <raylib.h>
#include <rlImGui/rlImGui.h>

#include "systems/DungeonSystem.h"
#include "systems/ModelSystem.h"

Game::Game() {
    m_registry = entt::registry();
}

void Game::o_vInit() {
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    SetExitKey(KEY_NULL);
    InitWindow(1280, 800, "Dungeon Crawler");
    SetTargetFPS(144);
    rlImGuiSetup(true);
    DisableCursor();

    m_camera = Camera3D{};
    m_camera.position = {10, 10, 10};
    m_camera.target = {0, 0, 0};
    m_camera.up = {0, 1, 0};
    m_camera.fovy = 45.f;
    m_camera.projection = CAMERA_PERSPECTIVE;

    DungeonSystem::o_vInit(10, m_registry);
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
    UpdateCamera(&m_camera, CAMERA_THIRD_PERSON);
}

void Game::o_vDraw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    {
        // Draw stuff

        BeginMode3D(m_camera);
        ModelSystem::Draw(m_registry);
        EndMode3D();

        //TODO: à mettre dans le système ImGui
        rlImGuiBegin();

        rlImGuiEnd();

        DrawFPS(10, 10);

    }

    EndDrawing();
}

void Game::o_vClose() {
    rlImGuiShutdown();
    CloseWindow();
}
