#ifndef JSONMAP_H
#define JSONMAP_H
#include "jsonwrapper.h"
class JsonMap {
    std::string name;
    QJsonValue value;
public:
    std::string getName();
    QJsonValue getValue();
    void read(QJsonObject);
};

template<>
void asInstanceOf<JsonMap>(JsonMap &value, QJsonValue object);

#endif // JSONMAP_H
