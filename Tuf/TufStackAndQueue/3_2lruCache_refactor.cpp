#include <bits/stdc++.h>
using namespace std;

//Just refactoring of the previous code :)

struct Node{
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(){
        next = prev = 0;
        value = 0;
    }
};
Node mempool[100001];
int node_ind = 0;


Node *getNode(int key, int val = 0){
    Node *node = &mempool[node_ind++];
    node->key = key;
    node->next = NULL;
    node->prev = NULL;
    node->value = val;
    return node;
}

// circular doubly linked list
class Dll{

public:
    Node *head;

    Dll(){
        init();
    }

    void init(){
        node_ind = 0;
        head = getNode(-1); //dummy node
        head->next = head->prev = head;
    }

    void insertAtFront(Node *node){
        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
    }

    void insertAtEnd(Node *node){
        // cout << "insertAtEnd" << endl;
        head->prev->next = node;
        node->prev = head->prev;
        node->next = head;
        head->prev = node;

    }

    // Node* removeLast(){
    Node *remove(Node *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        return node;
    }


    void printList(){
        Node *cur = head->next;
        while(cur!=head){
            cout << cur->key << " --- " << cur->value << ", ";
            cur = cur->next;
        }
        cout << endl;
    }
};


class LRUCache{

    Dll dll;
    int capacity; int cur_size = 0;
    unordered_map <int, Node*> mp;


public:
    LRUCache(int cap){
        // Write your code here
        cur_size = 0;
        capacity = cap;
        node_ind = 0;
        dll.init();
        mp.clear();
    }

    int get(int key){
        if (mp.find(key) != mp.end()){ //key exists
            dll.remove(mp[key]);
            dll.insertAtFront(mp[key]);           
            return mp[key]->value;
        }
        //key doesnt exist
        return -1;
    }

    void put(int key, int value){
        if (mp.find(key) != mp.end()){ //key exists
            mp[key]->value = value;
            dll.remove(mp[key]);
            dll.insertAtFront(mp[key]);
        }else{

            Node *node = getNode(key, value);
            mp[key] = node;
            if (cur_size < capacity){
                cur_size++;
            }else{
                //remove last element in the list to make space
                Node *temp = dll.remove(dll.head->prev);
                mp.erase(temp->key);
            }

            dll.insertAtFront(node);
        }       
    }

};