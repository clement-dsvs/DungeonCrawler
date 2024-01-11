include_directories(../include/rlImGui)

find_package(imgui)

add_library(rlImGui STATIC rlImGui.cpp)
target_link_libraries(rlImGui PRIVATE imgui::imgui raylib)