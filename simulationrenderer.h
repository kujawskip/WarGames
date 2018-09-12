#ifndef Simrenderer
#define Simrenderer
#include <QtWidgets>
#include "area.h"
#include "point.h"
#include "simulationsnapshot.h"

class SimulationRenderer :public QWidget {
    Q_OBJECT
    std::function<void(Point)> onClick;


    QPixmap pixmap;
    QLabel* label;
    QBrush brushes[4];


protected:
    SimulationSnapshot snapshot;
    QPainter* painter;
public:
    int getWidth();
    int getHeight();
    virtual QPoint paintPoint(Point p);
    void mousePressEvent(QMouseEvent* event);
    virtual void paintArea();
    void setSnapshot(SimulationSnapshot snapshot);
    SimulationRenderer(QWidget* parent,SimulationSnapshot snapshot, std::function<void(Point)> onClick);
};
#endif // Simrenderer
