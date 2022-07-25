#include <iostream>
#include <vector>

using namespace std;

void updateVector(vector<int> v) {
  v.push_back(10);
  v.push_back(11);
}

void updateVectorUsingReference(vector<int> &v) {
  v.push_back(11);
  v.push_back(10);
}

void printVector(vector<int> &v) {
  for (const int e : v) {
    // using const to prevent vector from updating value of element in vector
    cout << e << " ";
  }
  cout << endl;
}

//void preventUpdate(const vector<int> &v) {
//  for (int &e: v) {
//    e = 1;
//  }
//}

int main() {
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;

  // v.at() check index out of bound error
  // v[i] DOESN'T check index out of bound error
  for (int i = 0; i < v.size(); i++) {
    cout << v.at(i) << " ";
  }
  cout << endl;

  vector<int> v1{10,20,30};
  for (int x:v1) {
    cout << x << " ";
  }
  cout << endl;

  vector<int>::iterator it;

  for (it = v1.begin(); it != v1.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  int arr[] = {4,5,6,7,8,9};
  int n = sizeof(arr)/sizeof(arr[0]);
  vector<int> v2(arr, arr + n);
  vector<int>::iterator it1;
  for (it1 = v2.begin(); it1 != v2.end(); it1++) {
    cout << *it1 << " ";
  }
  cout << endl;

  vector<int>::reverse_iterator it2 ;
  for (it2 = v2.rbegin(); it2 != v2.rend(); it2++) {
    cout << *it2 << " ";
  }
  cout << endl;

  vector<int> v3{1, 3, 5, 4, 8};
  cout << "first element: " << v.front() << " last element: " << v.back() << endl;


  cout << "remove las element with pop_back: " << endl;
  cout << "Before remove" << endl;
  for (int x : v3) {
    cout << x << " ";
  }
  cout << endl;
  v3.pop_back();

  cout << "After remove" << endl;
  for (int x : v3) {
    cout << x << " ";
  }

  cout << endl;
  cout << "first element: " << v.front() << " last element: " << v.back() << endl;

  cout << "Change value of first element and last element" << endl;
  v3.front() = 100;
  v3.back() = 400;
  cout << "After change first element: " << v.front() << " last element: " << v.back() << endl;

  cout << "Insert 1 to the begin of the vector" << endl;
  v3.insert(v3.begin(), 1);
  for (int x : v3) {
    cout << x << " ";
  }

  cout << endl;

  cout << "Insert 4 at the 2nd index of the vector" << endl;
  v3.insert(v3.begin() + 2, 4);
  for (int x : v3) {
    cout << x << " ";
  }

  cout << "Insert 5 two times at the 1st index of the vector" << endl;
  v3.insert(v3.begin() + 1, 2, 5);
  for (int x : v3) {
    cout << x << " ";
  }
  cout << endl;

  vector<int> v4;
  cout << "insert value from 0th to 3th element of v3 to v4" << endl;
  v4.insert(v4.begin(), v3.begin(), v3.begin() + 4);
  for (int x : v4) {
    cout << x << " ";
  }
  cout << endl;

  cout << "delete first element from vector" << endl;
  v4.erase(v4.begin());
  for (int x : v4) {
    cout << x << " ";
  }
  cout << endl;

  cout << "delete all except last 2 elements" << endl;
  v4.erase(v4.begin(), v4.end() - 2);
  for (int x : v4) {
    cout << x << " ";
  }
  cout << endl;

  cout << "clear all element in vector" << endl;
  v4.clear();
  if (v4.empty()) {
    cout << "Vector is empty" << endl;
  } else {
    cout << "Vector is NOT empty" << endl;
  }

  vector<int> v5 = v2;
  cout << "Vector v5: ";
  for (int x : v5) {
    cout << x << " ";
  }
  cout << " with size: " << v5.size();
  cout << endl;

  cout << "Resize vector to 4" << endl;
  v5.resize(4);
  cout << "Vector v5: ";
  for (int x : v5) {
    cout << x << " ";
  }

  cout << "Resize vector to 6 all unassigned value will have default value" << endl;
  v5.resize(6);
  cout << "Vector v5: ";
  for (int x : v5) {
    cout << x << " ";
  }
  cout << endl;

  cout << "Resize vector to 8 all unassigned value will have default value of 10" << endl;
  v5.resize(8, 10);
  cout << "Vector v5: ";
  for (int x : v5) {
    cout << x << " ";
  }
  cout << endl;

  vector<int> v6 = v2;
  cout << "Vector v6: ";
  for (int x : v6) {
    cout << x << " ";
  }
  cout << endl;

  updateVector(v6);
  cout << "Vector is pass by value. So after calling function vector 6 is not change." << endl << "Vector v6: ";
  printVector(v6);

  updateVectorUsingReference(v6);
  cout << "Vector is pass by reference. So after calling function vector 6 is change." << endl << "Vector v6: ";
  printVector(v6);

  cout << "This will NOT UPDATE value of element in vector" << endl << "Vector v6: ";
  for (int x : v6) {
    x = 1;
  }
  printVector(v6);

  cout << "This will UPDATE value of element in vector" << endl << "Vector v6: ";
  for (int &x : v6) {
    x = 1;
  }
  printVector(v6);

  return 0;
}
