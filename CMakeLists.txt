CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)
PROJECT(ProjectAP)
IF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    SET (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE)
ENDIF()

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# The source files to compile
SET(SRC main.cpp
        "Game Representation/Game.h"
        "Game Representation/Game.cpp"
        "Game Representation/StateManager.h"
        "Game Representation/StateManager.cpp"
        "Game Representation/States/VictoryState.h"
        "Game Representation/States/VictoryState.cpp"
        "Game Representation/States/PausedState.h"
        "Game Representation/States/PausedState.cpp"
        "Game Representation/States/MenuState.h"
        "Game Representation/States/MenuState.cpp"
        "Game Representation/States/LevelState.h"
        "Game Representation/States/LevelState.cpp"
        "Game Representation/States/GameOverState.h"
        "Game Representation/States/GameOverState.cpp"
        "Game Representation/State.h"
        "Game Representation/State.cpp")

# Add include dirs for SFML
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_EXECUTABLE(ProjectAP ${SRC}
        "main.cpp")

# Link target to SFML libs
TARGET_LINK_LIBRARIES(ProjectAP sfml-system sfml-graphics sfml-window)

# Install our executable to the CMAKE_INSTALL_PREFIX/bin
INSTALL(TARGETS ProjectAP DESTINATION bin)