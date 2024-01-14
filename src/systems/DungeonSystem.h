//
// Created by cleme on 13/01/2024.
//

#ifndef DUNGEONSYSTEM_H
#define DUNGEONSYSTEM_H
#include <entt/entity/registry.hpp>

#include "raylib.h"
#include "raymath.h"

class DungeonSystem {
public:
    static void o_vInit(int nb_rooms, entt::registry& registry);

private:
    struct Cube {
        Vector3 position;
        Vector3 size;
        bool operator==(const Cube& other) const {
            return Vector3Equals(position, other.position) && Vector3Equals(size, other.size);
        }
    };


    static Vector2 o_ComputeSeparationVector(const Cube& room, std::vector<Cube>& room_list);
};



#endif //DUNGEONSYSTEM_H
