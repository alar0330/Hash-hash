#include <cstddef>
#include "HashNode.hpp"
#include "HashFun.hpp"

// Simple hash table implementation
// For better performance, always provide the case-specific hash function

template < typename K, typename V,
           size_t tabSize, typename F = HashFun<K, tabSize> >
class HashTable {
   
public:

    HashTable() :
        _table(),
        _hashFunc()
    { }

    ~HashTable() {

        for (size_t i = 0; i < tabSize; i++) {
            
            HashNode<K, V>* entry = _table[i];

            while (entry != nullptr) {
                HashNode<K, V>* prev = entry;
                entry = entry->getNext();
                delete prev; // remove all nodes
            }

            _table[i] = nullptr; // remove bucket root
        }
    }

    V get(const K& key, const V& defValue) {
       
        unsigned long hashValue = _hashFunc(key);
        HashNode<K, V>* entry = _table[hashValue];
        V value;

        while (entry != nullptr) {
            if (entry->getKey() == key) {
                value = entry->getValue();
                return value;
            }

            entry = entry->getNext();
        }

        return defValue;
    }

    void put(const K& key, const V& value) {
        
        unsigned long hashValue = _hashFunc(key);
        HashNode<K, V>* prev = nullptr;
        HashNode<K, V>* entry = _table[hashValue];

        while (entry != nullptr && entry->getKey() != key) {
           
            prev = entry;
            entry = entry->getNext();

        }

        if (entry == nullptr) {
           
            entry = new HashNode<K, V>(key, value);

            if (prev == nullptr)
                _table[hashValue] = entry; // new bucket
            else
                prev->setNext(entry); // add at the end of existing bucket
            
        } else {
            
            entry->setValue(value); // update value of existing node
            
        }
    }

    void remove(const K& key) {
        
        unsigned long hashValue = _hashFunc(key);
        HashNode<K, V>* prev = nullptr;
        HashNode<K, V>* entry = _table[hashValue];

        while (entry != nullptr && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == nullptr) {

            return; // key not found

        } else {
            if (prev == nullptr)                
                _table[hashValue] = entry->getNext(); // remove bucket root
            else
                prev->setNext(entry->getNext()); // remove node and reconnect

            delete entry;
        }
    }

private:

    HashTable(const HashTable & other) = delete;
    const HashTable& operator=(const HashTable & other) = delete;

    HashNode<K, V>* _table[tabSize]; // array for hash buckets
    F _hashFunc;  // functor to generate hashkeys
    
};
