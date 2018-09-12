#ifndef MAPLIST_H
#define MAPLIST_H
#include <QtWidgets>
#include <QList>

class MapList : public QWidget
{
    Q_OBJECT
    QList<QPushButton*> maps;
    std::function<void(std::string)> onClick;
public:
    void HandleButtonPress();
    MapList(QWidget* parent, std::function<void(std::string)> onClick);
};
#endif // MAPLIST_H
