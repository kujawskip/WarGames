#ifndef AREARENDERER_H
#define AREARENDERER_H
#include <QtWidgets>
#include "area.h"
#include "point.h"
class AreaRenderer :QWidget {
Q_OBJECT
std::function<void(Point)> onClick();
std::function<void(Point)> onRightClick();
Area area;
void repaint(Point p);

public:
    void mousePressedEvent(QMouseEvent* event);
    void repaint();
    AreaRenderer(QWidget* parent,Area& area);
};
#endif // AREARENDERER_H
