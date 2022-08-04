#include <iostream>
#include <vector>

using namespace std;

void swap(vector< pair<int, int> > &v, int i, int j) {
  pair<int, int> temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void sortVectorOfPair(vector< pair<int, int> > &v) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size()-1; j++) {
      if (v[j+1].second > v[j].second) {
        swap(v, j+1, j);
      }
    }
  }
}

void printVector(const vector< pair<int, int> > &v) {
  for (pair<int, int> p : v) {
    cout << p.first << " " << p.second << " " << endl;
  }
}

bool myCmp(pair<int, int> p1, pair<int, int> p2) {
  return p1.second > p2.second;
}

int main() {
  int roll[] = {101, 108, 103, 105};
  int marks[] = {70, 80, 40, 90};

  int size = sizeof(marks)/sizeof(marks[0]);

  vector< pair<int, int> > v;
  for (int i = 0; i < size; i++) {
    // v.push_back(make_pair(roll[i], marks[i]));
    v.push_back({roll[i], marks[i]});
  }

  // sortVectorOfPair(v);
  sort(v.begin(), v.end(), myCmp);
  printVector(v);

  return 0;
}
