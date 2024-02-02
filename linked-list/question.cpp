#include <iostream>
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
        int len;
    public:

        LinkedList() {
            head = NULL;
            tail = NULL;
            len = 0;
        }
        void insertEnd(_type a)
        {
            
            Node<_type> *newNode = new Node<_type>(a);
            if (tail == NULL) {
                head = newNode;
                tail = newNode;
                len++;
                return;
            }
            tail->next = newNode;
            tail = newNode;
            len++;
        }
        int length() {
            return len;
        }
        void traverse() {
            Node<_type> * temp = head;
            while (temp)
            {
                cout<<temp->data << " "; 
                temp = temp->next;
            }
        }
        Node<_type>* search(_type a)
        {
            Node<_type> *temp = head;
            while (temp)
            {
                if (temp->data== a){
                    return temp;
                }
                temp = temp->next;
            }
            return NULL;
        }
        void insertInBetween(int n, int a, int b)
        {
            Node<int> * node = search(a);
            if (node == tail ) return;
            if (node && node->next->data == b)
            {
                Node<_type> *tmp = new Node<int>(n);
                tmp->next = node->next;
                node->next = tmp;
            }
        }
};


int main(){
    LinkedList<int> l = LinkedList<int>(); 
    int n=5, tmp, a,b;
    // cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> tmp;
        l.insertEnd(tmp);
    }
    cin >> tmp;
    l.insertEnd(tmp);
    cin >> n;
    cin >> a >> b;
    l.insertInBetween(n, a,b);
    cout << endl;
    l.traverse();
    return 0;
}


