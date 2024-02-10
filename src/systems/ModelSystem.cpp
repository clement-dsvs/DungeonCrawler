//
// Created by Clément Desavis on 22/01/2024.
//

#include "ModelSystem.h"

#include "components/C_Position.h"
#include "components/StaticModel.h"

void ModelSystem::Draw(entt::registry &registry) {
    const auto view = registry.view<StaticModel, C_Position>();

    for (auto entity : view) {
        auto& position = registry.get<C_Position>(entity);
        auto& model = registry.get<StaticModel>(entity);

        DrawModel(model, position, 1.f, WHITE);
    }
}
