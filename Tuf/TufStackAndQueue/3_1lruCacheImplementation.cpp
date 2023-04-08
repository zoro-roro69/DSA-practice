#include <bits/stdc++.h>
using namespace std;


// LRU cache implementation using double linked list

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
class LRUCache{


    Node *head;


    Node *getNode(int key, int val = 0){
        Node *node = &mempool[node_ind++];
        node->key = key;
        node->next = NULL;
        node->prev = NULL;
        node->value = val;
        return node;
    }
    //insertin Linked list


    int capacity; int cur_size = 0;

    unordered_map <int, Node*> mp;

    void insertAtFront(Node *node){
        // node->prev->next = node->next;
        // node->next->prev = node->prev;

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

    void removeLast(){
        // cout << "removeLast" << endl;
        Node *last = head->prev;
        mp.erase(last->key);
        last->prev->next = last->next;
        last->next->prev = last->prev;

        //remove from map
        return;
    }

public:
    LRUCache(int cap){
        // Write your code here
        cur_size = 0;
        capacity = cap;
        node_ind = 0;
        head = getNode(-1); //dummy node
        head->prev = head->next = head; //circular
        mp.clear();
    }

    int get(int key){
        if (mp.find(key) != mp.end()){ //key exists
            //remove key fromt current positon and insert it at front
            Node *node = mp[key];
            node->prev->next = node->next;
            node->next->prev = node->prev;
            insertAtFront(node);           
            return node->value;
        }
        //key doesnt exist
        return -1;
    }

    void put(int key, int value){
        if (mp.find(key) != mp.end()){ //key exists
            mp[key]->value = value;
            mp[key]->prev->next = mp[key]->next;
            mp[key]->next->prev = mp[key]->prev;
            insertAtFront(mp[key]);
        }else{
            // cout << "put new elment" << endl;
            Node *node = getNode(key, value);
            mp[key] = node;
            if (cur_size < capacity){
                cur_size++;
            }else{
                removeLast();
                // mp.erase(key);
            }

            insertAtFront(node);
        }       
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



// i misunderstoood the question :)
//  question says "least recently used" and not "least number of times used"
//the below approach using heap is for "least number of times used"
// const int MAX_SIZE = 100001;
// struct Node{
//     int value;
//     int heap_ind;
//     int count;

//     Node(int val = 0, int ind = 0, int cnt = 0){
//         value = val;
//         heap_ind = ind;
//         count = cnt;
//     }
// };

// class LRUCache{

//     int heap[MAX_SIZE];
//     int h_size = 0;
//     int capacity = 0;

//     unordered_map <int, Node> map;

// public:

//     LRUCache(int cap){
//         // Write your code here
//         map.clear();
//         h_size = 0;
//         capacity = cap;
//     }

//     void insertInHeap(int key){
//         if (h_size < capacity){
//             //insert
//         }else{
//             //delete top
//         }
//     }

//     int get(int key){
//         // Write your code here
//         if (map.find(key) != map.end())
//             return map[key].value;

//         return -1;
//     }

//     void put(int key, int value){
//         // Write your code here
//         if (map.find(key) == map.end()){
//             //insert key in map and then in heap
//             map[key] = {value, h_size, 0};
//             insertInHeap(key);
//         }else{
//             //update in map and then in heap
            
//         }
//     }
// };

int main(){

    LRUCache lru(2);

    lru.put(2,1);
    lru.put(1,1);
    lru.put(2,3);
    lru.printList();

    lru.put(4,1);

    lru.printList();

    cout << lru.get(1) << endl;
    cout << lru.get(2) << endl;

    return 0;
}