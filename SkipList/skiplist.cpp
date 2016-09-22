#include "skiplist.h"

std::vector<Node *> SkipList::nodes() const
{
    return m_nodes;
}

void SkipList::setNodes(const std::vector<Node *> &nodes)
{
    m_nodes = nodes;
}

SkipList::SkipList()
{
    m_head = Node();
    m_nodes.push_back(&m_head);
}

Node *SkipList::contains(int value) const
{

}

void SkipList::insert(int value)
{
    Node * valueContained = contains(value);
    if (valueContained == nullptr)
    {

    }
}

void SkipList::remove(int value)
{

}

