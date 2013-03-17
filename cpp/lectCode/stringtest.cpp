#include <string>
#include <iostream>
using namespace std;

int main() {
  string s1 = "Hello";
  string s2 = s1;
  cout << &s1 << " " << s1 << endl;
  cout << &s2 << " " << s2 << endl;
  s1[0] = 'h';
  cout << &s1 << " " << s1 << endl;
  cout << &s2 << " " << s2 << endl;
 } ///:~