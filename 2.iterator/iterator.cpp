#include<iostream>
#include<vector>

using namespace std;

int main() {
  vector<int> v = { 10, 20, 30, 40, 50 };
  vector<int>::iterator i = v.begin();
  cout << *i << " ";
  i++;
  cout << *i << " ";
  i += 2;
  cout << *i << " ";
  i = v.end();
  i--;
  cout << *i << endl;



  vector<int>::iterator i2 = v.begin();
  cout << *i2 << " ";
  i2 = next(i2);
  cout << *i2 << " ";
  i2 = next(i2, 2);
  cout << *i2 << " ";
  i2 = prev(i2);
  cout << *i2 << " ";
  i2 = v.end();
  i2 = prev(i2);
  cout << *i2 << " " << endl;


  vector<int>::iterator i3 = v.begin();
  cout << *i3 << " ";
  advance(i3, 3);
  cout << *i3 << " ";

  cout << endl;
  return 0;
}
