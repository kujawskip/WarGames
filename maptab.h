#ifndef SQUADTAB_H
#define SQUADTAB_H
#include <QtWidgets>
#include "area.h"
#include "mapprovider.h"
#include "arearenderer.h"
class MapTab : public QWidget
{
    Q_OBJECT
    Area& area;
    void TogglePassable(Point p);
    void ToggleSeethrough(Point p);

    AreaRenderer* areaRenderer;
public:
    void LoadArea(std::string key);
    explicit MapTab(QWidget *parent, Area& area);
};
#endif // SQUADTAB_H
