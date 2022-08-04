#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> findGreaterOnTheLeft(int arr[], int size) {
  vector<int> v;
  stack<int> s;
  s.push(arr[0]);
  v.push_back(-1);
  bool found = false;

  for (int i = 1; i < size; i++) {
    while (!s.empty() && arr[i] >= s.top()) {
      s.pop();
    }
    s.empty() ? v.push_back(-1) : v.push_back(s.top());
    s.push(arr[i]);
}

  return v;
}

void printVector(vector<int> v) {
  for (auto e:v) {
    cout << e << " ";
  }
  cout << endl;
}

int main() {
  int arr[] = {15, 10, 18, 12, 4, 6, 2, 8};
  int size = sizeof(arr)/sizeof(arr[0]);
  if (size < 1) {
    return 0;
  }

  vector<int> v = findGreaterOnTheLeft(arr, size);
  printVector(v);

  int arr1[] = {8, 10, 12};
  size = sizeof(arr1)/sizeof(arr1[0]);
  if (size < 1) {
    return 0;
  }

  v = findGreaterOnTheLeft(arr1, size);
  printVector(v);

  int arr2[] = {12, 10, 8};
  size = sizeof(arr2)/sizeof(arr2[0]);
  if (size < 1) {
    return 0;
  }

  v = findGreaterOnTheLeft(arr2, size);
  printVector(v);

  return 0;
}
