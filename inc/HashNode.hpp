/**
 *
 *  @author  Alexander Arzhanov
 *  @version 29/12/17
 *
 *  @brief   Singly linked list
 *  <!      ´´´´´´´´´´´´´´´´´´´   >
 *
 *  Classic singly linked list with storage for key and value.
 *
**/

#pragma once

template<typename K, typename V>
class HashNode {
   
public:
    HashNode(const K& key, const V& value) :
        _key(key), 
        _value(value), 
        _next(nullptr)
    { }

    K getKey() const {
        return _key;
    }

    V getValue() const {
        return _value;
    }

    void setValue(V value) {
        _value = value;
    }

    HashNode* getNext() const {
        return _next;
    }

    void setNext(HashNode* next) {
        _next = next;
    }

private:

    // key-value pair
    K _key;
    V _value;
    
    // next bucket with the same key
    HashNode* _next;
    
    // delete copy and assignment ops.
    HashNode(const HashNode &) = delete;
    HashNode & operator=(const HashNode &) = delete;
};