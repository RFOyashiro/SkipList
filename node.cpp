#include "node.h"

int Node::cell() const
{
    return m_cell;
}

void Node::setCell(int cell)
{
    m_cell = cell;
}

std::vector<Node *> Node::getSons() const
{
    return m_sons;
}

void Node::setSons(const std::vector<Node *> &sons)
{
    m_sons = sons;
}

Node::Node()
{

}

