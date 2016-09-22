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

//renvois nullptr si value déjà dans skiplist
		//renvois le node qui est juste avant l'insertion
Node* Search (int Value)
{
	Node* Actuel = m_Head.GetSon(0);
	int Indice = Actuel.GetSons().size();
	while (indice != -1 || Actuel.GetSon(Indice) != Value)
	{
		if (Actuel.GetSon(Indice) > Value) Indice--;
		if (Actuel.GetSon(Indice) < Value) Acutel = Actuel.GetSon(Indice);
	}
	if (Actuel.GetSon(Indice) == Value) return nullptr;
	else return Actuel;			
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

