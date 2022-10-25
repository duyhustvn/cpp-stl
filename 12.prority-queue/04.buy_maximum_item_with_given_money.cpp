#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int purchaseMaxItemUsingSort(int arr[], int size, int k) {
  // Sort array
  // Time comlexity: O(n*logn)
  sort(arr, arr+size);

  // Time complexity: 0(n)
  for (int i = 0; i < size; i++) {
    if (k >= arr[i]) {
      k -= arr[i];
    } else {
      return i;
    }
  }

  // Total time complexity O(n + n*logn)
  return size;
}

int purchaseMaxItemUsingMinHeap(int arr[], int size, int k) {
  priority_queue<int, vector<int>, greater<int> > p(arr, arr+size);

  int count = 0;
  while (!p.empty()) {
    if (k >= p.top()) {
      k -= p.top();
      p.pop();
      count++;
    } else {
      break;
    }
  }
  return count;
}

int main() {
  int arr1[] = {12, 5, 111, 200, 1};
  int size = sizeof(arr1)/sizeof(arr1[0]);
  int k = 328;
  int maxItem = purchaseMaxItemUsingSort(arr1, size, k);
  cout << maxItem << endl;
  maxItem = purchaseMaxItemUsingMinHeap(arr1, size, k);
  cout << maxItem << endl;
  return 0;
}
