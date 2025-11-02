template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    // TO DO:
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

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    // TO DO: 
    for (int i = 0; i < this->M; ++i) {
        int index = probeIndex(key, i);
        if (this->occupied[index] && this->table[index] == key) {
            return {true, index};
        }
    }
    return {false, -1};
}
