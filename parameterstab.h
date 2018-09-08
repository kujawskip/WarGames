
#ifndef PARAMETERSTAB_H
#define PARAMETERSTAB_H
#include <QtWidgets>
#include "parameters.h"
class ParametersTab : public QWidget
{
    Q_OBJECT
    SimulationParameters parameters;
public:
    explicit ParametersTab(QWidget *parent, SimulationParameters& parameters);

};
#endif PARAMETERSTAB_H
