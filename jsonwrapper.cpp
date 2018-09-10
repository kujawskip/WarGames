#include "jsonwrapper.h"

template<>
bool isInstanceOf<int>(QJsonValue object )
{
    return object.isDouble();
}
template<>
bool isInstanceOf<double>(QJsonValue object )
{
    return object.isDouble();
}
template<>
bool isInstanceOf<QString>(QJsonValue object )
{
    return object.isString();
}
template<>
bool isInstanceOf<std::string>(QJsonValue object )
{
    return object.isString();
}
template<>
void asInstanceOf<double>(double& value, QJsonValue object)
{
    value = object.toDouble();
}
template<>
void asInstanceOf<int>(int& value, QJsonValue object)
{
    value = object.toDouble();
}
template<>
void asInstanceOf<QString>(QString& value, QJsonValue object)
{
    value = object.toString();
}
template<>
void asInstanceOf<std::string>(std::string& value, QJsonValue object)
{
    value = object.toString().toStdString();
}

QJsonDocument loadJson(QString fileName)
{
   QFile jsonFile(fileName);
   jsonFile.open(QFile::ReadOnly);
   auto byteArray = jsonFile.readAll();

   QJsonParseError error;
   auto result = QJsonDocument().fromJson(byteArray,&error);
   /*fprintf(stderr,"%d\n",error.offset);
   fprintf(stderr,"%s\n",error.errorString().toStdString().c_str());*/
   return result;
}
