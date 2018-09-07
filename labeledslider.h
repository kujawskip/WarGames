#ifndef LABELEDSLIDER_H
#define LABELEDSLIDER_H
#include <vector>
#include <functional>
#include <QtWidgets>
class LabeledSlider : public QWidget
{
private:
    Q_OBJECT
    std::vector<int> values;
    std::string prefix;
    std::string suffix;
    QSlider* slider;
    QLabel* valueLabel;
    std::string getLabel();
public slots:
    void onValueChanged(int value);
public:
    explicit LabeledSlider(QWidget *parent, std::vector<int> values, std::function<void(int)> callBack, std::string label = "", std::string prefix = "", std::string suffix = "");
    int getValue();
};
#endif // LABELEDSLIDER_H
