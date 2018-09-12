#include "simulationrenderer.h"
SimulationRenderer::SimulationRenderer(QWidget *parent, SimulationSnapshot snapshot,  std::function<void(Point)> onClick) : QWidget(parent)
{

    this->onClick = onClick;
    this->snapshot = snapshot;
    this->pixmap = QPixmap(600,450);
    this->label = new QLabel(this);
    this->label->setFixedWidth(600);
    this->label->setFixedHeight(450);
    auto layout = new QHBoxLayout(this);
    brushes[0] = QBrush(QColor(200,200,200));
    brushes[1] = QBrush(QColor(0,255,0));
    brushes[2] = QBrush(QColor(0,0,255));
    brushes[3] = QBrush(QColor(194,178,128));
    layout->addStretch(1);
    layout->addWidget(this->label);



    setLayout(layout);
    paintArea();
}

void SimulationRenderer::mousePressEvent(QMouseEvent *event)
{
    auto pos = event->pos();
    auto labelpos = this->label->pos();
    auto X = pos.x() - labelpos.x();
    auto Y = pos.y() - labelpos.y();

    if(X >= this->label->width() || X < 0 || Y < 0 || Y > this->label->height())
    {
        return;
    }

    X = X*Area::getWidth() / this->label->width();
    Y = Y*Area::getHeight() / this->label->height();
    Point point;
    point.setX(X);
    point.setY(Y);
    onClick(point);

}

void SimulationRenderer::paintArea()
{

    this->painter = new QPainter(&pixmap);
    for(int i = 0; i < Area::getWidth(); i++)
        for(int j = 0;j <Area::getHeight();j++)

        {
            Point p;
            p.setX(i);
            p.setY(j);
            paintPoint(p);
        }
    delete this->painter;

    this->label->setPixmap(this->pixmap);

}

QPoint SimulationRenderer::paintPoint(Point p)
{
    auto labelWidth = this->label->width();
    auto labelHeight = this->label->height();
    auto X = p.getX()*labelWidth/Area::getWidth();
    auto Y = p.getY()*labelHeight/Area::getHeight();
    int value = this->snapshot.getArea().getTile(p);
    this->painter->setBrush(brushes[value]);

    this->painter->drawRect(X,Y,labelWidth/Area::getWidth(),labelHeight/Area::getHeight());
    if(this->snapshot.containsUnit(p))
    {
        auto simUnit = snapshot.getUnit(p);

        auto unit = simUnit.getUnit();
        auto texture = QPixmap::fromImage(unit.getIcon());
        if(simUnit.getArmy()==1)
        {
         QTransform transform;
         auto trans = transform.rotate(180);
         texture = QPixmap(texture.transformed(trans));

        }
        this->painter->drawPixmap(QPoint(X,Y),texture.scaled(getWidth()/Area::getWidth(),getHeight()/Area::getHeight(),Qt::KeepAspectRatio));
    }
    return QPoint(X,Y);

}

int SimulationRenderer::getWidth()
{
    return this->label->width();
}

int SimulationRenderer::getHeight()
{
    return this->label->height();
}

void SimulationRenderer::setSnapshot(SimulationSnapshot snapshot)
{
    this->snapshot = snapshot;
    paintArea();
}
