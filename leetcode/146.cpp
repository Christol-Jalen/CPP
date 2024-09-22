// 146.LRU缓存
#include <unordered_map>
using namespace std;

struct DLinkedNode{
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr){}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr){}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache; // 哈希表<链表node>
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        size = 0;
        // 使用伪头部与伪尾部
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        // 如果key不存在缓存中
        if(!cache.count(key)){ 
            return -1;
        }
        // 如果key存在，先通过哈希表定位，再移动到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            // 如果key不存在，则创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key,value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表头部
            addToHead(node);
            ++size;
            if(size > capacity){
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed; // 防止内存泄露
                --size;
                }
            }
            else{
                DLinkedNode* node = cache[key];
                node->value = value;
                moveToHead(node);
            }
    }

    //--------------Helper Functions-----------
    void moveToHead(DLinkedNode* node){
        removeNode(node);
        addToHead(node);
    }

    void removeNode(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(DLinkedNode* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    DLinkedNode* removeTail(){
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */