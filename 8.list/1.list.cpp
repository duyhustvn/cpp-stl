#include <iostream>
#include <list>

using namespace std;

void printList(const list<int> &l) {
  for (int e: l) {
    cout << e << " ";
  }
  cout << endl;
}

int main() {
  list<int> l = {1, 2};
  printList(l);
  l.push_back(10);
  l.push_back(20);
  printList(l);

  l.push_front(5);
  printList(l);

  l.pop_front();
  printList(l);

  l.pop_back();
  printList(l);

  auto it = l.begin();
  it++;
  cout << "Insert 15 before it" << endl;
  it = l.insert(it, 15);
  printList(l);

  cout << "Insert 7 two times before it" << endl;
  it = l.insert(it, 2, 7);
  printList(l);

  cout << "first element: " << l.front() << " last element: " << l.back() << endl;

  cout << endl;
  list<int> l1 = {10, 20, 30, 40, 20, 40, 50};
  printList(l1);

  auto it1 = l1.begin();
  cout << "erase(it) remove element after it. it1: " << *it1 << endl;
  it1 = l1.erase(it1);
  cout << "After earse. it1: " << *it1 << endl;
  printList(l1);


  it1 = l1.end();
  it1--;
  cout << "before erase for last element it1: " << *it1 << endl;
  it1 = l1.erase(it1);
  cout << "After earse. it1: " << *it1 << endl;
  printList(l1);

  cout << "remove(x) remove all element have value of x " << endl;
  l1.remove(40);
  printList(l1);

  cout << endl;
  list<int> l2 = {10, 10, 20, 20, 40, 20, 40};
  printList(l2);
  l2.unique();
  cout << "unique() remove contigous duplicate value" << endl;
  printList(l2);

  l2.sort();
  printList(l2);

  l2.reverse();
  printList(l2);
  return 0;
}
