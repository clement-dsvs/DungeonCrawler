//
// Created by cleme on 13/01/2024.
//

#include "DungeonSystem.h"

#include <random>
#include <entt/entity/registry.hpp>

#include "raymath.h"
#include "components/Position.h"
#include "components/Size.h"

void DungeonSystem::o_vInit(int nb_rooms, entt::registry& registry) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist_size(1, 6); // Taille Mini/Maxi
    std::uniform_int_distribution<std::mt19937::result_type> dist_pos(-15, 15); // Ecartement relatif au 0, 0

    std::vector<Cube> rooms;

    for (int i = 0; i < nb_rooms; i++) {
        const Vector3 l_size {static_cast<float>(dist_size(rng)), 1, static_cast<float>(dist_size(rng))};
        Vector3 l_position {static_cast<float>(dist_pos(rng)), 0, static_cast<float>(dist_pos(rng))};
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

}

Vector2 DungeonSystem::o_ComputeSeparationVector(const Cube& room, std::vector<Cube>& room_list) {
    Vector2 totalForce{0, 0};
    unsigned int neigbourCount = 0;

    for (Cube neighbour: room_list) {
        if (room == neighbour) continue;

        Rectangle rec_room{room.position.x, room.position.z, room.size.x, room.size.z};
        Rectangle rec_neighbour{neighbour.position.x, neighbour.position.z, neighbour.size.x, neighbour.size.z};

        if (!CheckCollisionRecs(rec_room, rec_neighbour)) continue;

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
