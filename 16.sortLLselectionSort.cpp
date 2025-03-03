#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
void insert(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}
void selectionSort(Node *&head, Node *&tail)
{
    Node *first = head;
    while (first->next != NULL)
    {
        Node *second = first->next;
        while (second != NULL)
        {
            if (first->data > second->data)
            {
                swap(first->data, second->data);
            }
            second = second->next;
        }
        first = first->next;
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    int size = 0;
    while (cin >> val && val != -1)
    {
        insert(head, tail, val);
        size++;
    }
    selectionSort(head, tail);
    print(head);
}