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
int count(Node *temp, int i)
{
    if (temp == NULL)
    {
        return i;
    }
    i++;
    return count(temp->next, i);
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
void print(Node *&head, int size)
{
    if (size % 2 == 0)
    {
        int pos = size / 2;
        Node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        cout << temp->data << " " << temp->next->data << endl;
    }
    else
    {
        int pos = (size / 2) + 1;
        Node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (cin >> val && val != -1)
    {
        insert(head, tail, val);
    }
    int size = count(head, 0);
    print(head, size);
}