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
        "Game Representation/State.cpp"
        "Game Representation/EntityView.h"
        "Game Representation/EntityView.cpp"
        "Game Representation/Camera.h"
        "Game Representation/Camera.cpp"
        "Game Representation/Entities/PacManView.h"
        "Game Representation/Entities/PacManView.cpp"
        "Game Representation/Entities/GhostView.h"
        "Game Representation/Entities/GhostView.cpp"
        "Game Representation/Entities/CoinView.h"
        "Game Representation/Entities/CoinView.cpp"
        "Game Representation/Entities/FruitView.h"
        "Game Representation/Entities/FruitView.cpp"
        "Game Representation/Entities/WallView.h"
        "Game Representation/Entities/WallView.cpp"
        "Logic Library/World.cpp"
        "Logic Library/EntityModel.h"
        "Logic Library/EntityModel.cpp"
        "Logic Library/Entities/GhostModel.h"
        "Logic Library/Entities/GhostModel.cpp"
        "Logic Library/Entities/CoinModel.h"
        "Logic Library/Entities/CoinModel.cpp"
        "Logic Library/Entities/FruitModel.h"
        "Logic Library/Entities/FruitModel.cpp"
        "Logic Library/Entities/PacManModel.h"
        "Logic Library/Entities/PacManModel.cpp"
        "Logic Library/Entities/WallModel.h"
        "Logic Library/Entities/WallModel.cpp"
        "Logic Library/AbstractFactory.h"
        "Logic Library/AbstractFactory.cpp"
        "Game Representation/ConcreteFactory.h"
        "Game Representation/ConcreteFactory.cpp"
        "Logic Library/Observer.h"
        "Logic Library/Observer.cpp"
        "Game Representation/RenderWindow.h"
        "Game Representation/RenderWindow.cpp"
        "Logic Library/StopWatch.h"
        "Logic Library/StopWatch.cpp"
        "Logic Library/Score.h"
        "Logic Library/Score.cpp"
        "Logic Library/Random.h"
        "Logic Library/Random.cpp"
        "Logic Library/Stats.h"
        "Logic Library/Stats.cpp"
        "Logic Library/Entities/BananaModel.h"
        "Logic Library/Entities/BananaModel.cpp"
        "Game Representation/Entities/BananaView.h"
        "Game Representation/Entities/BananaView.cpp"
)

# Add include dirs for SFML
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_EXECUTABLE(ProjectAP ${SRC}
        "main.cpp")

# Link target to SFML libs
TARGET_LINK_LIBRARIES(ProjectAP sfml-system sfml-graphics sfml-window)

# Install our executable to the CMAKE_INSTALL_PREFIX/bin
INSTALL(TARGETS ProjectAP DESTINATION bin)