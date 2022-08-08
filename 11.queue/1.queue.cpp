#include <iostream>
#include <queue>

using namespace std;

int main() {
  queue<int> q;
  q.push(10);
  q.push(20);
  q.push(30);

  while (!q.empty()) {
    cout << "front: " << q.front() << " back: " << q.back() << endl;
    q.pop();
  }

  return 0;
}
