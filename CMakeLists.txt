cmake_minimum_required(VERSION 3.14)
project(square_io)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(square_io main.cpp bot.h bot.cpp control.h dynamic_entity.h dynamic_entity.cpp entity.h entity.cpp list_of_type.h player.h player.cpp static_entity.h static_entity.cpp visual_bot.h visual_player.h visual_static.h visual_world.h world.h world.cpp)

target_link_libraries(square_io sfml-graphics sfml-audio)