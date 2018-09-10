#ifndef MAPLIST_H
#define MAPLIST_H
#include <QtWidgets>
class MapList : public QWidget
{
    Q_OBJECT
    QList<QButton*> maps;
public:
    MapList(QWidget* parent, std::function<void(std::string)> onClick);
};
#endif // MAPLIST_H
