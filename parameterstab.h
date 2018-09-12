
#ifndef PARAMETERSTAB_H
#define PARAMETERSTAB_H
#include <QtWidgets>
#include "parameters.h"
class ParametersTab : public QWidget
{
    Q_OBJECT
    SimulationParameters& parameters;
    std::function<void()> onStart;
    void setAccuracy(int value);
    void setSpeed(int value);
    void setString(std::string value);
    void setDamage(int value);
public:
    explicit ParametersTab(QWidget *parent, SimulationParameters& parameters,std::function<void()> onStart);
    void startButtonClicked();
};
#endif PARAMETERSTAB_H
