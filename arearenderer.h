#ifndef AREARENDERER_H
#define AREARENDERER_H
#include <QtWidgets>
#include "area.h"
#include "point.h"
static QString descriptions[] = {
    "Skały \n(nie do przejścia, zasłaniają widok)",
    "Krzaki \n(do przejścia, zasłaniają widok)",
    "Woda \n(nie do przejścia, widać przez nią)",
    "Ziemia \n(można przejsć i widzieć)"

};

class AreaRenderer :public QWidget {
    Q_OBJECT
    std::function<void(Point)> onClick;
    std::function<void(Point)> onRightClick;

    QPixmap pixmap;
    QLabel* label;
    QBrush brushes[4];


protected:
    Area& area;
    QPainter* painter;
public:
    int getWidth();
    int getHeight();
    virtual QPoint paintPoint(Point p);
    void mousePressEvent(QMouseEvent* event);
    virtual void paintArea();
    AreaRenderer(QWidget* parent,Area& area, std::function<void(Point)> onClick,std::function<void(Point)> onRightClick, bool useLegend = true);
};
#endif // AREARENDERER_H
