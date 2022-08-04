#include <iostream>

using namespace std;

void pairSort(int arr[], char b[], int n) {
  pair<int, char> arr_p[n];

  for (int i = 0; i < n; i++) {
    //arr_p[i].first = arr[i];
    //arr_p[i].second = b[i];
    arr_p[i] = { arr[i], b[i] };
  }

  sort(arr_p, arr_p + n);

  for (int i = 0; i < n; i++) {
    b[i] = arr_p[i].second;
  }

  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << endl;
}

int main() {
  int a[] = {2, 1, 5, 4, 8, 3, 6, 7};
  int n = sizeof(a) / sizeof(a[0]);
  char b[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

  pairSort(a, b, n);
  return 0;
}
