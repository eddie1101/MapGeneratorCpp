cmake_minimum_required(VERSION 3.25)

project(MapGenerator)

file(MAKE_DIRECTORY build)

add_executable(map_generator src/main.cpp)
set_target_properties(map_generator PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY build
)

target_include_directories(map_generator PRIVATE sfml/include)

target_link_directories(map_generator PRIVATE sfml/lib)
target_link_libraries(map_generator -lsfml-window -lsfml-graphics -lsfml-system)