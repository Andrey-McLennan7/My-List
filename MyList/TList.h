#pragma once

template<typename T>
struct TNode
{
    T data;
    TNode* next;
};

template<typename T>
class TList {
private:
    TNode<T>* head;
    TNode<T>* tail;
public:
    TList();
    ~TList();

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
inline TList<T>::TList() : head(nullptr), tail(nullptr) {}

template<typename T>
inline TList<T>::~TList()
{
    this->Clear();
}

template<typename T>
inline void TList<T>::Add(T val)
{
    TNode<T>* node = new TNode<T>;

    node->data = val;
    node->next = nullptr;

    if (this->head == nullptr)
        this->head = node;
    else
        this->tail->next = node;

    this->tail = node;
}

template<typename T>
inline void TList<T>::AddToHead(T val)
{
    TNode<T>* node = new TNode<T>;

    node->data = val;
    node->next = this->head;

    if (this->tail == nullptr)
        this->tail = node;

    this->head = node;
}

template<typename T>
inline void TList<T>::Insert(int index, T val)
{
    TNode<T>* ptr = this->head;
    TNode<T>* prev = nullptr;

    int i = 0;
    while (i != index && ptr != nullptr)
    {
        prev = ptr;
        ptr = ptr->next;
        i++;
    }

    if (ptr == nullptr)
        this->Add(val);
    else
        if (ptr == this->head)
            this->AddToHead(val);
    else
    {
        TNode<T>* node = new TNode<T>;

        node->data = val;

        node->next = ptr;
        prev->next = node;
    }
}

template<typename T>
inline void TList<T>::Delete(int index)
{
    TNode<T>* node = this->head;
    TNode<T>* prev = nullptr;

    int i = 0;
    while (i != index && node != nullptr)
    {
        prev = node;
        node = node->next;
        i++;
    }

    if (node == nullptr)
        throw("Out of range");

    if (node == this->head)
    {
        this->head = this->head->next;

        if (this->head == nullptr)
            this->tail = nullptr;
    }
    else if (node == this->tail)
    {
        this->tail = prev;

        if (this->tail == nullptr)
            this->head = nullptr;
        else
            this->tail->next = nullptr;
    }
    else
        prev->next = node->next;

    delete node;
}

template<typename T>
inline void TList<T>::Clear()
{
    while (this->head != nullptr)
    {
        TNode<T>* node = this->head;
        this->head = this->head->next;
        delete node;
    }

    this->tail = nullptr;
}

template<typename T>
inline int TList<T>::size()
{
    TNode<T>* node = this->head;

    int i = 0;
    while (node != nullptr)
    {
        node = node->next;
        i++;
    }

    return i;
}

template<typename T>
inline void TList<T>::SetAt(int index, T val)
{
    TNode<T>* node = this->head;

    int i = 0;
    while (i != index && node != nullptr)
    {
        node = node->next;
        i++;
    }

    if (node == nullptr)
        throw("Out of range");

    node->data = val;
}

template<typename T>
inline T TList<T>::GetAt(int index)
{
    TNode<T>* node = this->head;

    int i = 0;
    while (i != index && node != nullptr)
    {
        node = node->next;
        i++;
    }

    if (node == nullptr)
        throw("Out of range");

    return node->data;
}

template<typename T>
inline bool TList<T>::isEmpty()
{
    if (this->head == nullptr)
        return true;
    return false;
}

template<typename T>
inline void TList<T>::pushBack(T val)
{
    this->Add(val);
}

template<typename T>
inline void TList<T>::pushFront(T val)
{
    this->AddToHead(val);
}

template<typename T>
inline T TList<T>::popBack()
{
    if (this->tail == nullptr)
        throw("Stack is Empty");

    T result = this->tail->data;

    TNode<T>* node = this->head;
    TNode<T>* prev = nullptr;

    while (node != this->tail)
    {
        prev = node;
        node = node->next;
    }

    this->tail = prev;

    delete node;

    if (this->tail == nullptr)
        this->head = nullptr;
    else
        this->tail->next = nullptr;

    return result;
}

template<typename T>
inline T TList<T>::popFront()
{
    if (this->head == nullptr)
        throw("Stack is empty");

    T result = this->head->data;

    this->Delete(0);

    return result;
}