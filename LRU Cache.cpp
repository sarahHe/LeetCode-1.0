// Design and implement a data structure for Least Recently Used (LRU) cache. 
// It should support the following operations: get and set.

// get(key) - Get the value (will always be positive) of the key if the 
// key exists in the cache, otherwise return -1.
// set(key, value) - Set or insert the value if the key is not already 
// present. When the cache reached its capacity, it should invalidate the 
// least recently used item before inserting a new item.


// 那就是利用链表和hashmap。当需要插入新的数据项的时候，如果新数据项在链表中存在
// （一般称为命中），则把该节点移到链表头部，如果不存在，则新建一个节点，
// 放到链表头部，若缓存满了，则把链表最后一个节点删除即可。在访问数据的时候，
// 如果数据项在链表中存在，则把该节点移到链表头部，否则返回-1。
// 这样一来在链表尾部的节点就是最近最久未访问的数据项。
// 其实在STL中的list就是一个双向链表，如果希望代码简短点，可以用list来实现：

//be careful about the type
struct Node {
    int key;
    int value;
    Node(int k, int v):key(k),value(v){};
};
    
class LRUCache{
private:
    int maxSize;
    list<Node> cacheList;
    map<int, list<Node>::iterator > mp;
    
public:
    LRUCache(int capacity) {
        maxSize = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        else {
            list<Node>::iterator it = mp[key];
            Node newNode(key, it->value);
            cacheList.erase(it);
            cacheList.push_front(newNode);
            mp[key] = cacheList.begin();
            return it->value;
        }
    }
    
    void set(int key, int value) {
        map<int, list<Node>::iterator >::iterator it = mp.find(key);
        if (it == mp.end()) {
            if (cacheList.size() == maxSize) {
                mp.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            Node newNode(key, value);
            cacheList.push_front(newNode);
            mp[key] = cacheList.begin();
        }
        else {
            Node newNode(key, value);
            cacheList.erase(mp[key]);
            cacheList.push_front(newNode);
            mp[key] = cacheList.begin();
        }
    }
};
