#include <iostream>
#include <forward_list>

using namespace std;

void printFL(forward_list<int> l) {
  for (auto it = l.begin(); it != l.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

int main() {
  forward_list<int> l;
  // assign will create new list and update value of l

  l.assign({40, 10});
  printFL(l);

  l.assign({10, 20, 30, 10});
  printFL(l);

  l.remove(10);
  cout << "Remove will remove all instance with value of 10" << endl;
  printFL(l);

  forward_list<int> l2;
  l2.assign(l.begin(), l.end());
  printFL(l2);

  cout << "Create forward_list with 5 elements and each element has value of 5" << endl;
  l2.assign(5, 10);
  printFL(l2);

  cout << endl << endl;
  forward_list<int> l3;
  l3.assign({15, 20, 30});
  printFL(l3);
  auto it = l3.insert_after(l3.begin(), 10);
  printFL(l3);
  it = l3.insert_after(it, {2, 3, 5});
  printFL(l3);
  it = l3.emplace_after(it, 40);
  printFL(l3);
  // it = l3.emplace_after(it, {8, 9});
  // printFL(l3);
  cout << "Erase_after in this case remove only 1 element after it" << endl;
  it = l3.erase_after(it);
  printFL(l3);

  cout << "Erase_after in this case remove all element after it" << endl;
  it = l3.erase_after(it, l3.end());
  printFL(l3);


  forward_list<int> l4 = {5, 10, 15};
  forward_list<int> l5 = {6, 12};
  cout << "Before merge" << endl;
  cout << "l4: ";
  printFL(l4);
  cout << "l5 ";
  printFL(l5);

  l4.merge(l5);

  cout << "After merge l5 will be merge into l4 and l5 will be clear" << endl;
  cout << "l4: ";
  printFL(l4);
  cout << "l5 ";
  printFL(l5);

  return 0;
}
