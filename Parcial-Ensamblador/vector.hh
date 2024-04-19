#ifndef VECTOR_HH
#define VECTOR_HH

#include <iostream>
using namespace std;

template<typename T>
class vector{
private:
    unsigned int sz;
    unsigned int cap;
    T *storage;

public:
    vector(): sz(0), cap(14), storage(new T[cap]) {}

    T& at(unsigned int pos) {
        return storage[pos];
    }

    void push_back(const T& valor) {
        if (sz == cap) {
            resize(cap * 1.5);
        }
        storage[sz] = valor;
        sz++;
    }

    void resize(unsigned int new_capacity) {
        T *new_storage = new T[new_capacity];
        for (unsigned int i = 0; i < sz; ++i) {
            new_storage[i] = storage[i];
        }
        delete[] storage;
        storage = new_storage;
        cap = new_capacity;
    }

    unsigned int size() const {
        return sz;
    }

    unsigned int capacity() const {
        return cap;
    }

    T* begin() const {
        return storage;
    }

    T* end() const {
        return storage + sz;
    }
};

#endif
