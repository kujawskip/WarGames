#ifndef LABELEDLABEL_H
#define LABELEDLABEL_H
#include <QtWidgets>
class LabeledLabel :public QWidget
{
    Q_OBJECT
    QLabel* label;
    QLabel* labeledLabel;
public:
    LabeledLabel(QWidget* parent);
    QLabel* getLabel();
    QLabel* getLabeledLabel();
};
#endif // LABELEDLABEL_H
