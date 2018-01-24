/**
 *  @file    HashTable.hpp
 *  @author  Alexander Arzhanov
 *  @version 29/12/17
 *
 ***********
 *  @brief   Contains templates for HashTable
 ***********
**/


#include <cstddef>
#include "HashNode.hpp"
#include "HashFun.hpp"



/**
 ***********
 *  @brief   Simple hash table implementation
 ***********
 *
 *  @warning For better performance, always provide the case-specific hash functor.
 *
 *  @tparam K Type of the @c Key.
 *  @tparam V Type of the @c Value.
 *  @tparam tabSize The size of the HashTable.
 *  @tparam F The custom hashing functor (default is @c HashFun).
 *
**/
template < typename K, typename V,
           size_t tabSize, typename F = HashFun<K, tabSize> >
class HashTable {
   
public:

    /// @name Contructors/Destructors
    /// @{
    
    /// The only constructor for HashNode
    HashTable() :
        _table(),
        _hashFunc()
    { }

    /// The destructor
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

    // end of group: Contructors/Destructors
    /// @}
        
    /**
    * @brief Gets the @c value for provided @c key.
    *
    * If Key is not found in the HashTable, 
    * the default value will be returned (@c defValue).
    *
    * @param key The searched key.
    * @param defValue The default value (if key not found).
    *
    * @return Either the found Value for the Key, or the default value.
    */
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

    /**
    * @brief Adds the Key-Value pair to the HashTable.
    *
    * If bucket already exists, it adds a node to the
    * end of the bucket chain.
    *
    * @param key The Key to add.
    * @param defValue The Value to add.
    *
    */
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

    /**
    * @brief Removes an entry from the HashTable.
    *
    * If Key is not found, it does nothing.
    *
    * @param key The Key to remove.
    *
    */
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
