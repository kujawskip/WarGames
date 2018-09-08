#ifndef JSONWRAPPER_H
#define JSONWRAPPER_H
#include <QJsonObject>
#include <vector>
template <typename T>
bool isInstanceOf(QJsonValue value)
{
    return true;
}


template <typename T>
bool isInstanceOf(QJsonObject object,QString key)
{
 return object.contains(key) && isInstanceOf<T>(object[key]);
}

template <typename T>
void asInstanceOf(T& arg, QJsonValue value);


template <typename T>
void asInstanceOf(T& value, QJsonObject object, QString key)
{
    asInstanceOf<T>(value, object[key]);
}

template<typename T>
bool tryRead(T& value,QJsonObject object, QString key)
{
    if(isInstanceOf<T>(object,key))
    {
        asInstanceOf<T>(value,object,key);
        return true;
    }
    return false;

}

template<typename T>
bool tryReadArray(std::vector<T>& value, QJsonObject object, QString key)
{
    bool result = true;
    if(object.contains(key) && object[key].isArray())
    {
        QJsonArray valuesArray = object[key].toArray();
        for (int index = 0; index < valuesArray.size(); ++index) {
                   T item;
                   auto isInstance = isInstanceOf<T>(valuesArray[index]);
                   if(isInstance)
                   {
                       asInstanceOf<T>(item, valuesArray[index]);
                       value.push_back(item);
                   }
                   result &= isInstance;
               }


        return result;
    }
    return false;
}

template<>
bool isInstanceOf<int>(QJsonValue object );

template<>
bool isInstanceOf<double>(QJsonValue object );
template<>
bool isInstanceOf<QString>(QJsonValue object );
template<>
bool isInstanceOf<std::string>(QJsonValue object );

template<>
void asInstanceOf<double>(double& value, QJsonValue object);
template<>
void asInstanceOf<int>(int& value, QJsonValue object);
template<>
void asInstanceOf<QString>(QString& value, QJsonValue object);
template<>
void asInstanceOf<std::string>(std::string& value, QJsonValue object);
#endif // JSONWRAPPER_H
