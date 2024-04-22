#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <vector>
#include "circuitLevel.h"
#include <vector>
#include <QObject>
#include <memory>
class GameModel : public QObject {
    Q_OBJECT

private:
    int currentLevel;
    std::vector<std::unique_ptr<CircuitLevel>> levels;
     void computeLevelCircuit(int currentLevel);

public:
    explicit GameModel(QObject *parent = nullptr);

signals:
    void circuitCompleted(bool completed);
    void correctGate(bool correctGate);

public slots:
    void onInputReceived(std::vector<bool>inputs, int currentLevel);
    void checkUserGate(string gate);



};

#endif // GAMEMODEL_H
