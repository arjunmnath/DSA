
#include <iostream>
#include <stack>
using namespace std;

template <typename type_>
class Node
{

    public:
        type_ data;
        Node<type_> *next;

        Node() {
            data = 0;
            next = NULL;
        }
        Node(type_ a)
        {
            this->data = a;
            this->next = NULL;
        }
};

template <typename _type>
class LinkedList{
    private:
        Node<_type> * head, *tail;
    public:

        LinkedList() {
            head = NULL;
        }
        void insert(_type a)
        {
            Node<_type> * newNode =new Node<_type>(a);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else {
                newNode->next = NULL;
                tail->next = newNode;
                tail = newNode;
            }
        }

        void traverse() {
            Node<_type> * temp = head;
            while (temp)
            {
                cout << "[" << temp->data << ", " << temp->next << "], ";
                temp = temp->next;
            }
        }


        void reverseUsingStack() {
            Node<_type> * temp = head;
            using nodePtr = Node<_type>*;
            stack<nodePtr> s;
            while (temp->next !=NULL) {
                s.push(temp);
                temp = temp->next;
            }
            head = temp;
            while (!s.empty()) {
                temp->next = s.top();
                temp = temp->next;
                s.pop();
            }
            temp->next = NULL;
        }
};


int main() {
    LinkedList<int> l = LinkedList<int>(); 
    int temp;
    while (true) {
        cin >> temp;
        l.insert(temp);
        if(cin.get() == 10) break;
    }
    l.traverse();
    cout << endl;
    l.reverseUsingStack();
    cout << endl;
    l.traverse();
    return 0;
}

