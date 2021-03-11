#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Set {
   private:
    vector<T> m_elems;

   public:
    Set() = default;
    Set(const vector<T>& elem);
    Set(const Set<T>& s);

    bool is_elem(T);
    void insert(T);
    void erase(T);

    Set common(const Set<T>& s);
    Set sum(const Set<T>& s);
    Set& operator=(const Set<T>& s);
    template<typename F>
    friend ostream& operator<<(ostream& os, const Set<F>& s);

    // oop
    typename vector<T>::iterator find(const T& t);
};

template <typename T>
Set<T>::Set(const vector<T>& elem) {
    this->m_elems = elem;
}
template <typename T>
Set<T>::Set(const Set<T>& s) {
    this->m_elems = s.m_elems;
}
template <typename T>
bool Set<T>::is_elem(T c) {
    for (auto it = this->m_elems.begin(); it != this->m_elems.end(); ++it) {
        if (*it == c)
            return true;
    }
    return false;
}

template <typename T>
void Set<T>::insert(T c) {
    this->m_elems.push_back(c);
}
template <typename T>
void Set<T>::erase(T c) {
    for (auto it = this->m_elems.begin(); it != this->m_elems.end(); ++it) {
        if (*it == c) {
            this->m_elems.erase(it);
            return;
        }
    }
}

template <typename T>
ostream& operator<<(ostream& os, const Set<T>& s) {
    for (auto it = s.m_elems.begin(); it != s.m_elems.end(); ++it) {
        os << *it << ' ';
    }
    return os;
}

template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& s) {
    this->m_elems = s.m_elems;
    return *this;
}
template <typename T>
Set<T> Set<T>::common(const Set<T>& s) {
    Set temp;
    for (auto it = this->m_elems.begin(); it != this->m_elems.end(); ++it) {
        for (auto q = s.m_elems.begin(); q != s.m_elems.end(); q++) {
            if (*it == *q)
                temp.m_elems.push_back(*it);
        }
    }
    return temp;
}
template <typename T>
Set<T> Set<T>::sum(const Set<T>& s) {
    Set temp;
    temp.m_elems = this->m_elems;
    for (auto it = s.m_elems.begin(); it != s.m_elems.end(); ++it) {
        int flag = 1;
        for (auto q = this->m_elems.begin(); q != this->m_elems.end(); ++q) {
            if (*it == *q)
                flag = 0;
        }
        if (flag)
            temp.m_elems.push_back(*it);
    }
    return temp;
}

template <typename T>
typename vector<T>::iterator Set<T>::find(const T& t) {
    for(auto it = this->m_elems.begin(); it != this->m_elems.end(); ++it) {
        if(*it == t)    return it;
    }
    cout << "can not find!" << endl;
    return this->m_elems.end();
}
