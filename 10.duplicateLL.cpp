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
bool containDuplicate(Node *&head)
{
    bool duplicate = false;
    Node *temp = head;
    while (temp != NULL)
    {
        int val = temp->data;
        Node *newTemp = temp->next;
        while (newTemp != NULL)
        {
            int secVal = newTemp->data;
            if (val == secVal)
            {
                duplicate = true;
                break;
            }
            newTemp = newTemp->next;
        }
        temp = temp->next;
    }
    return duplicate;
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
    if (containDuplicate(head))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}