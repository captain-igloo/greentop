/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <list>
#include <unordered_map>
#include <assert.h>

namespace greentop {

template <typename K, typename V>
class LRUCache {

    public:
        LRUCache(uint64_t maxSize) : maxSize(maxSize) {
        };

        void put(const K& key, const V& value) {
            auto it = cacheMap.find(key);
            if (it != cacheMap.end()) {
                cacheList.erase(it->second);
                cacheMap.erase(it);
            }
            cacheList.push_front(std::make_pair(key, value));
            cacheMap.insert(std::make_pair(key, cacheList.begin()));
            clean();
        }

        V get(const K& key) {
            auto it = cacheMap.find(key);
            cacheList.splice(cacheList.begin(), cacheList, it->second);

            return it->second->second;
        }

        bool exists(const K &key) const {
            return (cacheMap.count(key) > 0);
        };

        void clear() {
            cacheList.clear();
            cacheMap.clear();
        }

    private:
        std::list<std::pair<K, V>> cacheList;
        std::unordered_map<K, decltype(cacheList.begin())> cacheMap;
        uint64_t maxSize;

        void clean() {
            while (cacheMap.size() > maxSize) {
                auto lastIt = cacheList.end();
                lastIt--;
                cacheMap.erase(lastIt->first);
                cacheList.pop_back();
            }
        };

};

}

#endif // LRU_CACHE_H
