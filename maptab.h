#ifndef SQUADTAB_H
#define SQUADTAB_H
#include <QtWidgets>
#include "area.h"
class MapTab : public QWidget
{
    Q_OBJECT

public:
    explicit MapTab(QWidget *parent, Area& area);
};
#endif // SQUADTAB_H
