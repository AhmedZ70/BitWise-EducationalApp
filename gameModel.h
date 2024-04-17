#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <vector>
#include "circuitLevel.h"
#include <vector>
#include <QObject>
#include <memory>
class GameModel: public QObject {

private:

    int currentLevel;
    std::vector<std::unique_ptr<CircuitLevel>> levels;

public:

    GameModel();

    bool computeLevelCiruit(int currentLevel);

signals:

public slots:



};

#endif // GAMEMODEL_H
