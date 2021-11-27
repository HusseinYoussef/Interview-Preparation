#include <iostream>
#include <vector>

using namespace std;

class MyHashMap {
public:
    int arr[1000005];
    MyHashMap() {
        for (int i = 0; i < 1000005;++i)
            arr[i] = -1;
    }
    
    void put(int key, int value) {
        arr[key] = value;
    }
    
    int get(int key) {
        return arr[key];
    }
    
    void remove(int key) {
        arr[key] = -1;
    }
};
