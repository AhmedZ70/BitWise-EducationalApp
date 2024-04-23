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
#include "levelTen.h"
#include "levelEleven.h"
#include "levelTwelve.h"
#include <algorithm>
#include <iostream>

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name GameModel header file for assignment9
 * This cpp file defines and implements  the GameModel class which manages game levels and handles logic
 * for circuit simulation based on user interactions in a digital circuit simulation game.
 */
GameModel::GameModel(QObject *parent) : QObject(parent), currentLevel(0){
    // Push all premade levels
    levels.push_back(std::make_unique<LevelOne>());
    levels.push_back(std::make_unique<LevelTwo>());
    levels.push_back(std::make_unique<LevelThree>());
    levels.push_back(std::make_unique<LevelFour>());
    levels.push_back(std::make_unique<LevelFive>());
    levels.push_back(std::make_unique<LevelSix>());
    levels.push_back(std::make_unique<LevelSeven>());
    levels.push_back(std::make_unique<LevelEight>());
    levels.push_back(std::make_unique<LevelNine>());
    levels.push_back(std::make_unique<LevelTen>());
    levels.push_back(std::make_unique<LevelEleven>());
    levels.push_back(std::make_unique<LevelTwelve>());
}

void GameModel::computeLevelCircuit(int currentLevel){
    levels[currentLevel]->computeOutput();

    bool result = levels[currentLevel]->getResult();
    emit circuitCompleted(result);
}
void GameModel:: onInputReceived(std::vector<bool>inputs)
{
    levels[currentLevel]->setInput(inputs);
    computeLevelCircuit(currentLevel);
}

void GameModel::checkUserGate(string gate)
{
    cout << gate << endl;
    cout << currentLevel << endl;
    bool gateCorrect = levels[currentLevel]->correctUserGate(gate);
    emit correctGate(gateCorrect);
}

void GameModel::setGateDropped(const std::vector<std::string>& gateTypese){
    if (hasEmptyString(gateTypese)){
        throw std::invalid_argument("One or more gate types are empty.");
    }
    else {
         levels[currentLevel]->setGateTypes(gateTypese);
    }

}

bool GameModel::hasEmptyString(const std::vector<std::string>& gateTypes) {
    return std::find(gateTypes.begin(), gateTypes.end(), "") != gateTypes.end();
}

void GameModel::onGetCurrentLevel(int level)
{
    currentLevel = level-1;
}
