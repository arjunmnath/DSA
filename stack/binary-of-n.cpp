#include <iostream>
#include <stack>

using namespace std;


int main() {
    stack<int> s;
    int n;
    cout << "enter a number: ";
    cin >> n;
    while (n!=0)     
    {
        s.push(n & 1);
        n >>= 1;
    }    
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}
