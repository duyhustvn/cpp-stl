#include <iostream>

#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

bool myCmp(pair<int, int> p1, pair<int, int> p2) {
  if (p1.second == p2.second) {
    return p1.first < p2.first;
  }
  return p1.second > p2.second;
}

void findKMostFrequentElement(int arr[], int size, int k) {
  /*
    Time complexity: O(n + n + nlogn + k)
   */

  unordered_map<int, int> umap;

  // Time complexity: O(n)
  for (int i = 0; i < size; i++) {
    // key not found
    if (umap.find(arr[i]) == umap.end()) {
      umap[arr[i]] = 1;
    } else {
      umap[arr[i]] = umap.at(arr[i]) + 1;
    }
  }

  // Time complexity: O(n)
  vector<pair<int, int> > v(umap.begin(), umap.end());

  // Time complexity: O(nlogn)
  sort(v.begin(), v.end(), myCmp);

  // Time complexit: O(k)
  for (int i = 0; i < k; i++) {
    cout << v[i].first << " ";
  }
  cout << endl;
}

void printPQ(priority_queue<pair<int, int> > q) {
  while (!q.empty()) {
    cout << q.top().first;
    q.pop();
  }
  cout << endl;
}


struct MyCmp {
  bool operator() (pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) {
      return p1.first > p2.first;
    }
    return p1.second < p2.second;
  }
};

void findKMostFrequentElementUsingPriorityQueue(int arr[], int size, int k) {
  /*
    Time complexity: O(n + n + klogn)
   */


  unordered_map<int, int> umap;

  // Time complexity O(n)
  for (int i = 0; i < size; i++) {
    umap[arr[i]]++;
  }

  // Time complexity O(n)
  priority_queue<pair<int, int>, vector<pair<int, int> >, MyCmp > pq(umap.begin(), umap.end());
  int count = 0;

  // Time complexity O(klogn)
  while (!pq.empty() && count < k) {
    count++;
    cout <<  pq.top().first << " ";
    pq.pop();
  }
  cout << endl;
}

int main() {
  int arr1[] = {10, 5, 20, 5, 10, 10, 30, 5};
  int size = sizeof(arr1)/sizeof(arr1[0]);
  int k = 2;

  findKMostFrequentElement(arr1, size, k);
  findKMostFrequentElementUsingPriorityQueue(arr1, size, k);
  return 0;
}
