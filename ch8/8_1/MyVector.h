#include <bits/c++config.h>
#include <cstddef>
#include <iostream>
using namespace std;

template <typename T>
class MyVector {
   public:
    MyVector(){};
    MyVector(const T*, const size_t);
    MyVector(const MyVector&);
    MyVector(MyVector&&);
    ~MyVector();
    T& operator[](size_t);
    size_t size();
    MyVector& operator=(const MyVector&);
    MyVector& operator=(MyVector&&);
    const T& at(const size_t);
    const T& front(const size_t);
    const T& back(const size_t);
    void push_back(const T&);
    const T& pop_back();
    void insert(const size_t);
    void erase(const size_t);
    void clear();
    void show();

   private:
    T* m_arr = nullptr;
    size_t m_begin = 0;
    size_t m_end = 0;
};

template <typename T>
MyVector<T>::MyVector(const T* arr, const size_t size) {
    this->m_arr = new T[size]();
    for (size_t q = 0; q < size; q++) {
        *(this->m_arr + q) = *(arr + q);
    }
    this->m_end = size - 1;
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& rhs) {
    this->m_end = rhs.m_end;
    this->m_begin = rhs.m_begin;
    this->m_arr = new T[this->m_end - this->m_begin + 1];
    for (size_t q = this->m_begin; q <= this->m_end; ++q) {
        *(this->m_arr + q) = *(rhs.m_arr + q);
    }
}

template <typename T>
MyVector<T>::MyVector(MyVector<T>&& rhs) : m_arr(rhs.m_arr) {
    this->m_end = rhs.m_end;
    this->m_begin = rhs.m_begin;
    rhs.m_arr = nullptr;
}

template <typename T>
MyVector<T>::~MyVector<T>() {
    if (this->m_arr != nullptr) {
        delete[] this->m_arr;
    }
}
template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& rhs) {
    if (this != &rhs) {
        if (this->m_arr != nullptr) {
            delete[] this->m_arr;
        }
        this->m_end = rhs.m_end;
        this->m_begin = rhs.m_begin;
        this->m_arr = new T[this->m_end - this->m_begin + 1];
        for (size_t q = this->m_begin; q <= this->m_end; ++q) {
            *(this->m_arr + q) = *(rhs.m_arr + q);
        }
    }
    return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& rhs) {
    if (rhs.m_arr != nullptr) {
        this->m_arr = rhs.m_arr;
        this->m_end = rhs.m_end;
        this->m_begin = rhs.m_begin;
        rhs.m_arr = nullptr;
    }
}

template <typename T>
T& MyVector<T>::operator[](size_t i) {
    return *(this->m_arr + i);
}

template <typename T>
size_t MyVector<T>::size() {
    return this->m_end - this->m_begin + 1;
}

template <typename T>
const T& MyVector<T>::at(const size_t q) {
    try {
        if (q > this->m_end) {
            throw -1;
        }
    } catch (int) {
        cout << "Out of range!" << endl;
    }
    return (*this)[q];
}

template <typename T>
void MyVector<T>::show() {
    for (size_t q = this->m_begin; q <= this->m_end; ++q) {
        cout << *(this->m_arr + q) << endl;
    }
}
