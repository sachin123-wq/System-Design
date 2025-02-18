#include "LRU_Cache.hpp"

int main(){
    LRUCache lrucache(3);
    lrucache.put(1, 1);
    lrucache.put(2, 2);
    cout << "For key = 1 " << "value is " << lrucache.get(1) << endl;
    lrucache.put(3, 3);
    cout << "For key = 2 " << "value is " << lrucache.get(2) << endl;
    lrucache.prinCacheData();
    lrucache.put(4, 4);
    lrucache.prinCacheData();
    cout << "For key = 5 " << "value is " << lrucache.get(5) << endl;
    return 0;
}