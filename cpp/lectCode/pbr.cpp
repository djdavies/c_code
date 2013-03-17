#include <iostream>
using namespace std;

void f(int* p) {
	cout << *p << endl;
	cout << *(p+1) << endl;
}

int main() {
	int a[] = {1, 2, 3};
	f(&a[0]);
}