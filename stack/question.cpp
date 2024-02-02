//20 10 30 40 -> 10, 40, 30, 20
#include <iostream>
#include "stack.cpp"
using namespace std;

int main() {
	Stack s;
	int a, b;
	for (int i=0; i< 4; i++ ){ 
		cin >> a;
		if (i==1) {
			b = a;
			continue; 
		}
		s.push(a);
	}
	cout << b << " " ;
	while (!s.isEmpty()) {
		cout << s.pop() << " ";
	}
	cout << endl;
}

	

	
		
