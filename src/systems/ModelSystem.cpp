//
// Created by Clément Desavis on 22/01/2024.
//

#include "ModelSystem.h"

#include "components/C_Position.h"
#include "components/C_Model.h"

void ModelSystem::Draw(entt::registry &registry) {
    const auto view = registry.view<C_Model, C_Position>();

    for (auto entity : view) {
        auto& position = registry.get<C_Position>(entity);
        auto& model = registry.get<C_Model>(entity);

        DrawModel(model, position, 1.f, WHITE);
    }
}
