#ifndef SKIPLIST_H
#define SKIPLIST_H

#include "node.cpp"

template<class K, class V, int MAXLEVEL = 16>
class SkipList
{
private:
    K m_min_key;
    K m_max_key;
    int max_current_height;
    Node<K, V, MAXLEVEL> *m_head = NULL;
    Node<K, V, MAXLEVEL> *m_tail = NULL;
    const int max_height;
    int randomLevel();

public:
    typedef K KeyType;
    typedef V ValueType;
    typedef Node<K, V, MAXLEVEL> NODE;

    SkipList(K minKey, K maxKey);
    virtual ~SkipList();

    void insert(K searchedKey, V newValue);
    void remove(K searchedKey);
    const NODE *search(K searchedKey);
    bool isEmpty() const;
    void displayList();
};

#endif // SKIPLIST_H
