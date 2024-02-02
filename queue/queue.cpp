#include <iostream>
using namespace std;
#define MAX_SIZE 100
class Queue{
    private:
        int _queue[MAX_SIZE];
        int front, rear;
    public:
        Queue() {
            front=-1;
            rear=-1;
        }
        bool empty(){
            return rear == -1 && front == -1;
        }
        bool full() {
            if (front == 0 && rear == MAX_SIZE - 1) {
                return true;
            }
            if (front == rear + 1) {
                return true;
            }
            return false;
        }
        void enqueue(int a) {
            if (empty())
            {
                front =0;
                rear = 0;
                _queue[rear]= a;
            }
            else if (full()) {
                cout << "Queue overflow!..." << endl;	
                return;
            }
            else {
                rear = (rear+1) % MAX_SIZE;
                _queue[rear] = a;
                return;
            }
        }
        int dequeue() {
            if (empty()) {
                cout << "Queue underflow!..." << endl;
                return 0;
            }
            int tmp = _queue[front];
            front = (front+1) % MAX_SIZE;
            return tmp;
        }
        void show() {
            int i=front;
            if(empty())
            {
                cout << "Queue is empty" << endl;
                return;
            }
            while (i<=rear)
            {
                cout << _queue[i] << " ";
                i = (i+1) % MAX_SIZE;
            }
            cout << endl; 
        }
};
int main() {
    Queue q;
    int n, a;
    char tmp;
    cin >> n;
    for (int i=0; i<n;i++)
    {
        cin >> tmp;
        switch (tmp)
        {
            case 'a':
                cin >> a;
                q.enqueue(a);
                i++;
                break;
            case 'b':
                q.dequeue();
                break;
            case 'c':
                q.show();
                break;
        }
    }
}
