include_directories(../include/rlImGui)

add_library(rlImGui STATIC rlImGui.cpp)
target_link_libraries(rlImGui PRIVATE imgui raylib)