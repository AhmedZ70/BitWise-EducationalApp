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

public:
    explicit GameModel(QObject *parent = nullptr);

signals:
    void circuitCompleted(bool completed);

public slots:
    void onInputReceived(std::vector<bool>inputs, int currentLevel);
    void computeLevelCircuit(int currentLevel);
    void setGateDropped(const std::vector<std::string>& gateTypese);



};

#endif // GAMEMODEL_H
