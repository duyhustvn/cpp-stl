#include <iostream>

using namespace std;

template <typename T>

T myMax(T x, T y) {
  return (x > y) ? x : y;
}

template <typename T1>
T1 arrMax(T1 arr[], int n) {
  T1 res = arr[1];
  for (int i = 1; i < n; i++) {
    if (arr[i] > res) {
      res = arr[i];
    }
  }
  return res;
}

int main() {
  int result = myMax<int>(3, 7);
  cout << result << endl;

  char c = myMax<char>('c', 'g');
  cout << c << endl;

  int arr[] = {1,2,3,6,5};
  int maxE = arrMax<int>(arr, 5);
  float maxE1 = arrMax(arr, 4);
  cout << maxE << endl;
  cout << maxE1 << endl;

  float arr1[] = {1.1, 2.2, 5.5, 4.4};
  float maxF = arrMax<float>(arr1, 4);
  float maxF1 = arrMax(arr1, 4);
  cout << maxF << endl;
  cout << maxF1 << endl;
}
