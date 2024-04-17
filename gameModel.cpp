#include "gameModel.h"
#include "levelone.h"
#include "leveltwo.h"
#include "levelThree.h"
#include "levelFour.h"
#include "levelFive.h"
#include "levelSix.h"

GameModel:: GameModel(){

    levels.push_back(std::make_unique<LevelOne>());
    levels.push_back(std::make_unique<LevelTwo>());
    levels.push_back(std::make_unique<LevelThree>());
    levels.push_back(std::make_unique<LevelFour>());
    levels.push_back(std::make_unique<LevelFive>());
    levels.push_back(std::make_unique<LevelSix>());

    currentLevel = 0;
}
