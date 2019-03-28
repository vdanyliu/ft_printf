cmake_minimum_required(VERSION 3.12.1)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES
#        libft/*.h
#        libft/*.c
        *.h
        *.c)

aux_source_directory(libft LBFT_SRC)
add_library(ft STATIC ${LBFT_SRC})


add_executable(ft_printf
        ${SOURCES})

target_link_libraries(ft_printf ft)

#set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
#set(GCC_COVERAGE_COMPILE_FLAGS "-Werror -Wextra -Wall")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
#target_link_libraries(ft_printf -lmlx "-framework OpenGL" "-framework AppKit")

