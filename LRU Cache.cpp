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
    map<int, list<Node>::iterator> mp;
    list<Node> theList;
public:
    LRUCache(int capacity) {
        maxSize = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            theList.erase(mp[key]);
            theList.push_front(*mp[key]);
            mp[key] = theList.begin();
            return mp[key]->value;
        }
        else
            return -1;
        
    }
    
    void set(int key, int value) {
        Node newNode(key, value);
        if (mp.find(key) == mp.end()) {//doesn't find insert
            if (theList.size() == maxSize) { //full
                mp.erase(theList.back().key);
                theList.pop_back();
                theList.push_front(newNode);
                mp[key] = theList.begin();
            }
            else {
                theList.push_front(newNode);
                mp[key] = theList.begin();
            }
        }
        else { //found so set
            theList.erase(mp[key]);
            theList.push_front(newNode);
            mp[key] = theList.begin();
        }
    }
};
