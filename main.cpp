#include <iostream>

#include "CLinkedList.h"

using namespace std;

int main() {

    CLinkedList list;

    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(6);
    list.add(7);

    list.print();

    list.reverse();
    cout << endl;

    list.print();

    return 0;
}
