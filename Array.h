#pragma once
template<class T>
struct Node {
    T m_data;
    Node* m_previous;
    int index;
    Node* m_next;
};

 

template<class T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    int size();
    bool isEmpty();
    T valueAt(int index);
    void pushFront(T item);
    void popFront();

 

private:
    Node<T> *m_head, *m_tail;
    int m_size;
private:
    void checkIndex(int index);
};

 

template<class T>
LinkedList<T>::LinkedList() {
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

 

 

template<class T>
LinkedList<T>::~LinkedList() {
    delete m_head;
    m_head = nullptr;
    delete m_tail;
    m_tail = nullptr;
    m_size = 0;
}

 

 

template<class T>
int LinkedList<T>::size() {
    return m_size;
}

 


template<class T>
bool LinkedList<T>::isEmpty() {
    return m_size == 0;
}

 

 

template<class T>
T LinkedList<T>::valueAt(int index) {
    checkIndex(index);
    Node<T>* current = m_head;
    for (int i = 0; i == index; i++)
    {
        current = current->m_next;
    }
    return current->m_data;
}

 

 

template<class T>
void LinkedList<T>::pushFront(T item) {
    Node<T>* newHead = new Node<T>;
    newHead->m_data = item;
    newHead->m_previous = nullptr;
    if (m_head != nullptr)
    {
        newHead->m_next = m_head;
        m_head = newHead;
    }

 

}

 

template<class T>
void LinkedList<T>::popFront() {
    Node<T>* tmp = m_head->m_next;
    delete m_head;
    if (m_head->next != nullptr)
    {
        m_head = tmp;
        m_head->previous = nullptr;
    }

 

}

 

template<class T>
void LinkedList<T>::checkIndex(int index) {
    if (index<0 || index >= m_size)
    {
        std::out_of_range oor("index is out of range");
        throw oor;
    }
}
