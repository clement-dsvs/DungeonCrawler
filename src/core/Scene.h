//
// Created by clement on 2/14/24.
//

#ifndef SCENE_H
#define SCENE_H
#include <entt/entity/registry.hpp>

#include "resources/StaticModelCache.h"

#include "rlights.h"


class Scene {
public:
    Scene();

    void Init();

    entt::registry& getRegistry() { return m_registry; }
    StaticModelCache& getStaticModelCache() { return m_staticModelCache; }
    Shader& getShader() { return m_shader; }
    Camera3D& getCamera() { return m_camera; }

private:
    entt::registry m_registry;
    StaticModelCache m_staticModelCache;

    Camera3D m_camera;

    Shader m_shader;
    Light lights[4];
};



#endif //SCENE_H
