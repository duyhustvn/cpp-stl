#include <iostream>
#include <queue>

using namespace std;

void printVector(vector<int> v) {
  for (auto e: v) {
    cout << e << " ";
  }
  cout << endl;
}

vector<int> findKMaxElement(int arr[], int size, int k) {
  vector<int>v;
  // time complexity: O(k * log(k))
  priority_queue<int, vector<int>, greater<int> >q(arr, arr+k);

  // time complexity: 0((n-k) * log(k))
  for (int i = k; i < size; i++) {
    if (arr[i] >= q.top()) {
      q.pop();
      q.push(arr[i]);
    }
  }

  // time complexity: O(k)
  while (!q.empty()) {
    v.push_back(q.top());
    q.pop();
  }
  return v;
}

int main() {
  int arr1[] = {1, 4, 6, 2, 3, 8, 9, 5, 7, 0};
  int size = sizeof(arr1)/sizeof(arr1[0]);
  int k = 3;
  vector<int> v = findKMaxElement(arr1, size, k);
  printVector(v);
  return 0;
}
