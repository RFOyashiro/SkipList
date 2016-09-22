#ifndef NODE_H
#define NODE_H

#include <vector>

class Node
{
private:
    int m_cell;
    std::vector<Node *> m_sons;

public:
    Node();
    Node(int elem);

    int cell() const;
    void setCell(int cell);
    Node* getSon(unsigned indice) const;
    std::vector<Node *> getSons() const;
    void setSons(const std::vector<Node *> &sons);
    void setSon(int indice, Node* son);

};

#endif // NODE_H
