#ifndef LABELEDLINEEDIT_H
#define LABELEDLINEEDIT_H
#include <QtWidgets>
#include <functional>
class LabeledLineEdit : public QWidget
{
private:
    Q_OBJECT
    QLineEdit* slider;
    QLabel* valueLabel;
    std::function<void(const QString&)> callBack;
public slots:
    void onValueChanged(const QString& value);
public:
    explicit LabeledLineEdit(QWidget *parent,std::function<void(const QString&)> callBack,std::string label = "");
    QString getValue();
};
#endif // LABELEDLINEEDIT_H
