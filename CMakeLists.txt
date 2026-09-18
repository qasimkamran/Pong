cmake_minimum_required(VERSION 3.15)

project(Pong VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(RAYLIB_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/vendor/raylib-6.0")
set(RAYLIB_LIBRARY "${RAYLIB_ROOT}/lib/raylib.lib")

if(NOT WIN32)
    message(FATAL_ERROR "The bundled raylib library is built for Windows.")
endif()

if(NOT EXISTS "${RAYLIB_LIBRARY}")
    message(FATAL_ERROR "Bundled raylib library not found: ${RAYLIB_LIBRARY}")
endif()

add_library(raylib STATIC IMPORTED)
set_target_properties(raylib PROPERTIES
    IMPORTED_LOCATION "${RAYLIB_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES "${RAYLIB_ROOT}/include"
)

file(GLOB_RECURSE PONG_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(Pong
    main.cpp
    ${PONG_SOURCES}
)

target_compile_features(Pong PRIVATE cxx_std_17)

target_include_directories(Pong PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(Pong PRIVATE
    raylib
    user32
    gdi32
    shell32
    opengl32
    winmm
)

