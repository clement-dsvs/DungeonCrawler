cmake_minimum_required(VERSION 3.11)
project(DungeonCrawler)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

# Dependencies
add_subdirectory(external/raylib)
include(cmake/FindImgui.cmake)
add_subdirectory(external/entt)
#add_subdirectory(external/bullet3)

add_subdirectory(libs/rlImGui)

# DungeonCrawler
add_executable(${PROJECT_NAME} src/main.cpp
        src/core/Game.cpp
        src/core/Game.h
        src/systems/DungeonSystem.cpp
        src/systems/DungeonSystem.h
        src/components/StaticModel.h
        src/components/Position.h
        src/components/Size.h
        src/systems/RenderSystem.cpp
        src/systems/RenderSystem.h
        src/core/resources/StaticModelCache.h
        src/core/resources/StaticModelLoader.cpp
        src/core/resources/StaticModelLoader.h
        src/core/globals.h
        src/core/Scene.cpp
        src/core/Scene.h
)

#set(raylib_VERBOSE 1)
target_include_directories(${PROJECT_NAME} PRIVATE src libs/include third-party/imgui)
target_link_libraries(${PROJECT_NAME} raylib EnTT::EnTT imgui rlImGui) #SQLite::SQLite3


# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()