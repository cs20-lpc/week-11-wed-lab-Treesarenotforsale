#pragma once
#include "HashTableClosed.hpp"

template <typename T>
class QuadraticProbing : public HashTableClosed<T> {
public:
    explicit QuadraticProbing(int size = 101)
        : HashTableClosed<T>(size) {}

    int probeIndex(const T& key, int i) const override {
        // TODO: Implement quadratic probing
        return (this->hash1(key) + i * i) % this->M;
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
        return -1;
    }

   
};
