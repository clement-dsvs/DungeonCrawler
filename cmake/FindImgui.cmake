set(IMGUI_SRC_DIR ${CMAKE_SOURCE_DIR}/external/imgui)

include_directories(${IMGUI_SRC_DIR})


add_library(imgui STATIC ${IMGUI_SRC_DIR}/imgui.cpp ${IMGUI_SRC_DIR}/imgui_draw.cpp ${IMGUI_SRC_DIR}/imgui_tables.cpp ${IMGUI_SRC_DIR}/imgui_widgets.cpp)
