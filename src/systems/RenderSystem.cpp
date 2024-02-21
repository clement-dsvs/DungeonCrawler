//
// Created by Clément Desavis on 22/01/2024.
//

#include "RenderSystem.h"

#include <entt/resource/resource.hpp>

#include "components/Position.h"
#include "components/StaticModel.h"
#include "core/Scene.h"

void ModelSystem::Draw(Scene& scene) {
    const auto& registry = scene.getRegistry();
    const Shader& shader = scene.getShader();

    float cameraPos[3] = { scene.getCamera().position.x, scene.getCamera().position.y, scene.getCamera().position.z };
    SetShaderValue(shader, shader.locs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);

    const auto view = registry.view<entt::resource<StaticModel>, Position>();

    for (const entt::entity entity : view) {
        const auto& position = registry.get<Position>(entity);
        const auto& model = registry.get<entt::resource<StaticModel>>(entity);

        DrawModel(model, position, 1.f, WHITE);
    }
}
