cmake_minimum_required(VERSION 3.17)
project(ping_pong_server)

set(CMAKE_CXX_STANDARD 14)

add_executable(ping_pong_server server_main.cpp PlayerBoard.cpp PlayerBoard.h Ball.cpp Ball.h Score.cpp Score.h)


set(SFML_DIR "~/Downloads/SFML-2.5.1/lib/cmake/SFML/")
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

target_link_libraries(ping_pong_server sfml-graphics sfml-network)