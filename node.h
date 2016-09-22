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

    int cell() const;
    void setCell(int cell);
    Node* getSon(int i) const;
    std::vector<Node *> getSons() const;
    void setSons(const std::vector<Node *> &sons);
};

#endif // NODE_H
