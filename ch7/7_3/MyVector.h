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

    void QuickSort(const size_t&, const size_t&);
    mutable bool flag_sort = 0;

    const size_t binary_search(const T&);

    // additional
    void show();

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
        this->data[t] = *(temp.begin() + t);
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
    if (!this->flag_back) {
        return 0;
    }
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
    if (this->size() >= N) {
        cout << "can not insert!" << endl;
        return;
    }
    ++this->flag_back;
    for (size_t loc = this->flag_back; loc != pos; --loc) {
        this->data[loc] = this->data[loc - 1];
    }
    this->data[pos] = temp;
}

template <typename T, size_t N>
const T MyVector<T, N>::erase(const T& pos) {
    if (!this->size()) {
        cout << "can not erase!" << endl;
        throw -1;
    }
    T return_data = this->data[pos];
    for (size_t loc = this->flag_back; loc != pos; --loc) {
        this->data[loc - 1] = this->data[loc];
    }
    this->data[this->flag_back--] = 0;
    return return_data;
}

template <typename T, size_t N>
void MyVector<T, N>::clear() {
    while (this->flag_back) {
        this->data[this->flag_back--] = 0;
    }
    this->data[this->flag_back] = 0;
}

template <typename T, size_t N>
void MyVector<T, N>::QuickSort(const size_t& begin, const size_t& end) {
    if (begin < end) {
        T key = this->data[begin];
        size_t i = begin;
        size_t j = end;

        while (i < j) {
            while ((i < j) && (this->data[j] >= key)) {
                --j;
            }
            this->data[i] = this->data[j];
            while ((i < j) && (this->data[i] <= key)) {
                ++i;
            }
            this->data[j] = this->data[i];
        }
        this->data[i] = key;
        this->QuickSort(begin, i - 1);
        this->QuickSort(i + 1, end);
    } else {
        this->flag_sort = 1;
    }
}

template <typename T, size_t N>
void MyVector<T, N>::show() {
    for (size_t loc = this->flag_front; loc != this->size(); ++loc) {
        cout << this->data[loc] << ' ';
    }
    cout << endl;
}

template <typename T, size_t N>
const size_t MyVector<T, N>::binary_search(const T& temp) {
    if (!this->flag_sort) {
        this->QuickSort(0, this->size() - 1);
    }
    size_t i = 0;
    size_t j = this->flag_back;
    while (i < j) {
        if(this->data[(i+j)/2] == temp) {
            break;
        }
        else if(this->data[(i+j)/2] > temp) {
            j = (i+j)/2;
        }
        else if(this->data[(i+j)/2] < temp) {
            i = (i+j)/2;
        }
    }
    return (i+j)/2;
}
