#include <iostream>
#include <stack>

using namespace std;

string revertString(char str[], int size) {
  string revertedString = "";
  stack<char> s;
  for (int i = 0; i < size; i++) {
    s.push(str[i]);
  }
  while (!s.empty()) {
    char c = s.top();
    s.pop();
    revertedString.push_back(c);
  }
  return revertedString;
}

int main() {
  char str[] = "geeks";
  int size = sizeof(str)/sizeof(str[0]);
  string revertedString = revertString(str, size);
  cout << "original string: " << str << " reverted string: " << revertedString << endl;
  return 0;
}
