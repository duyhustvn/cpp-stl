#include <iostream>
#include <queue>

using namespace std;

void mySortUsingMaxHeap(int arr[], int size) {
  priority_queue<int> pq(arr, arr+size);
  for (int i = size-1; i >= 0; i--) {
    arr[i] = pq.top();
    pq.pop();
  }
}

void mySortUsingMinHeap(int arr[], int size) {
  priority_queue<int, vector<int>, greater<int> >pq(arr, arr+size);
  for (int i = 0; i < size; i++) {
    arr[i] = pq.top();
    pq.pop();
  }
}

int main() {
  int arr1[] = {8, 5, 12, 20};
  int size = sizeof(arr1)/sizeof(arr1[0]);

  mySortUsingMaxHeap(arr1, size);

  for (int i = 0; i < size; i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;


  int arr2[] = {8, 5, 12, 20, 1};
  size = sizeof(arr2)/sizeof(arr2[0]);
  mySortUsingMinHeap(arr2, size);
  for (int i = 0; i < size; i++) {
    cout << arr2[i] << " ";
  }
  cout << endl;

  return 0;
}
