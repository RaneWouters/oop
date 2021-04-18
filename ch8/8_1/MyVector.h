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
    const T& at(const size_t&);
    const T& front();
    const T& back();
    void push_back(const T&);
    const T& pop_back();
    void insert(const size_t&, const T&);
    void erase(const T&);
    void clear();
    void show();

   private:
    T* m_arr = nullptr;
    size_t m_begin = 0;
    size_t m_end = 0;
    size_t m_capacity = 0;
};

template <typename T>
MyVector<T>::MyVector(const T* arr, const size_t size) {
    this->m_arr = new T[size]();
    this->m_capacity = size;
    for (size_t q = 0; q < size; q++) {
        *(this->m_arr + q) = *(arr + q);
    }
    this->m_end = size - 1;
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& rhs)
    : m_end(rhs.m_end), m_begin(rhs.m_begin), m_capacity(rhs.m_capacity) {
    this->m_arr = new T[m_capacity];
    for (size_t q = this->m_begin; q <= this->m_end; ++q) {
        *(this->m_arr + q) = *(rhs.m_arr + q);
    }
}

template <typename T>
MyVector<T>::MyVector(MyVector<T>&& rhs)
    : m_end(rhs.m_end),
      m_begin(rhs.m_begin),
      m_arr(rhs.m_arr),
      m_capacity(rhs.m_capacity) {
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
        this->m_capacity = rhs.m_capacity;
        this->m_arr = new T[this->m_capacity];
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
        this->m_capacity = rhs.m_capacity;
        rhs.m_arr = nullptr;
    }
}

template <typename T>
T& MyVector<T>::operator[](size_t i) {
    return *(this->m_arr + i);
}

template <typename T>
size_t MyVector<T>::size() {
    if (this->m_begin == this->m_end) {
        return 0;
    }
    return (this->m_end - this->m_begin + 1);
}

template <typename T>
const T& MyVector<T>::at(const size_t& q) {
    try {
        if (q > this->m_end) {
            throw -1;
        }
        return (*this)[q];
    } catch (int) {
        cout << "Out of range!" << endl;
    }
}

template <typename T>
const T& MyVector<T>::front() {
    return (*this)[this->m_begin];
}

template <typename T>
const T& MyVector<T>::back() {
    return (*this)[this->m_end];
}

template <typename T>
void MyVector<T>::push_back(const T& temp) {
    if (this->m_capacity <= (this->m_end + 1)) {
        this->m_capacity += 10;
        T* target = new T[this->m_capacity]();
        for (int q = this->m_begin; q <= this->m_end; ++q) {
            *(target + q) = *(this->m_arr + q);
        }
        delete[] this->m_arr;
        this->m_arr = target;
    }
    ++this->m_end;
    *(this->m_arr + this->m_end) = temp;
}

template <typename T>
const T& MyVector<T>::pop_back() {
    --this->m_end;
    return (*this)[this->m_end + 1];
}

template <typename T>
void MyVector<T>::insert(const size_t& pos, const T& temp) {
    if (this->m_capacity <= (this->m_end + 1)) {
        this->m_capacity += 10;
        T* target = new T[this->m_capacity]();
        for (int q = this->m_begin; q < pos; ++q) {
            *(target + q) = *(this->m_arr + q);
        }
        *(target + pos) = temp;
        ++this->m_end;
        for (int q = pos + 1; q <= this->m_end; ++q) {
            *(target + q) = *(this->m_arr + q - 1);
        }
        delete[] this->m_arr;
        this->m_arr = target;
    } else {
        for (int q = this->m_end + 1; q >= pos; --q) {
            *(this->m_arr + q) = (*this)[q];
        }
        *(this->m_arr + pos) = temp;
    }
}

template <typename T>
void MyVector<T>::erase(const T& temp) {
    for (int q = this->m_begin; q <= this->m_end; ++q) {
        if ((*this)[q] == temp) {
            for (int i = q; i <= this->m_end; ++i) {
                *(this->m_arr + i) = (*this)[i + 1];
            }
            --this->m_end;
            return;
        }
    }
}

template <typename T>
void MyVector<T>::clear() {
    for (int q = this->m_begin; q <= this->m_end; ++q) {
        *(this->m_arr + q) = 0;
    }
    this->m_end = this->m_begin;
}

template <typename T>
void MyVector<T>::show() {
    if (!this->size()) {
        return;
    }
    for (size_t q = this->m_begin; q <= this->m_end; ++q) {
        cout << *(this->m_arr + q) << ' ';
    }
    cout << endl;
}
