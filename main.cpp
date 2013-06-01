#include <iostream>

#include "list/LinkedList.h"

using namespace std;

int main() {
  list::LinkedList<int> list;

  list.Add(1);
  list.Add(2);
  list.Add(3);
  list.Add(4);
  list.Add(5);
  list.Add(6);
  list.Add(7);

  while (list.GetNext()) {
    cout << list.GetNext()->val << endl;
  }

  list.Reverse();
  cout << endl;

  cout << list.GetHead()->val << endl;
  for (int i = 0; i < list.GetSize(); i++) {
    cout << list.GetNext()->val << endl;
  }

  return 0;
}
