#include <iostream>
using namespace std;

struct Node{
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr){}
};

class LRUCache {
public:
    LRUCache(int capacity){
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }

    int get(int key){
        if(cacheMap.find(key) == cacheMap.end()){
            return -1;
        }
        Node *node = cacheMap[key];
        if(node != head){
            node -> prev -> next = node -> next;
            node -> next -> prev = node -> prev;
            moveToHead(node);
        }
        return node -> value;
    }

    void put(int key, int value){
        // if the key is already in the cache
        if(cacheMap.find(key) != cacheMap.end()){
            Node *node = cacheMap[key];
            node -> value = value;
            node -> prev -> next = node -> next;
            node -> next -> prev = node -> prev;
            moveToHead(node);
        }else{
            // if the key is not in the cache
            Node *node = new Node(key, value);
            cacheMap[key] = node;
            moveToHead(node);
            if(cacheMap.size() > capacity){
                Node *node = tail -> prev;
                node -> prev -> next = tail;
                tail -> prev = node -> prev;
                cacheMap.erase(node -> key);
                delete node;
            }
        }
    }

    void prinCacheData(){
        char buffer[100];
        int offset = 0;
        offset += snprintf(buffer + offset, 100 - offset, "head ->");
        Node *node = head -> next;
        while(node != tail){
            offset += snprintf(buffer + offset, 100 - offset, "(key=%d, value=%d) -> ", node -> key, node -> value);
            node = node -> next;
        }
        offset += snprintf(buffer + offset, 100 - offset, "tail");
        buffer[offset] = '\0';
        cout << buffer << endl;
    }
private:
    int capacity;
    Node *head;
    Node *tail;
    unordered_map<int, Node*> cacheMap;

     void moveToHead(Node *node){
        node -> next = head -> next;
        head -> next -> prev = node;
        head -> next = node;   
        node -> prev = head;
    }
};