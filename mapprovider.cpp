#include "mapprovider.h"
#include "jsonmap.h"
void MapProvider::load(QJsonObject object)
{

    std::vector<JsonMap> maps;

    this->loadedMaps.clear();
    tryReadArray(maps, object, "maps");

    for(auto& jsonmap : maps)
    {
        this->loadedMaps.insert(this->loadedMaps.end(), std::pair<std::string,QJsonValue>(jsonmap.getName(),jsonmap.getValue()));
    }

}

QJsonValue MapProvider::getMap(std::string key)
{
    return loadedMaps[key];
}

std::vector<std::string> MapProvider::getMapList()
{
    std::vector<std::string> result;
    for(auto& keyValuePair : loadedMaps)
    {
        result.push_back(keyValuePair.first);
    }
    return result;
}
