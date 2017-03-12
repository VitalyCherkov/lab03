project(lab03)
cmake_minimum_required(VERSION 3.5.2)
add_definitions(-Wall -Werror -Wextra -Ofast)

set(MAIN_EXE main.c)
set(DO_PROG_STATIC_LIB doProg.c)
set(LIST_SHARED_LIB list.c)

add_library(doProg STATIC ${DO_PROG_STATIC_LIB})
add_library(list SHARED ${LIST_SHARED_LIB})
add_executable(main ${MAIN_EXE})

target_link_libraries(doProg list)
target_link_libraries(main doProg)

