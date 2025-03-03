#include <bits/stdc++.h>
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
void printList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
void insertInPos(Node *&head, int pos, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
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
    printList(head);
    int q=7;
    while (q--)
    {
        int pos;
        int v;
        cin >> pos >> v;
        pos++;
        if (pos < 1 || pos > size + 1)
        {
            cout << "Invalid" << endl;
        }
        else if (pos == 1)
        {
            insertAtHead(head, v);
            printList(head);
            size++;
        }
        else
        {
            insertInPos(head, pos, v);
            printList(head);
            size++;
        }
    }
}