#include <iostream>
#include <string>
#include <assert.h>
#include "../inc/HashTable.hpp"

using namespace std;

struct MyHashFun {
    unsigned long operator()(const int& k) const {
        return k % 10;
    }
};

int main() {
    
    HashTable<int, string, 10, MyHashFun> hmap;
    hmap.put(1, "1");
    hmap.put(2, "2");
    hmap.put(3, "3");
    
    cout << "Test started." << endl;

    auto value = hmap.get(2, "NF");
    assert(value == "2");

    value = hmap.get(3, "NF");
    assert(value == "3");
    
    value = hmap.get(4, "NF");
    assert(value == "NF");

    hmap.remove(3);
    value = hmap.get(3, "NF");
    assert(value == "NF");
    
    cout << "Test finished." << endl;
    
}