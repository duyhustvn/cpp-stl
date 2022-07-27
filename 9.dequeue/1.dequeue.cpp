#include <iostream>
#include <deque>

using namespace std;

void printDQ(const deque<int> &dq) {
  for (auto e: dq) {
    cout << e << " ";
  }
  cout << endl;
}

int main() {
  deque<int> dq = {10, 20, 30};
  printDQ(dq);

  dq.push_back(5);
  printDQ(dq);

  deque<int> dq1 = {10, 15, 30, 5, 12};
  auto it = dq1.begin();
  it++;

  dq1.insert(it, 20); // insert 20 before it
  printDQ(dq1);

  return 0;
}
