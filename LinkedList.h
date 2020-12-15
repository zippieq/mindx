/*
* Array.h
*
*  Created on: Dec 15, 2020
*      Author: Administrator
*/

 


#ifndef ARRAY_H
#define ARRAY_H

 

 

template<class T, int cap>
class Array {
public:
    Array();
    ~Array();
    int size();
    int capacity();
    bool isEmpty();
    T itemAt(int index);
    void append(T item);
    void insert(T item, int index);
    void pop();
    void removeAt(int index);

 

 

private:
    int m_size;
    int m_capacity;
    T* m_data;
private:
    void checkResize();
    void checkShrink();
    void checkIndex(int index);
};
template<class T, int cap>
Array<T, cap>::Array() {
    m_capacity = cap;
    m_data = new T[m_capacity];
    m_size = 0;
}

 

 

template<class T, int cap>
Array<T, cap>::~Array() {
    delete m_data;
    m_data = nullptr;
}

 

 

template<class T, int cap>
int Array<T, cap>::size() {
    return m_size;
}

 

 

template<class T, int cap>
int Array<T, cap>::capacity() {
    return m_capacity;
}

 

 

template<class T, int cap>
bool Array<T, cap>::isEmpty() {
    return m_size == 0;
}

 

 

template<class T, int cap>
T Array<T, cap>::itemAt(int index) {
    checkIndex(index);
    return m_data[index];
}

 

 

template<class T, int cap>
void Array<T, cap>::append(T item) {
    checkResize();
    m_data[m_size++] = item;
}

 

 

template<class T, int cap>
void Array<T, cap>::insert(T item, int index) {
    checkIndex(index);
    checkResize();
    for (int i = index; i < m_size; i++)
    {
        m_data[i + 1] == m_data[i];
    }
    m_data[index] = item;
    m_size++;
}

 

 

template<class T, int cap>
void Array<T, cap>::pop() {
    if (m_size <= 0)
        return;
    m_size--;
    checkShrink();
}

 

template<class T, int cap>
void Array<T, cap>::removeAt(int index) {
    checkIndex(index);
    for (int i= index; i < m_size - 1; i++)
        m_data[i] = m_data[i + 1];
    m_size--;
    checkShrink();
}

 

template<class T, int cap>
void Array<T, cap>::checkResize() {
    if (m_size == m_capacity) {
        // create bigger array and copy data over
        T* copy = new T[2 * m_capacity]();
        for (int i = 0; i < m_capacity; i++) {
            copy[i] = m_data[i];
        }
        delete[] m_data;
        m_data = copy;
        m_capacity *= 2;
    }
}

 

template<class T, int cap>
void Array<T, cap>::checkShrink() {
    if (m_size == m_capacity/4 && m_size >0) {
        // create smaller array and copy data over
        T* copy = new T[m_capacity/2]();
        for (int i = 0; i < m_size; i++) {
            copy[i] = m_data[i];
        }
        delete[] m_data;
        m_data = copy;
        m_capacity /= 2;
    }
}

 

template<class T, int cap>
void Array<T, cap>::checkIndex(int index) {
    if (index<0||index>=m_size)
    {
        std::out_of_range oor("index is out of range");
        throw oor;
    }
}

 

#endif
