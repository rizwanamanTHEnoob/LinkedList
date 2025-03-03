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
bool isSorted(Node *&head)
{
    bool sorted = true;
    Node *temp = head;
    int initialValue = temp->data;
    temp = temp->next;
    while (temp != NULL)
    {
        if (initialValue > temp->data)
        {
            sorted = false;
            break;
        }
        initialValue = temp->data;
        temp = temp->next;
    }
    return sorted;
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
    if (isSorted(head))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}