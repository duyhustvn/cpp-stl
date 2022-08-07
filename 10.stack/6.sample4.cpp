#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> findNextGreater(int arr[], int size) {
  vector<int> v;
  stack<int> s;

  v.push_back(-1);
  s.push(arr[size-1]);

  for (int i = size - 2; i >= 0; i--) {
    while (!s.empty() && arr[i] >= s.top()) {
      s.pop();
    }

    s.empty() ? v.insert(v.begin(), -1) : v.insert(v.begin(), s.top());
    s.push(arr[i]);
  }

  return v;
}

void printVector(vector<int> v) {
  for (auto e: v) {
    cout << e << " ";
  }
  cout << endl;
}

int main() {
  int arr1[] = {5, 15, 10, 8, 6, 12, 9, 18};
  int size = sizeof(arr1)/sizeof(arr1[0]);

  vector<int> v = findNextGreater(arr1, size);
  printVector(v);


  int arr2[] = {10, 15, 20, 25};
  size = sizeof(arr2)/sizeof(arr2[0]);

  v = findNextGreater(arr2, size);
  printVector(v);

  int arr3[] = {25, 20, 15, 10};
  size = sizeof(arr3)/sizeof(arr3[0]);

  v = findNextGreater(arr3, size);
  printVector(v);

  return 0;
}
