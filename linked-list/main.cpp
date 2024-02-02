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
        Node<_type> * head;
    public:

        LinkedList() {
            head = NULL;
        }
        void insertStart(_type a)
        {
            Node<_type> * newNode =new Node<_type>(a);
            if (head == NULL)
            {
                head = newNode;
            }
            else {
                newNode->next = head;
                head = newNode;
            }
        }
        void insertEnd(_type a)
        {
            Node<_type> * temp = head, *newNode = new Node<_type>(a);
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        int length() {
            int i=0;
            Node<_type> *temp = head;
            while (temp) {
                temp = temp->next;
                i++;
            }
            return i;
        }
        void insertAtN(_type a, int n)
        {
            Node<_type>* temp = head, *newNode = new Node<_type>(a);
            for (int i=0; i<n-1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;

        }
        void traverse() {
            Node<_type> * temp = head;
            while (temp)
            {
                cout << "[" << temp->data << ", " << temp->next << "], ";
                temp = temp->next;
            }
        }
        void search(_type a)
        {
            Node<_type> *temp = head;
            while (temp)
            {
                if (temp->data== a){
                    cout << "Found";
                        break;
                }
                temp = temp->next;
            }
        }
        void reverse() {
            Node<_type> *temp = head, *next=NULL, *prev=NULL;
            while (temp!=NULL) {
                next = temp->next;
                temp->next = prev;
                prev = temp;
                temp = next;
            }
            head = prev;
        }
        
};


int main(){
    LinkedList<int> l = LinkedList<int>(); 
    l.insertStart(10);
    l.insertStart(20);
    l.insertStart(30);
    l.insertStart(40);
    l.insertStart(50);
    l.traverse();
    l.reverse();
    cout << endl;
    l.traverse();
    return 0;
}


/*
 * Insertion:

    Insert at the beginning of the list✅.
    Insert at the end of the list ✅.
    Insert at a specific position in the list ✅.

Deletion:

Delete from the beginning of the list.
Delete from the end of the list.
Delete a specific element from the list.
Delete at a specific position in the list.

Traversal:
    Traverse the entire list and print or process each element ✅.
    
Search:

Search for a specific element in the list.
Update/Modify:

Update the value of a specific element in the list.
Length/Size:

Get the number of elements in the list.
Concatenation:

Combine two linked lists.
Reverse:

Reverse the order of elements in the list.
Detect a Cycle:

Check if there is a cycle in the linked list.
Find Middle Element:

Find the middle element of the list.
Remove Duplicates:

Remove duplicate elements from the list.
Merge Two Sorted Lists:

Merge two sorted linked lists into a single sorted list.
Split:

Split the list into two halves.
Clone:

Create a copy of the linked list.
Circular Linked List Operations:

Insertion, deletion, traversal, etc., specific to circular linked lists.
*/
