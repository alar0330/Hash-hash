/**
 *  @file    HashNode.hpp
 *  @author  Alexander Arzhanov
 *  @version 29/12/17
 *
 ***********
 *  @brief   Template for singly linked list.
 ***********
**/

#pragma once

/**
 ***********
 *  @brief    Classic singly linked list with storage for key and value.
 ***********
 *
 *  A simple template implementation of singly linked lists
 *  to hold a @b key and a @b value
 *
 *  @tparam K Type of the @c Key.
 *  @tparam V Type of the @c Value.
**/
template<typename K, typename V>
class HashNode {
   
public:

    /// @name Contructors
    
    /// The only constructor for HashNode
    HashNode(const K& key, const V& value) :
        _key(key), 
        _value(value), 
        _next(nullptr)
    { }
    
    /// @name Setters/Getters
    /// @{
        
    /// Get the stored key
    K getKey() const {
        return _key;
    }

    /// Get the stored value
    V getValue() const {
        return _value;
    }

    /// Set the value
    void setValue(V value) {
        _value = value;
    }

    /// Get pointer to the next node
    HashNode* getNext() const {
        return _next;
    }

    /// Set pointer to the next node
    void setNext(HashNode* next) {
        _next = next;
    }
    
    // end of group: Setters/Getters
    /// @}

private:

    K _key;          ///< the Key    
    V _value;        ///< the Value
    HashNode* _next; ///< pointer to the next node (same bucket)
    
    // delete copy and assignment ops
    HashNode(const HashNode &) = delete;
    HashNode & operator=(const HashNode &) = delete;
};