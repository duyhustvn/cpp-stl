#include <iostream>
#include <vector>

using namespace std;

bool mycmp(pair<int, int> p1, pair<int, int> p2) {
  return p1.first < p2.first;
}

void printVector(const vector< pair<int, int> > v) {
  for (pair<int, int> e: v) {
    cout << e.first << " " << e.second << endl;
  }
}

int main() {
  int arr[] = {20, 40, 30, 10};

  vector< pair<int, int> > v;
  int size = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < size; i++) {
    v.push_back({arr[i], i});
  }

  sort(v.begin(), v.end(), mycmp);
  printVector(v);
  return 1;
}
