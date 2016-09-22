#include "node.h"

Node::Node (int elem) : 
	m_cell (elem) {}

int Node::cell() const
{
	return m_cell;
}

std::vector<Node *> Node::getSons() const
{
	return m_sons;
}

Node* Node::getSon(unsigned indice) const
{
	if (indice >= m_sons.size()) return 0;
	return m_sons[indice];
}

void Node::setSons(const std::vector<Node *> &sons)
{
	m_sons = sons;
}

void Node::setSon(int indice, Node* son)
{
	m_sons[indice] = son;
}

void Node::setCell(int cell)
{
	m_cell = cell;
}
