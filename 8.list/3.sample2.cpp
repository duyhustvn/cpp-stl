#include <iostream>
#include <list>

using namespace std;

template <typename T>

void insert(list<T> &l, T v) {
  l.push_back(v);
}

template <typename T>
void print(list<T> l) {
  for (T it: l) {
    cout << it << " ";
  }
  cout << endl;
}

template <typename T>
void replace(list<T> &l, T v, T replaceValue) {
  for (auto it = l.begin(); it != l.end(); it++) {
    if (*it == v) {
      it = l.erase(it);
      it = l.insert(it, replaceValue);
      break;
    }
  }
}

template <typename T>
void replace(list<T> &l, T v, list<T> replaceValue) {
  for (auto it = l.begin(); it != l.end(); it++) {
    if (*it == v) {
      it = l.erase(it);
      for (auto it1 = replaceValue.rbegin(); it1 != replaceValue.rend(); it1++) {
        it = l.insert(it, *it1);
      }
      break;
    }
  }
}



int main() {
  list<int> l;
  cout << "insert 3" << endl;
  insert<int>(l, 3);
  print<int>(l);
  cout << "insert 3" << endl;
  insert<int>(l, 3);
  print<int>(l);
  cout << "insert 4" << endl;
  insert<int>(l, 4);
  print<int>(l);

  cout << "replace 1st 3 with 2" << endl;
  replace<int>(l, 3, 2);
  print<int>(l);
  cout << "replace 1st 4 with 5" << endl;
  replace<int>(l, 4, 5);
  print<int>(l);


  cout << "replace 1st 3 with 8 9" << endl;
  replace<int>(l, 3, {8, 9});
  print<int>(l);


  cout << "replace 1st 5 with 10 12" << endl;
  replace<int>(l, 5, {10, 12});
  print<int>(l);


  cout << "replace 1st 2 with 6 7" << endl;
  replace<int>(l, 2, {6, 7});
  print<int>(l);

  return 0;
}
