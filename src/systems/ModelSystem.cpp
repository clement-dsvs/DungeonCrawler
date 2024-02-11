//
// Created by Clément Desavis on 22/01/2024.
//

#include "ModelSystem.h"

#include <entt/resource/resource.hpp>

#include "components/Position.h"
#include "components/StaticModel.h"

void ModelSystem::Draw(entt::registry &registry) {
    const auto view = registry.view<entt::resource<StaticModel>, Position>();

    for (const entt::entity entity : view) {
        const auto& position = registry.get<Position>(entity);
        const auto& model = registry.get<entt::resource<StaticModel>>(entity);

        DrawModel(model, position, 1.f, WHITE);
    }
}
