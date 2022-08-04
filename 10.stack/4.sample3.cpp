#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void printVector(vector<int> v) {
  for (auto e: v) {
    cout << e << " ";
  }
  cout << endl;
}


//vector<int> stockSpan(int arr[], int size) {
//  vector<int> span;
//  for (int i = 0; i < size; i++) {
//    int count = 1;
//    for (int j = i-1; j >= 0; j--) {
//      if (arr[i] >= arr[j]) {
//        count++;
//      } else {
//        break;
//      }
//    }
//    span.push_back(count);
//  }
//  return span;
//}

void printStack(int arr[], stack<int> s) {
  cout << "stack size: " << s.size() << endl;
  while (!s.empty()) {
    cout << arr[s.top()] << " -> " << " ";
    s.pop();
  }
  cout << endl;
}

vector<int> stockSpan(int arr[], int size) {
  stack<int> s;
  vector<int> span;
  s.push(0);
  span.push_back(1);
  for (int i = 1; i < size; i++) {
    int count = 0;
    while (!s.empty() && arr[i] > arr[s.top()]) {
      s.pop();
    }
    if (!s.empty()) {
      count = i - s.top();
    } else {
      count = i+1;
    }
    s.push(i);
    span.push_back(count);
  }
  return span;
}


int main() {
  int arr[] = {15, 13, 12, 14, 16, 8, 6, 4, 10, 30};
  int size = sizeof(arr) / sizeof(arr[0]);
  vector<int> span = stockSpan(arr, size);
  printVector(span);
  return 1;
}
