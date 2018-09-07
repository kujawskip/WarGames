#ifndef PLACEMENTTAB_H
#define PLACEMENTTAB_H
#include <QtWidgets>
#include "placement.h"
class PlacementTab : public QWidget
{
    Q_OBJECT

public:
    explicit PlacementTab(QWidget *parent, Placement& placement);
};
#endif // PLACEMENTTAB_H
