#pragma once

template <typename K, size_t tabSize>
struct HashFun {
    unsigned long operator()(const K& key) const {
        return reinterpret_cast<unsigned long>(key) % tabSize;
    }
};