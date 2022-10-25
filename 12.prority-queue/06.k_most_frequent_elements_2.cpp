#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct MyCmp {
  bool operator()(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
  }
};

void findKMostFrequentElementUsingPriorityQueue(int arr[], int size, int k) {
  unordered_map<int, int> umap;

  for (int i = 0; i < size; i++) {
    umap[arr[i]]++;
  }

  priority_queue<pair<int, int>, vector<pair<int, int> >, MyCmp > pq(umap.begin(), umap.end());

  vector<int> prefix;
  for (int i = 0; i < k-1; i++) {
    prefix.push_back(pq.top().first);
    pq.pop();
  }
  cout << endl;


   vector<int> equal;
   pair<int, int> lastElement = pq.top();
   equal.push_back(lastElement.first);
   pq.pop();
   while (!pq.empty()) {
     if (pq.top().second == lastElement.second) {
       equal.push_back(pq.top().first);
       pq.pop();
     } else {
       break;
     }
   }


   for (int i = 0; i < equal.size(); i++) {
     for (int j = 0; j < prefix.size(); j++) {
       cout << prefix[j] << " ";
     }
     cout << equal[i] << endl;
   }
}

void findKMostFrequentElement(int arr[], int size, int k) {
  unordered_map<int, int> umap;
  // Time complexity: O(n)
  for (int i = 0; i < size; i++) {
    umap[arr[i]]++;
  }

  vector<int> freq[size+1];

  // Time complexity: O(n)
  // for (auto x:umap) {
  //   freq[x.second].push_back(x.first);
  // }

  for (int i = 0; i < size; i++) {
    int f = umap[arr[i]];
    if (f != -1) {
      freq[f].push_back(arr[i]);
      umap[arr[i]] = -1;
    }
  }


  int count = 0;

  // Time complexity: O(n*n)
  for (int i = size; i >= 0; i--) {
    for (int x: freq[i]) {
      cout << x << " ";
      count++;
      if (count == k) {
        return;
      }
    }
  }
}

int main() {
  int arr1[] = {6, 7, 6, 7, 6, 7, 4, 4, 2, 2, 5};
  int size = sizeof(arr1)/sizeof(arr1[0]);
  int k = 3;

  findKMostFrequentElementUsingPriorityQueue(arr1, size, k);
  findKMostFrequentElement(arr1, size, k);
  return 0;
}
