#include <iostream>

#include "CLinkedList.h"

using namespace std;

int main() {

    CLinkedList list;

    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Add(4);
    list.Add(5);
    list.Add(6);
    list.Add(7);

    list.Print();

    list.Reverse();
    cout << endl;

    list.Print();

    return 0;
}
