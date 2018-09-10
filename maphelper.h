#ifndef MAPHELPER_H
#define MAPHELPER_H
#include <map>

template<typename T_key,typename T_val>
T_val getOrSet(std::map<T_key,T_val>& valueMap, T_key key, T_val defaultValue)
{
    printf("fire\n");
    auto valueIterator = valueMap.find(key);
    if(valueIterator == valueMap.end())
    {
      valueMap[key] = defaultValue;
      return defaultValue;
    }

    return valueIterator->second;
}
#endif // MAPHELPER_H
