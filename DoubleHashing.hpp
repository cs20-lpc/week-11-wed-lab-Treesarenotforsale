#pragma once
#include "HashTableClosed.hpp"

template <typename T>
class DoubleHashing : public HashTableClosed<T> {
public:
    DoubleHashing(int size = 101)
        : HashTableClosed<T>(size) {}

    int hash2(const T& key) const {
        return 7 - (static_cast<int>(key) % 7);
    }

    int probeIndex(const T& key, int i) const override {
        // TODO: Implement double hashing
        return (this->hash1(key) + i * hash2(key)) % this->M;
    }
    int insert(const T& key) override {
        for (int i = 0; i < this->M; ++i) {
            int index = probeIndex(key, i);
            if (!this->occupied[index]) {
                this->table[index] = key;
                this->occupied[index] = true;
                this->N++;
                return index;
            }
        }
        return -1;  // Table is full
    }
 };
