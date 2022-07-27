#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void printVector(const vector<int> &v) {
  for (auto e: v) {
    cout << e << " ";
  }
  cout << endl;
}

int max(int arr[], int start, int end) {
  int max = 0;
  for (int i = start; i <= end; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

vector<int> maxInSubArrayOpt(int arr[], int size, int k) {
  vector<int> listMax;
  deque<int> dq;

  for (int i = 0; i < k; i++) {
    while (!dq.empty() && arr[i] >= arr[dq.back()]) {
      dq.pop_back();
    }
    dq.push_back(i);
  }

  for (int i = k; i < size; i++) {
    listMax.push_back(arr[dq.front()]);
    // remove out of slide window
    while (!dq.empty() && dq.front() <= i-k) {
      dq.pop_front();
    }

    //
    while (!dq.empty() && arr[i] >= arr[dq.back()]) {
      dq.pop_back();
    }
    dq.push_back(i);
  }

  listMax.push_back(arr[dq.front()]);
  return listMax;
}

vector<int> maxInSubArray(int arr[], int size, int k) {
  vector<int>v;
  for (int i = 0; i < size- k + 1; i++) {
    int maxValue = max(arr, i, i + k - 1);
    v.push_back(maxValue);
  }
  return v;
}

int main() {
  int arr1[] = {10, 8, 5, 12, 15, 7, 6};
  int k = 3;
  int size = sizeof(arr1)/ sizeof(arr1[0]);

  vector<int> listMax = maxInSubArrayOpt(arr1, size, k);
  printVector(listMax);

  //vector<int> v = maxInSubArray(arr1, size, k);
  //for (auto e: v) {
  //  cout << e << " ";
  //}
  //cout << endl;

  int arr2[] = {20, 5, 3, 8, 6, 15};
  k = 4;
  size = sizeof(arr2)/ sizeof(arr2[0]);

  vector<int> listMax2 = maxInSubArrayOpt(arr2, size, k);
  printVector(listMax2);

  //vector<int> v1 = maxInSubArray(arr2, size, k);
  //for (auto e: v1) {
  //  cout << e << " ";
  //}
  //cout << endl;

  return 0;
}
