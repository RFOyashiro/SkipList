#include "skiplist.h"
#include "math.h"
#include "time.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

template<class K, class V, int MAXLEVEL>
int SkipList<K, V, MAXLEVEL>::randomLevel()
{
    int height = 1;
    while (rand() % 1 == 0 && height < MAXLEVEL) {
        height++;
    }
    return height;
}

template<class K, class V, int MAXLEVEL>
SkipList<K, V, MAXLEVEL>::SkipList(K minKey, K maxKey) :
    max_current_height(1),
    max_height(MAXLEVEL),
    m_min_key(minKey),
    m_max_key(maxKey)
{
    srand(time(NULL));
    m_head = new NODE(m_min_key);
    m_tail = new NODE(m_max_key);
    for (int i = 1; i < MAXLEVEL; ++i) {
        m_head->forwards[i] = m_tail;
    }
}

template<class K, class V, int MAXLEVEL>
SkipList<K, V, MAXLEVEL>::~SkipList()
{
    NODE* curNode = m_head->forwards[1];
    while (curNode != m_tail) {
        NODE* tmpNode = curNode;
        curNode = curNode->forwards[1];
        delete tmpNode;
    }
    delete m_head;
    delete m_tail;
}

template<class K, class V, int MAXLEVEL>
void SkipList<K, V, MAXLEVEL>::insert(K searchedKey, V newValue)
{
    Node<K, V, MAXLEVEL>* path[MAXLEVEL];
    NODE* current = m_head;
    for (int height = max_current_height; height >= 1; --height) {
        while (current->forwards[height]->key < searchedKey) {
            current = current->forwards[height];
        }
        path[height] = current;
    }
    current = current->forwards[1];
    if (current->key == searchedKey) {
        current->value = newValue;
    }
    else {
        int newHeight = randomLevel();
        if (newHeight > max_current_height) {
            for (int level = max_current_height + 1; level <= newHeight; ++level) {
                path[level] = m_head;
            }
            max_current_height = newHeight;
        }
        current = new NODE(searchedKey, newValue);
        for (int height = 1; height <= max_current_height; ++height) {
            current->forwards[height] = path[height]->forwards[height];
            path[height]->forwards[height] = current;
        }
    }
}

template<class K, class V, int MAXLEVEL>
void SkipList<K, V, MAXLEVEL>::remove(K searchedKey)
{
    Node<K, V, MAXLEVEL>* path[MAXLEVEL];
    NODE* current = m_head;
    for (int height = max_current_height; height >= 1; --height) {
        while (current->forwards[height]->key < searchedKey) {
            current = current->forwards[height];
        }
        path[height] = current;
    }
    current = current->forwards[1];
    if (current->key == searchedKey) {
        for (int height = 1; height <= max_current_height; ++height) {
            if (path[height]->forwards[height] != current) {
                break;
            }
            path[height]->forwards[height] = current->forwards[height];
        }
        delete current;
        while (max_current_height > 1 && m_head->forwards[max_current_height] == NULL) {
            max_current_height--;
        }
    }
}

template<class K, class V, int MAXLEVEL>
bool SkipList<K, V, MAXLEVEL>::isEmpty() const
{
    return m_head->forwards[1] == m_tail;
}

template<class K, class V, int MAXLEVEL>
void SkipList<K, V, MAXLEVEL>::displayList()
{
    NODE* current = m_head->forwards[1];
    while (current != m_tail) {
        cout << "(" << current->key << ", " << current->value << ")" << endl;
        current = current->forwards[1];
    }
}

template<class K, class V, int MAXLEVEL>
const Node<K, V, MAXLEVEL>* SkipList<K, V, MAXLEVEL>::search(K searchedKey)
{
    typedef Node<K, V, MAXLEVEL> NodeType;
    NodeType* current = m_head;
    for (int height = max_current_height; height >= 1; --height) {
        while (current->forwards[height]->key < searchedKey) {
            current = current->forwards[height];
        }
    }
    current = current->forwards[1];
    if (current->key == searchedKey) {
        return current;
    }
    else return NULL;
}
