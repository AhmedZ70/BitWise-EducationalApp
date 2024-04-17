#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "circuit.h"
#include "levels.h"
#include <vector>

class GameModel {

private:

    int currentLevel;

    std::vector<levels> levels;

public:

    GameModel();

    bool computeLevelCiruit(int currentLevel);

};

#endif // GAMEMODEL_H
