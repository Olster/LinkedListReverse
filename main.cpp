#include <iostream>
#include <string>

#include "list/LinkedList.h"

using namespace std;

void TestInt();
void TestString();

int main() {
  TestInt();

  cout << endl;

  TestString();

  return 0;
}

void TestInt() {
  list::LinkedList<int> list;

  list.Add(1);
  list.Add(2);
  list.Add(3);
  list.Add(4);
  list.Add(5);
  list.Add(6);
  list.Add(7);

  for (auto it = list.Begin(); it != list.End(); ++it) {
    cout << *it << endl;
  }

  list.Reverse();
  cout << endl;

  for (auto it = list.Begin(); it != list.End(); ++it) {
    cout << *it << endl;
  }
}

void TestString() {
  list::LinkedList<string> list;

  list.Add("Hello");
  list.Add("I'm here");
  list.Add("Test1");
  list.Add("Test2");
  list.Add("Test3");

  for (auto it = list.Begin(); it != list.End(); ++it) {
    cout << *it << endl;
  }

  list.Reverse();
  cout << endl;

  for (auto it = list.Begin(); it != list.End(); ++it) {
    cout << *it << endl;
  }
}
