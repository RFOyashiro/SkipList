#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>

template<class K, class V, int MAXLEVEL>
class Node
{
private:

    /*
    int m_key;
    std::vector<Node *> m_pointers;
    std::vector<Node *> buildTower(int max);*/

public:
    K key;
    V value;
    Node<K, V, MAXLEVEL> *forwards[MAXLEVEL+1];

    Node();
    Node(K searchedKey);
    Node(K searchedKey, V value);
    /*
    Node();
    Node(int max, int key);

    int key() const;
    void setKey(int key);
    Node* getPointer(int i) const;
    std::vector<Node *> getPointers() const;
    void setPointers(const std::vector<Node *> &pointers);*/
};

#endif // NODE_H
