CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2)
PROJECT(RoadFighter)

SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/Modules/)
SET(CMAKE_CXX_FLAGS  "-Wall")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

FIND_PACKAGE(SFML 2.4.2 COMPONENTS graphics system window)

FILE(GLOB SRC src/*.cpp src/*.h)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

SET(RF_INCLUDE_DIR lib/roadfighter)
ADD_SUBDIRECTORY(lib/roadfighter)

INCLUDE_DIRECTORIES(${RF_INCLUDE_DIR})

SET(ROADFIGHTER_SRC
        main/main.cpp main/Game.cpp main/Game.h
        main/Singletons/Transformation.cpp main/Singletons/Transformation.h
        main/Singletons/Random.cpp main/Singletons/Random.h

        roadfighterSFML/PlayerCarSFML.cpp roadfighterSFML/PlayerCarSFML.h
        roadfighterSFML/RacingCarSFML.cpp roadfighterSFML/RacingCarSFML.h
        roadfighterSFML/SFMLFactory.cpp roadfighterSFML/SFMLFactory.h
        roadfighterSFML/TruckSFML.cpp roadfighterSFML/TruckSFML.h roadfighterSFML/LorrySFML.cpp roadfighterSFML/LorrySFML.h roadfighterSFML/Explosion.cpp roadfighterSFML/Explosion.h)

ADD_EXECUTABLE(RoadFighter ${ROADFIGHTER_SRC})
TARGET_LINK_LIBRARIES(RoadFighter ${SFML_LIBRARIES})
TARGET_LINK_LIBRARIES(RoadFighter roadfighter)
ADD_DEPENDENCIES(RoadFighter roadfighter)




