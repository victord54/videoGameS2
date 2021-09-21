
cmake_minimum_required( VERSION 3.7.0 )
project(spaceCorridor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
file(GLOB SOURCES
    "${SRC_DIR}/*.h"
    "${SRC_DIR}/*.c"
)
add_definitions(-DRESOURCES_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}/resources/\")

find_package( SDL2 )
if( ${SDL2_FOUND} )
    message(STATUS "Found SDL2")
    include_directories(${SDL2_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} ${SOURCES})
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
else()
    message(STATUS "Could not locate SDL2, using the submodule")
    add_subdirectory(external)
    add_executable(${PROJECT_NAME} ${SOURCES})
    target_include_directories(${PROJECT_NAME} PRIVATE "external/SDL2/include")
    target_link_libraries(
            ${PROJECT_NAME} PRIVATE
            SDL2main
            SDL2-static
            SDL2_ttf
            SDL2_image
            )
endif()
