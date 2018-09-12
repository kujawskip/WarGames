#include "arearenderer.h"
#include "labeledlabel.h"
AreaRenderer::AreaRenderer(QWidget *parent, Area &area,  std::function<void(Point)> onClick,std::function<void(Point)> onRightClick, bool useLegend) : QWidget(parent), area(area)
{

    this->onClick = onClick;
    this->onRightClick = onRightClick;
    this->pixmap = QPixmap(400,300);
    this->label = new QLabel(this);
    this->label->setFixedWidth(400);
    this->label->setFixedHeight(300);
    auto layout = new QHBoxLayout(this);
    brushes[0] = QBrush(QColor(200,200,200));
    brushes[1] = QBrush(QColor(0,255,0));
    brushes[2] = QBrush(QColor(0,0,255));
    brushes[3] = QBrush(QColor(194,178,128));
    layout->addStretch(1);
    layout->addWidget(this->label);

    if(useLegend)
    {
        auto legendLayout = new QVBoxLayout(this);
        legendLayout->addStretch(1);
        for(int i = 0; i< 4; i++)
        {
            auto labeledLabel = new LabeledLabel(this);
            auto legendPixmap = QPixmap(40,48);
            auto painter = new QPainter(&legendPixmap);
            painter->setBrush(brushes[i]);
            painter->drawRect(0,0,40,48);
            delete painter;
            labeledLabel->getLabel()->setFixedWidth(40);
            labeledLabel->getLabel()->setFixedHeight(48);
            labeledLabel->getLabel()->setPixmap(legendPixmap);
            labeledLabel->getLabeledLabel()->setText(descriptions[i]);
            legendLayout->addWidget(labeledLabel);
            legendLayout->setAlignment(labeledLabel, Qt::AlignLeft);
        }
        layout->addLayout(legendLayout);
        layout->setAlignment(legendLayout,Qt::AlignLeft);
    }


    setLayout(layout);
    paintArea();
}

void AreaRenderer::mousePressEvent(QMouseEvent *event)
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

    if(event->button() == Qt::LeftButton)
    {
        onClick(point);

    }
    if(event->button() == Qt::RightButton)
    {
        onRightClick(point);

    }
    this->painter = new QPainter(&pixmap);
    paintPoint(point);
    delete this->painter;
    this->label->setPixmap(this->pixmap);
}

void AreaRenderer::paintArea()
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

QPoint AreaRenderer::paintPoint(Point p)
{
    auto labelWidth = this->label->width();
    auto labelHeight = this->label->height();
    auto X = p.getX()*labelWidth/Area::getWidth();
    auto Y = p.getY()*labelHeight/Area::getHeight();
    int value = area.getTile(p);
    this->painter->setBrush(brushes[value]);

    this->painter->drawRect(X,Y,labelWidth/Area::getWidth(),labelHeight/Area::getHeight());
    return QPoint(X,Y);

}

int AreaRenderer::getWidth()
{
    return this->label->width();
}

int AreaRenderer::getHeight()
{
    return this->label->height();
}
