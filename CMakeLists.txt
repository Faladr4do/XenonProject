cmake_minimum_required(VERSION 3.24)

project(XenonProject LANGUAGES C CXX)

# ---------------------------------------------------------------------------
# Global settings
# ---------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Keep our target at the top of the Xcode / Visual Studio project tree
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# ---------------------------------------------------------------------------
# Dependencies (downloaded at configure time)
# ---------------------------------------------------------------------------
include(FetchContent)

# SDL3 -- windowing, input and OpenGL context creation
set(SDL_SHARED OFF CACHE BOOL "" FORCE)   # static: no .dll / .dylib to ship
set(SDL_STATIC ON  CACHE BOOL "" FORCE)
set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG        release-3.4.16
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(SDL3)

# GLAD -- OpenGL 3.3 core function loader (pre-generated, lives in external/)
add_subdirectory(external/glad)

# OpenGL -- provided by the operating system / graphics driver
find_package(OpenGL REQUIRED)

# ---------------------------------------------------------------------------
# Our application
# ---------------------------------------------------------------------------
add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        SDL3::SDL3
        glad
        OpenGL::GL
)

# Warnings
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
endif()

# Run from the source tree so relative paths (shaders/, assets/) just work
set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY   "${CMAKE_SOURCE_DIR}"
    XCODE_SCHEME_WORKING_DIRECTORY  "${CMAKE_SOURCE_DIR}"
)

# Make our executable the default target in Visual Studio (F5)
set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

# Tidy the IDE tree: hide third-party targets in a folder
set_target_properties(glad PROPERTIES FOLDER "external")
if(TARGET SDL3-static)
    set_target_properties(SDL3-static PROPERTIES FOLDER "external")
endif()
if(TARGET SDL_uclibc)
    set_target_properties(SDL_uclibc PROPERTIES FOLDER "external")
endif()
