cmake_minimum_required(VERSION 3.10.2)
project(RoadFighter)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/Modules/)
SET(CMAKE_CXX_FLAGS  "-Wall")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

FIND_PACKAGE(SFML 2.4.2 COMPONENTS graphics system window)

FILE(GLOB SRC src/*.cpp src/*.h)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

set(RF_SOURCES ./main/resources/lib/roadfighter/Entity.h ./main/resources/lib/roadfighter/Entity.cpp)

add_library(rf SHARED ${RF_SOURCES})

set(SOURCE_FILES main/cpp/main.cpp main/cpp/Transformation.cpp main/cpp/Transformation.h)

add_executable(RoadFighter ${SOURCE_FILES})

target_link_libraries(RoadFighter ${SFML_LIBRARIES})
target_link_libraries(RoadFighter rf)

