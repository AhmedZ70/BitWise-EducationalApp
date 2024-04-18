#include "gameModel.h"
#include "levelone.h"
#include "leveltwo.h"
#include "levelThree.h"
#include "levelFour.h"
#include "levelFive.h"
#include "levelSix.h"
#include "levelSeven.h"
#include "levelEight.h"
#include "levelNine.h"
#include <iostream>

GameModel::GameModel(QObject *parent) : QObject(parent), currentLevel(0){

    levels.push_back(std::make_unique<LevelOne>());
    levels.push_back(std::make_unique<LevelTwo>());
    levels.push_back(std::make_unique<LevelThree>());
    levels.push_back(std::make_unique<LevelFour>());
    levels.push_back(std::make_unique<LevelFive>());
    levels.push_back(std::make_unique<LevelSix>());
    levels.push_back(std::make_unique<LevelSeven>());
    levels.push_back(std::make_unique<LevelEight>());
    levels.push_back(std::make_unique<LevelNine>());
}

void GameModel::computeLevelCircuit(int currentLevel){
    levels[currentLevel]->computeOutput();

    bool result = levels[currentLevel]->getResult();

    emit circuitCompleted(result);
}
void GameModel:: onInputReceived(std::vector<bool>inputs)
{
    levels[currentLevel]->setInput(inputs);
}

