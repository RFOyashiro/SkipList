#include "node.h"
#include "time.h"
#include "stdlib.h"

/*
Node::Node()
{
    m_pointers = std::vector<Node*>(1);
}

Node::Node(int max, int key = NULL)
{
    m_key = key;
    m_pointers = std::vector<Node*>(buildTower(max));
}

int Node::key() const
{
    return m_key;
}

void Node::setKey(int key)
{
    m_key = key;
}

Node *Node::getPointer(int i) const
{
    int size = getPointers().size();
    if (i >= 0 && i < size)
        return m_pointers.at(i);
    return NULL;
}

std::vector<Node *> Node::getPointers() const
{
    return m_pointers;
}

void Node::setPointers(const std::vector<Node *> &pointers)
{
    m_pointers = pointers;
}

std::vector<Node *> Node::buildTower(int max)
{
    int sizeOfTower = 0;
    for (int i = 1; i <= max; ++i)
    {
        if (rand() % 1 == 0) break;
        ++sizeOfTower;
    }
    std::vector<Node *> Vtower (sizeOfTower);
    return Vtower;
}
*/
template<class K, class V, int MAXLEVEL>
Node<K, V, MAXLEVEL>::Node()
{
    for (int i = 1; i < MAXLEVEL; ++i)
        forwards[i] = NULL;
}

template<class K, class V, int MAXLEVEL>
Node<K, V, MAXLEVEL>::Node(K searchedKey) :
    key(searchedKey)
{
    Node();
}

template<class K, class V, int MAXLEVEL>
Node<K, V, MAXLEVEL>::Node(K searchedKey, V value) :
    key(searchedKey),
    value(value)
{
    Node();
}

