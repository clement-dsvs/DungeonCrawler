//
// Created by cleme on 13/01/2024.
//

#include "DungeonSystem.h"

#include <entt/entity/registry.hpp>
#include <entt/resource/cache.hpp>
#include <iostream>
#include <random>

#include "components/Position.h"
#include "components/StaticModel.h"
#include "core/Scene.h"
#include "core/globals.h"
#include "raymath.h"

/*
 void DungeonSystem::o_vInit(int nb_rooms, entt::registry& registry) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist_pos(0, 15); // Ecartement relatif au 0, 0
    std::uniform_int_distribution<std::mt19937::result_type> dist_size(1, 6); // Taille Mini/Maxi

    std::vector<Cube> rooms;

    for (int i = 0; i <= nb_rooms * 3; i++) {
        Vector3 l_size {};
        l_size.x = int(dist_size(rng));
        l_size.y = 0;
        l_size.z = int(dist_size(rng));

        Vector3 l_position {};
        l_position.x = int(dist_pos(rng)) - 15;
        l_position.y = 0;
        l_position.z = int(dist_pos(rng)) - 15;
        rooms.push_back({l_position, l_size});
    }

    bool had_value = true;
    while (had_value) {
        had_value = false;
        for (Cube& room: rooms) {
            const Vector2 separation = o_ComputeSeparationVector(room, rooms);

            if (separation.x != 0 || separation.y != 0) had_value = true;

            room.position.x += separation.x;
            room.position.z += separation.y;
        }
    }

    double average_size = 0;

    for (const Cube& room : rooms) {
        average_size += room.size.x * room.size.z;
    }

    average_size /= rooms.size();

    std::erase_if(rooms, [&](Cube room) {
        return (room.size.x * room.size.z < average_size * 1.3);
    });

    for (const Cube& room : rooms) {
        for (int x = 0; x < room.size.x; x ++) {
            for (int z = 0; z < room.size.z; z++) {
                auto l_model =
LoadModel("/Users/clement/code/cpp/DungeonCrawler/assets/models/world/floor_wood_large.gltf.glb"); Position
l_position{}; l_position.x = room.position.x * 3 + (x * 4); l_position.y = room.position.y; l_position.z =
room.position.z * 3 + (z * 4);

                std::cout << l_position.x << " | " << l_position.y << " | " << l_position.z << "\n";

                entt::entity l_entity = registry.create();
                registry.emplace<StaticModel>(l_entity, l_model);
                registry.emplace<Position>(l_entity, l_position);
            }
        }
    }
}
 */

void DungeonSystem::o_vInit(int nb_rooms, Scene& scene)
{
    auto& l_registry = scene.getRegistry();
    auto& l_cache = scene.getStaticModelCache();

    for (int x = -3; x <= 3; x++)
    {
        for (int z = -3; z <= 3; z++)
        {
            entt::entity l_entity = l_registry.create();
            auto ret = l_cache.load(HASH_AND_STRING(R"(D:\code\C++\dungeon-crawler\assets\models\world\floor_tile_large.gltf.glb)"));
            entt::resource<StaticModel> l_model = ret.first->second;
            for (int i = 0; i < l_model->materialCount; i++)
            {
                l_model->materials[i].shader = scene.getShader();
            }
            Position l_position{};
            l_position.x = x * 4;
            l_position.y = 0;
            l_position.z = z * 4;
            l_registry.emplace<entt::resource<StaticModel>>(l_entity, l_model);
            l_registry.emplace<Position>(l_entity, l_position);
        }
    }
}

Vector2 DungeonSystem::o_ComputeSeparationVector(const Cube &room, std::vector<Cube> &room_list)
{
    Vector2 totalForce{0, 0};
    unsigned int neigbourCount = 0;

    for (Cube neighbour: room_list)
    {
        if (room == neighbour)
            continue;

        Rectangle rec_room{room.position.x, room.position.z, room.size.x, room.size.z};
        Rectangle rec_neighbour{neighbour.position.x, neighbour.position.z, neighbour.size.x, neighbour.size.z};

        if (!CheckCollisionRecs(rec_room, rec_neighbour))
            continue;

        totalForce.x += rec_neighbour.x - rec_room.x;
        totalForce.y += rec_neighbour.y - rec_room.y;

        neigbourCount++;
    }

    if (neigbourCount == 0)
        return totalForce;

    totalForce.x /= static_cast<float>(neigbourCount);
    totalForce.y /= static_cast<float>(neigbourCount);

    totalForce.x *= -1;
    totalForce.y *= -1;

    return Vector2Normalize(totalForce);
}
