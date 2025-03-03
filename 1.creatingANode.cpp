#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
int main()
{
    Node a(10), b(20), c(30);
    a.next = &b;
    b.next = &c;
    cout << a.data << endl;
    cout << a.next->data << endl;
    cout << a.next->next->data << endl;
}