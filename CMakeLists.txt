cmake_minimum_required(VERSION 3.22)
project(tetriz)

set(CXX_STANDARD 20)

aux_source_directory(. src)
add_executable(tetriz ${src})
find_package(Threads REQUIRED)
target_link_libraries(tetriz Threads::Threads)


