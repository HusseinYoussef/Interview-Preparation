#include <iostream>

using namespace std;

class MyHashSet {
public:
    bool arr[1000006];
    MyHashSet() {
        memset(arr, 0, sizeof(arr));
    }
    
    void add(int key) {
        arr[key] = 1;
    }
    
    void remove(int key) {
        arr[key] = 0;
    }
    
    bool contains(int key) {
        return arr[key];
    }
};
