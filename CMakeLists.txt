cmake_minimum_required(VERSION 3.0)

project (raycast_lib)
message("Sources: " ${PROJECT_SOURCE_DIR})
if (APPLE)
    # Do something for Mac
endif ()

if (WIN32)
    # Do something for Windows
endif ()

set (RAYCAST_SOURCES
    "src/ray_caster.cpp"
)

set (RAYCAST_INCLUDES "${PROJECT_SOURCE_DIR}/src")

include_directories(${RAYCAST_INCLUDES} "${PROJECT_SOURCE_DIR}/src")
find_package(Eigen3 REQUIRED)

add_library(${PROJECT_NAME} STATIC ${RAYCAST_SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC Eigen3::Eigen)

