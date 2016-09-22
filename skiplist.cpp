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

/************************************/
//Modifier les noms de fonctions

//renvois nullptr si value déjà dans skiplist
//renvois le node qui est juste avant l'insertion
Node* SearchVal (int Value)
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

vector <Node*> SearchPtr (int Value)
{
	Node* Actuel = m_Head.GetSon(0);
	vector <Node*> Ptrs;
	int Indice = Actuel.GetSons().size();
	Ptrs.push_back(Actuel.GetSon(Indice));
	while (indice != -1 || Actuel.GetSon(Indice) != Value)
	{
		if (Actuel.GetSon(Indice) > Value) 
		{
			Indice--;
			Ptrs.push_back(Actuel.GetSon(Indice));
		}
		if (Actuel.GetSon(Indice) < Value)
		{
			Acutel = Actuel.GetSon(Indice);
			Ptrs.push_back(Actuel.GetSon(Indice));
		}
	}
	return Ptrs;
}

/*******************************************/

void SkipList::insert(int value)
{
    //Le premier noeud dont la valeur est inférieure à celle du nouveau
    Node * nodeBeforeInsert = contains(value);

    //Si la valeur à insérer n'est pas déjà présente dans la liste
    if (nodeBeforeInsert != 0)
    {
        //Création du noeud à insérer
        Node * nodeToInsert = new Node();

        //Attribution de la valeur donnée au noeud que l'on insère
        nodeToInsert->setCell(value);

        //On lie le pointeur du noeud suivant à celui que l'on insère
        nodeToInsert->getSons().push_back(nodeBeforeInsert->getSon(0));

        //On lie le pointeur du noeud précédent à celui que l'on insère
        nodeBeforeInsert->getSons().at(0) = nodeToInsert;


        for (int i = 0; i < nodeBeforeInsert->getSons().size(); ++i)
        {

        }
    }
}

void SkipList::remove(int value)
{

}

