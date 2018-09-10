#ifndef MAPPROVIDER_H
#define MAPPROVIDER_H
#include <map>
#include <vector>
#include <QJsonObject>


class MapProvider
{
    public:
        static MapProvider& getInstance()
        {
            static MapProvider    instance;

            return instance;
        }
    private:

        std::map<std::string,QJsonValue> loadedMaps;

        MapProvider()
        {

        }
    public:
        MapProvider(MapProvider const&)               = delete;
        void operator=(MapProvider const&)  = delete;
        void load(QJsonObject object);
        QJsonValue getMap(std::string key);
        std::vector<std::string> getMapList();
};
#endif // MAPPROVIDER_H
