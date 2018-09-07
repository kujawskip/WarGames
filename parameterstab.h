
#ifndef PARAMETERSTAB_H
#define PARAMETERSTAB_H
#include <QtWidgets>
#include "parameters.h"
class ParametersTab : public QWidget
{
    Q_OBJECT

public:
    explicit ParametersTab(QWidget *parent = 0, SimulationParameters* parameters = 0);
};
#endif PARAMETERSTAB_H
