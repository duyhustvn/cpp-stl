#include <iostream>
#include <queue>

using namespace std;

void priorityQueueUsingMaxHeap() {
  priority_queue<int> pq;

  pq.push(30);
  pq.push(20);
  pq.push(50);
  pq.push(10);
  pq.push(40);

  cout << "Priority queue using max heap" << endl;
  cout << "priority size: " << pq.size() << endl;
  cout << "top: " << pq.top() << endl;
  while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << endl << endl;
}

void priorityQueueUsingMinHeap() {
  priority_queue<int, vector<int>, greater<int> > pq;
  pq.push(30);
  pq.push(20);
  pq.push(50);
  pq.push(10);
  pq.push(40);

  cout << "Priority queue using min heap" << endl;
  cout << "priority size: " << pq.size() << endl;
  cout << "top: " << pq.top() << endl;
  while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << endl << endl;

}

void priorityQueueFromArray() {
  int arr[] = {5, 15, 10, 12};
  priority_queue<int> pq(arr, arr+4);
  cout << "priority queue from array" << endl;
  cout << "priority size: " << pq.size() << endl;
  cout << "top: " << pq.top() << endl;
  while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << endl << endl;
}

void priorityQueueFromVector() {
  vector<int>v = {5, 15, 10, 12};
  priority_queue<int> pq(v.begin(), v.end());
  cout << "priority queue from vector" << endl;
  cout << "priority size: " << pq.size() << endl;
  cout << "top: " << pq.top() << endl;
  while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << endl << endl;
}

int main() {
  priorityQueueUsingMaxHeap();
  priorityQueueUsingMinHeap();
  priorityQueueFromArray();
  priorityQueueFromVector();
  return 0;
}
