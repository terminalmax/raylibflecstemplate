cmake_minimum_required(VERSION 4.0)
project(MyGame C)

# Use C23
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

include(FetchContent)

# ---- Fetch Raylib ----
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5  # Use latest stable
)
FetchContent_MakeAvailable(raylib)

# ---- Fetch Flecs ----
FetchContent_Declare(
    flecs
    GIT_REPOSITORY https://github.com/SanderMertens/flecs.git
    GIT_TAG v4.1.2
)
FetchContent_MakeAvailable(flecs)

# ---- Your executable ----
add_executable(${PROJECT_NAME}
    src/main.c
)

# ---- Link libraries ----
target_link_libraries(${PROJECT_NAME}
    PRIVATE raylib flecs
)

# ---- Platform specific settings ----
if (APPLE)
    # macOS frameworks
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework IOKit" "-framework Cocoa" "-framework OpenGL")
elseif (UNIX AND NOT APPLE)
    # Linux deps
    target_link_libraries(${PROJECT_NAME} PRIVATE m pthread dl rt X11)
endif()

