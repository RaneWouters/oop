#include <bits/c++config.h>
#include <cstddef>
#include <initializer_list>
#include <iostream>
using namespace std;

template <typename T, size_t N>
class MyVector {
   public:
    MyVector() = default;
    MyVector(const std::initializer_list<T>&);
    MyVector(const MyVector<T, N>&);
    const MyVector<T, N> operator=(const MyVector<T, N>&);

    const size_t size();
    const T& operator[](const size_t&);
    const T& at(const size_t&);
    const T& front();
    const T& back();

    void push_back(const T&);
    void pop_back();
    void insert(const size_t&, const T&);
    const T erase(const T&);
    void clear();

    void sort();

    const T* binary_search(const T&);

   private:
    T data[N] = {0};
    size_t flag_front = 0;
    size_t flag_back = 0;
};

template <typename T, size_t N>
MyVector<T, N>::MyVector(const std::initializer_list<T>& temp) {
    size_t m = temp.size() < N ? temp.size() : N;
    auto it = temp.begin();
    for (size_t t = 0; t < m; ++t) {
        this->data[t] = *(temp.begin()+t);
    }
    this->flag_back = m - 1;
}

template <typename T, size_t N>
MyVector<T, N>::MyVector(const MyVector<T, N>& temp) {
    size_t m = temp.size();
    for (size_t t = 0; t < m; ++t) {
        this->data[t] = temp.data[t];
    }
    this->flag_back = m - 1;
}

template <typename T, size_t N>
const MyVector<T, N> MyVector<T, N>::operator=(const MyVector<T, N>& temp) {
    size_t m = temp.size();
    this->clear();
    for (size_t t = 0; t < m; ++t) {
        this->data[t] = temp.data[t];
    }
    this->flag_back = temp.flag_back;
    this->flag_front = temp.flag_front;
}

template <typename T, size_t N>
const size_t MyVector<T, N>::size() {
    return (this->flag_back - this->flag_front + 1);
}

template <typename T, size_t N>
const T& MyVector<T, N>::operator[](const size_t& location) {
    return this->data[location];
}

template <typename T, size_t N>
const T& MyVector<T, N>::at(const size_t& location) {
    if (location >= this->size()) {
        throw -1;
    }
    return this->data[location];
}

template <typename T, size_t N>
const T& MyVector<T, N>::front() {
    return this->data[this->flag_front];
}

template <typename T, size_t N>
const T& MyVector<T, N>::back() {
    return this->data[this->flag_back];
}

template <typename T, size_t N>
void MyVector<T, N>::push_back(const T& temp) {
    this->flag_back += 1;
    this->data[this->flag_back] = temp;
}

template <typename T, size_t N>
void MyVector<T, N>::pop_back() {
    this->data[this->flag_back] = 0;
    this->flag_back -= 1;
}

template <typename T, size_t N>
void MyVector<T, N>::insert(const size_t& pos, const T& temp) {
    if(this->size() >= N) {
        cout << "can not insert!" << endl;
        return ;
    }
    ++this->flag_back;
    for(size_t loc = this->flag_back; loc != pos; --loc) {
        this->data[loc] = this->data[loc-1]; 
    }
    this->data[pos] = temp;
}
    
template <typename T, size_t N>
const T MyVector<T,N>::erase(const T& pos) {
    if(!this->size()) {
        cout << "can not erase!" << endl;
        throw -1;
    }
    T return_data = this->data[pos];
    for(size_t loc = this->flag_back; loc != pos; --loc) {
        this->data[loc - 1] = this->data[loc]; 
    }
    this->data[this->flag_back--] = 0;
    return return_data;
}
