//
// Created by clement on 2/14/24.
//

#include "Scene.h"

#include "raymath.h"
#define RLIGHTS_IMPLEMENTATION
#include "rlights.h"


 Scene::Scene()
{

}

void Scene::Init()
 {
     m_camera.position = {10, 10, 10};
     m_camera.target = {0, 0, 0};
     m_camera.up = {0, 1, 0};
     m_camera.fovy = 45.f;
     m_camera.projection = CAMERA_PERSPECTIVE;

     m_shader = LoadShader(R"(D:\code\C++\dungeon-crawler\assets\shaders\glsl330\lighting.vs)",
                          R"(D:\code\C++\dungeon-crawler\assets\shaders\glsl330\lighting.fs)");
     m_shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(m_shader, "viewPos");
     int ambientLoc = GetShaderLocation(m_shader, "ambient");
     float array[4] = {0.1f, 0.1f, 0.1f, 1.0f};
     SetShaderValue(m_shader, ambientLoc, array, SHADER_UNIFORM_VEC4);

     lights[0] = CreateLight(LIGHT_POINT, Vector3{0, 10, 0}, Vector3Zero(), ORANGE, m_shader);
     lights[0].enabled = true;
 }
