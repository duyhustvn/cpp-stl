#include <iostream>

using namespace std;

int main() {
  // sample array
  int arr[] = {10,15,8,20};

  sort(arr, arr + 4);

  for (int i = 0; i < 4; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;

  if (binary_search(arr, arr + 4, 8)) {
    cout << "Present" << endl;
  } else {
    cout << "Not present" << endl;
  }

  return 0;
}
