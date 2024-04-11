cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(HeatGeodesics)
# include_directories(PUBLIC "${PROJECT_BINARY_DIR}")
# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_program(CCACHE_FOUND ccache)
option(DISABLE_CCACHE "Disable ccache even if found" OFF)
if (CCACHE_FOUND AND NOT DISABLE_CCACHE)
    message(STATUS "Using ccache")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
endif ()

set(PM_CMAKE_DIR ${PROJECT_SOURCE_DIR}/cmake)
include(cmake/CPM.cmake)
include(cmake/dependencies.cmake)

find_package(Eigen3 REQUIRED)
add_library(thirdparty INTERFACE)
target_link_libraries(thirdparty INTERFACE
    Eigen3::Eigen fmt::fmt
    spdlog::spdlog spdlog::spdlog_header_only
    absl::inlined_vector
    absl::flat_hash_map
    absl::flat_hash_set
    CDT
    igl::core
)

add_subdirectory(libs)
add_subdirectory(apps)