#include <iostream>
#include <list>

using namespace std;

void printFL(list<int> l) {
  for (auto e: l) {
    cout << e << " ";
  }
  cout << endl;
}

int lastOne(int arr[], int k, int size) {
  list<int> fl;
  for (int i = size-1; i >= 0; i--) {
    fl.push_front(arr[i]);
  }
  printFL(fl);

  auto it = fl.begin();
  int count = 1;
  while (fl.size() != 1) {
    if (count == k) {
      cout << "remove " << *it << endl;
      it = fl.erase(it);
      if (it == fl.end()) {
        it = fl.begin();
      }
      count = 1;
    } else {
      if (it == --fl.end()) {
        it = fl.begin();
      } else {
        it++;
      }
      count++;
    }
  }
  return *(fl.begin());
}

// Josephus problem
int main() {
  int arr[] = {0,1,2,3,4,5,6};
  int k = 3;
  int n = sizeof(arr) / sizeof(arr[0]);
  int lastElement = lastOne(arr, k, n);
  cout << "last element: " << lastElement << endl;


  int arr1[] = {0,1,2,3,4,5,6,7};
  k = 2;
  n = sizeof(arr1) / sizeof(arr1[0]);
  lastElement = lastOne(arr1, k, n);
  cout << "last element: " << lastElement << endl;
  return 0;
}
