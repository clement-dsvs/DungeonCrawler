cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(DungeonCrawler)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

# Dependencies
add_subdirectory(third-party/raylib)
# add_subdirectory(third-party/imgui)
add_subdirectory(third-party/entt)

# add_subdirectory(libs/rlImGui)

# find_package(EnTT CONFIG REQUIRED)
# find_package(imgui CONFIG REQUIRED)
# find_package(SQLite3 REQUIRED)

# Our Project
add_executable(${PROJECT_NAME} src/main.cpp
        src/core/Logger.cpp
        src/core/Logger.h
        src/core/Game.cpp
        src/core/Game.h
        src/systems/DungeonSystem.cpp
        src/systems/DungeonSystem.h
        src/components/Model.h
        src/components/Position.h
        src/components/Size.h)
#set(raylib_VERBOSE 1)
target_include_directories(${PROJECT_NAME} PRIVATE src) # libs/include
target_link_libraries(${PROJECT_NAME} raylib EnTT::EnTT) # imgui::imgui rlImGui SQLite::SQLite3

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()