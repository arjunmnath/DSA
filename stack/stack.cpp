#include <iostream>
#define STACK_SIZE 100	
using namespace std;
class Stack {
	private:		
		int _stack[STACK_SIZE];
		int top;
	public:		
		Stack(){
			top = -1;
		}
		bool isFull(){
			return top >= STACK_SIZE-1;
		}
		bool isEmpty()
		{
			return top == -1;

		}
		void push(int a) {
			if (isFull()) {
				cout<< "Error: Stack Overflow" << endl;
				return;
			}
			_stack[++top] = a;
		}
		int pop() {
			if (isEmpty()) {
				cout << "Error: Stack Underflow" << endl;
				return 0;
			}	
			return _stack[top--];
		}
};
/*

int main() {
	Stack s;
	s.push(10);
	s.push(30);
	cout << s.pop() << " " << s.pop() << endl;
	}
*/
