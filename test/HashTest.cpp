/**
 *  @file    HashTest.cpp
 *  @author  Alexander Arzhanov
 *  @version 29/12/17
 *
 ********************************
 *  @brief   A lazy unit test
 ********************************
 *
 *  Automated unit testing with 4 test cases.
 *
**/


#include <iostream>
#include <string>
#include <assert.h>
#include "../inc/HashTable.hpp"

using namespace std;

/**
 ***********
 *  @brief    Custom Hashing Functor for the Test Suite.
 ***********
**/
struct MyHashFun {
    unsigned long operator()(const int& k) const {
        return k % 10;
    }
};

int main() {
    
    unsigned t = 1;
    const char OK[] = ": OK\n";
    const char FAILED[] = ": FAILED\n";
    
    HashTable<int, string, 10, MyHashFun> hmap;
    hmap.put(1, "1");
    hmap.put(2, "2");
    hmap.put(3, "3");
    
    cout << "Test suite started." << endl;

    auto value = hmap.get(2, "NF");
    cout << "Test #" << t++ << (value == "2" ? OK : FAILED);

    value = hmap.get(3, "NF");
    cout << "Test #" << t++ << (value == "3" ? OK : FAILED);
    
    value = hmap.get(4, "NF");
    cout << "Test #" << t++ << (value == "NF" ? OK : FAILED);

    hmap.remove(3);
    value = hmap.get(3, "NF");
    cout << "Test #" << t++ << (value == "NF" ? OK : FAILED);
    
    cout << "Test suite finished." << endl;
    
}