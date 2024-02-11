//
// Created by Clément Desavis on 12/01/2024.
//

#include "Game.h"

#include <imgui.h>
#include <raylib.h>
#include <rlImGui/rlImGui.h>

#include <entt/resource/cache.hpp>

#include "components/Position.h"
#include "systems/DungeonSystem.h"
#include "systems/ModelSystem.h"

#include "resources/StaticModelCache.h"

Game::Game() {
    m_registry = entt::registry();
    m_camera = Camera3D{};
}

void Game::o_vInit() {
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    SetExitKey(KEY_NULL);
    InitWindow(1280, 800, "Dungeon Crawler");
    SetTargetFPS(144);
    rlImGuiSetup(true);
    DisableCursor();

    m_camera.position = {10, 10, 10};
    m_camera.target = {0, 0, 0};
    m_camera.up = {0, 1, 0};
    m_camera.fovy = 45.f;
    m_camera.projection = CAMERA_PERSPECTIVE;


    StaticModelCache cache{};
    using namespace entt::literals;

    auto ret = cache.load(R"(D:\code\C++\dungeon-crawler\assets\models\world\banner_blue.gltf.glb)"_hs, R"(D:\code\C++\dungeon-crawler\assets\models\world\banner_blue.gltf.glb)");
    entt::resource<StaticModel> res = ret.first->second;

    const entt::entity entity = m_registry.create();
    m_registry.emplace<entt::resource<StaticModel>>(entity, res);
    m_registry.emplace<Position>(entity, Position{0, 0, 0});

    //auto ret2 = cache.load(R"(D:\code\C++\dungeon-crawler\assets\models\world\banner_blue.gltf.glb)");

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
