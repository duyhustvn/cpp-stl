#include <iostream>
#include <stack>

using namespace std;

bool isMatch(char a, char b) {
  return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
}

bool isBalance(string s) {
  stack<char> st;
  char ch;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
      st.push(s[i]);
    } else {
      if (st.empty()) {
        return false;
      }
      if (!isMatch(st.top(), s[i])) {
        return false;
      }
      st.pop();
    }
  }
  return true;
}

int main() {
  string s1 = "{}[]";
  cout << s1 << " is " << (isBalance(s1) ? " balance" : " not balance") << endl;


  s1 = "{[]}";
  cout << s1 << " is " << (isBalance(s1) ? " balance" : " not balance") << endl;


  s1 = "{[])";
  cout << s1 << " is " << (isBalance(s1) ? " balance" : " not balance") << endl;


  return 1;
}
