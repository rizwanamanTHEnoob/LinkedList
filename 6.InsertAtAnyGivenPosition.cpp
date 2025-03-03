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
void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertAtPosition(Node *&head, int val, int pos)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    for (int i = 1; i < pos-1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int main()
{
    Node *head = new Node(5);
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    int pos;
    cin >> pos;
    insertAtPosition(head, 25, 3);

    print(head);
}
