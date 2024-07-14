#pragma once

template<typename T>
struct TDNode
{
    T data;
    TDNode<T>* next;
    TDNode<T>* prev;
};

template<typename T>
class TDList {
private:
    TDNode<T>* head;
    TDNode<T>* tail;

    TDNode<T>* SearchIndex(int &index)
    {
        TDNode<T>* ptr = this->head;

        int i = 0;
        while (i != index && ptr != nullptr)
        {
            ptr = ptr->next;
            i++;
        }

        return ptr;
    }

public:
    TDList();
    ~TDList();

    void Add(T);
    void AddToHead(T);
    void Insert(int, T);
    void Delete(int);
    void Clear();

    int size();
    void SetAt(int, T);
    T GetAt(int);

    bool isEmpty();

    void pushBack(T);
    void pushFront(T);
    T popBack();
    T popFront();
};

template<typename T>
inline TDList<T>::TDList() : head(nullptr), tail(nullptr) {}

template<typename T>
inline TDList<T>::~TDList()
{
    this->Clear();
}

template<typename T>
inline void TDList<T>::Add(T val)
{
    TDNode<T>* node = new TDNode<T>;

    node->data = val;
    node->next = nullptr;
    node->prev = this->tail;

    if (this->head == nullptr)
        this->head = node;
    else
        this->tail->next = node;

    this->tail = node;
}

template<typename T>
inline void TDList<T>::AddToHead(T val)
{
    TDNode<T>* node = new TDNode<T>;

    node->data = val;
    node->next = this->head;
    node->prev = nullptr;

    if (this->tail == nullptr)
        this->tail = node;
    else
        this->head->prev = node;

    this->head = node;
}

template<typename T>
inline void TDList<T>::Insert(int index, T val)
{
    TDNode<T>* ptr = SearchIndex(index);

    if (ptr == nullptr)
        this->Add(val);
    else
        if (ptr == this->head)
            this->AddToHead(val);
    else
    {
        TDNode<T>* node = new TDNode<T>;

        node->data = val;

        node->prev = ptr->prev;
        node->next = ptr->prev->next;

        ptr->prev->next = node;
        ptr->prev = node;
    }
}

template<typename T>
inline void TDList<T>::Delete(int index)
{
    TDNode<T>* node = SearchIndex(index);

    if (node == nullptr)
        throw("Out of range");

    if (node == this->head)
    {
        this->head = this->head->next;

        if (this->head == nullptr)
            this->tail = nullptr;
        else
            this->head->prev = nullptr;
    }
    else if (node == this->tail)
    {
        this->tail = this->tail->prev;

        if (this->tail == nullptr)
            this->head = nullptr;
        else
            this->tail->next = nullptr;
    }
    else
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    delete node;
}

template<typename T>
inline void TDList<T>::Clear()
{
    while (this->head != nullptr)
    {
        TDNode<T>* node = this->head;
        this->head = this->head->next;
        delete node;
    }

    this->tail = nullptr;
}

template<typename T>
inline int TDList<T>::size()
{
    TDNode<T>* node = this->head;

    int i = 0;
    while (node != nullptr)
    {
        node = node->next;
        i++;
    }

    return i;
}

template<typename T>
inline void TDList<T>::SetAt(int index, T val)
{
    TDNode<T>* node = SearchIndex(index);

    if (node == nullptr)
        throw("Out of range");

    node->data = val;
}

template<typename T>
inline T TDList<T>::GetAt(int index)
{
    TDNode<T>* node = SearchIndex(index);

    if (node == nullptr)
        throw("Out of range");

    return node->data;
}

template<typename T>
inline bool TDList<T>::isEmpty()
{
    if (this->head == nullptr)
        return true;
    return false;
}

template<typename T>
inline void TDList<T>::pushBack(T val)
{
    this->Add(val);
}

template<typename T>
inline void TDList<T>::pushFront(T val)
{
    this->AddToHead(val);
}

template<typename T>
inline T TDList<T>::popBack()
{
    if (this->tail == nullptr)
        throw("Stack is Empty");

    T result = this->tail->data;

    TDNode<T>* node = this->tail;

    this->tail = this->tail->prev;

    delete node;

    if (this->tail == nullptr)
        this->head = nullptr;
    else
        this->tail->next = nullptr;

    return result;
}

template<typename T>
inline T TDList<T>::popFront()
{
    if (this->head == nullptr)
        throw("Stack is Empty");

    T result = this->head->data;

    this->Delete(0);

    return result;
}