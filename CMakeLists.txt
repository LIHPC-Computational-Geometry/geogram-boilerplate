cmake_minimum_required(VERSION 3.5)

project(boilerplate-geogram)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# autofill VORPALINE_PLATFORM
include(${CMAKE_SOURCE_DIR}/ext/geogram/cmake/geo_detect_platform.cmake)

set(GEOGRAM_LIB_ONLY ON)
set(GEOGRAM_SOURCE_DIR "${CMAKE_SOURCE_DIR}/ext/geogram/" CACHE PATH "full path to the Geogram (or Vorpaline) installation")

set(
  SRCFILES
  src/shared.cpp
  src/MyGui.cpp
)

#################
# DEPENDENCIES
#################

# Geogram
add_subdirectory(ext/geogram)

set(
  EXTERNAL_LIBS
  geogram
  geogram_gfx
  ${GLFW_LIBRARIES}
)

#################
# LIBRARY
#################

add_library(lib STATIC ${SRCFILES})
target_include_directories(lib PRIVATE include)
target_link_libraries(lib PRIVATE ${EXTERNAL_LIBS})

#################
# EXECUTABLES
#################

add_executable(cli apps/cli.cpp)
target_include_directories(cli PRIVATE include)
target_link_libraries(cli PRIVATE lib ${EXTERNAL_LIBS})

add_executable(gui apps/gui.cpp)
target_include_directories(gui PRIVATE include)
target_link_libraries(gui PRIVATE lib ${EXTERNAL_LIBS})