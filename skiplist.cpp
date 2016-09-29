#include "skiplist.h"

SkipList::SkipList()
{
    m_head = Node(0);
    m_nodes.push_back(&m_head);
}

std::vector<Node *> SkipList::nodes() const
{
    return m_nodes;
}

void SkipList::setNodes(const std::vector<Node *> &nodes)
{
    m_nodes = nodes;
}

//renvois nullptr si value déjà dans skiplist
//renvois le node qui est juste avant l'insertion
Node *SkipList::SearchVal (int Value)
{
    Node* Actuel = m_head.getSon(0);
    int Indice = Actuel->getSons().size();
    while (Indice != -1 || Actuel->getSon(Indice)->cell() != Value)
    {
        if (Actuel->getSon(Indice)->cell() > Value) Indice--;
        if (Actuel->getSon(Indice)->cell() < Value) Actuel = Actuel->getSon(Indice);
    }
    if (Actuel->getSon(Indice)->cell() == Value) return 0;
    else return Actuel;
}

std::vector <Node*> SkipList::SearchPtr (int Value)
{
    Node* Actuel = m_head.getSon(0);
    std::vector <Node*> Ptrs;
    int Indice = Actuel->getSons().size();
    Ptrs.push_back(Actuel->getSon(Indice));
    while (Indice != -1 || Actuel->getSon(Indice)->cell() != Value)
    {
        if (Actuel->getSon(Indice)->cell() > Value)
        {
            Indice--;
            Ptrs.push_back(Actuel->getSon(Indice));
        }
        if (Actuel->getSon(Indice)->cell() < Value)
        {
            Actuel = Actuel->getSon(Indice);
            Ptrs.push_back(Actuel->getSon(Indice));
        }
    }
    return Ptrs;
}


void SkipList::insert(int value)
{
    //Le premier noeud dont la valeur est inférieure à celle du nouveau
    Node * nodeBeforeInsert = SearchVal(value);

    std::vector<Node *> ptrVisited = SearchPtr(value);

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
            //GO SKYPE ET DIS MOI CE QUE JE DOIS FAIRE POUR FINIR LE PROJET
        }
    }
}

void SkipList::remove(int value)
{

}

