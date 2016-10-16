#include <iostream>
#include "skiplist.cpp"

using namespace std;

int main()
{
    //tests
    int min = 1;
    int max = 100;
    SkipList<int, int*> skiplist = SkipList<int, int*>(min, max);
    int key = 44;
    int* value = new int(2);
    skiplist.insert(key, value);
    for (int i = 0; i < 10; ++i) {
        skiplist.insert(i, new int (i));
    }
    skiplist.displayList();
    if (skiplist.isEmpty())
        cout << "Vide !" << endl;
    return 0;
}

