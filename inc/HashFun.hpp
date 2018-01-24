/**
 *
 *  @author  Alexander Arzhanov
 *  @version 29/12/17
 *
 *  @brief   Default hash function
 *  <!      ´´´´´´´´´´´´´´´´´´´´´´   >
 *
 *  Implementation of the default hash function.
 *  Will be used if no custom hash function is provided.
 *
**/

#pragma once

template <typename K, size_t tabSize>
struct HashFun {
    unsigned long operator()(const K& key) const {
        return reinterpret_cast<unsigned long>(key) % tabSize;
    }
};