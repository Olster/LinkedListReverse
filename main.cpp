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

  list::LinkedList<int>::Iterator it = list.Begin();
  for (int i = 0; i < list.GetSize(); i++, ++it) {
    cout << *it << endl;
  }

  list.Reverse();
  cout << endl;

  it = list.Begin();
  for (int i = 0; i < list.GetSize(); i++, ++it) {
    cout << *it << endl;
  }

  return 0;
}
