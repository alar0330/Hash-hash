/**
 *  @file    HashFun.hpp
 *  @author  Alexander Arzhanov
 *  @version 29/12/17
 *
 ***********
 *  @brief    Contains template with default hash functor.
 ***********
**/

#pragma once

/**
 ***********
 *  @brief    Default hash functor.
 ***********
 *
 *  Implementation of the default hash functor.
 *  Will be used if no custom hash functor is provided.
 *
 *  @tparam K Type of the Key.
 *  @tparam tabSize Size of the HashTable to be used with.
 *
**/
template <typename K, size_t tabSize>
struct HashFun {
    unsigned long operator()(const K& key) const {
        return reinterpret_cast<unsigned long>(key) % tabSize;
    }
};