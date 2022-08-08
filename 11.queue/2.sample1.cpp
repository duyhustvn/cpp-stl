#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void revertKItem(queue<int> &q, int k) {
  stack<int> s;
  int count = 0;
  while (!q.empty() && count < k) {
    int front = q.front();
    s.push(front);
    q.pop();
    count++;
  }

  while (!s.empty()) {
    int front = s.top();
    s.pop();
    q.push(front);
  }

  for (int i = 0; i < q.size()-k; i++) {
    int front = q.front();
    q.pop();
    q.push(front);
  }
}

void printQueue(queue<int> q) {
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}

int main() {
  queue<int> q;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  int k = 2;
  revertKItem(q, k);
  printQueue(q);
  return 0;
}
