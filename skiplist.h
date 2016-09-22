#ifndef SKIPLIST_H
#define SKIPLIST_H

#include "node.h"

class SkipList
{
private:
    std::vector<Node *> m_nodes;
    Node m_head;

public:
    SkipList();
    Node *contains(int value) const;
    void insert(int value);
    void remove(int value);
    std::vector<Node *> nodes() const;
    void setNodes(const std::vector<Node *> &nodes);
    Node *SearchVal(int Value);
    std::vector<Node *> SearchPtr(int Value);
};

#endif // SKIPLIST_H
