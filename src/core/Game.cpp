//
// Created by Clément Desavis on 12/01/2024.
//

#include "Game.h"

#include <raylib.h>
#include <rlImGui/rlImGui.h>

#include "systems/DungeonSystem.h"
#include "systems/RenderSystem.h"

Game::Game()
{
}

void Game::o_vInit()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    InitWindow(1280, 800, "Dungeon Crawler");
    SetExitKey(KEY_NULL);
    SetTargetFPS(144);
    rlImGuiSetup(true);

    m_scene.Init();
    DungeonSystem::o_vInit(10, m_scene);

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
    UpdateCamera(&m_scene.getCamera(), CAMERA_THIRD_PERSON);
}

void Game::o_vDraw()
{
    DisableCursor();
    BeginDrawing();
    {
        ClearBackground(BLACK);
        BeginMode3D(m_scene.getCamera());
        {
            ModelSystem::Draw(m_scene);
            DrawGrid(12, 1);
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
