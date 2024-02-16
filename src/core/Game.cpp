//
// Created by Clément Desavis on 12/01/2024.
//

#include "Game.h"

#include <entt/resource/cache.hpp>
#include <raylib.h>
#include <rlImGui/rlImGui.h>
#include <stack>

#include "Scene.h"
#include "systems/DungeonSystem.h"
#include "systems/RenderSystem.h"

Game::Game()
{
    m_registry = entt::registry();
    m_camera = Camera3D{};
    std::stack<Scene> scene_stack;
    for (auto& scene : scene_stack)
    {
        
    }
}

void Game::o_vInit()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    InitWindow(1280, 800, "Dungeon Crawler");
    SetExitKey(KEY_NULL);
    SetTargetFPS(144);
    rlImGuiSetup(true);
    DisableCursor();
    HideCursor();

    m_camera.position = {10, 10, 10};
    m_camera.target = {0, 0, 0};
    m_camera.up = {0, 1, 0};
    m_camera.fovy = 45.f;
    m_camera.projection = CAMERA_PERSPECTIVE;
}

void Game::o_vStart()
{
    while (!WindowShouldClose())
    {
        o_vUpdate(GetFrameTime());
        o_vDraw();
    }
}

void Game::o_vUpdate(float delta)
{
    // Update systems
    UpdateCamera(&m_camera, CAMERA_THIRD_PERSON);
}

void Game::o_vDraw()
{
    BeginDrawing();
    {
        ClearBackground(RAYWHITE);
        BeginMode3D(m_camera);
        {
            ModelSystem::Draw(m_registry);
        }
        EndMode3D();

        rlImGuiBegin();
        {
        }
        rlImGuiEnd();

        DrawFPS(10, 10);
    }
    EndDrawing();
}

void Game::o_vClose()
{
    rlImGuiShutdown();
    CloseWindow();
}
