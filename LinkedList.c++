#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // Constructor Called
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor Called
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};
void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    // Remember ((((Head = temp))) hoga.......
    head = temp;
}
void inserAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtMiddle(Node *&tail, Node *&head, int data, int positon)
{
    if (positon == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < positon - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next = NULL)
    {
        inserAtTail(tail, data);
        return;
    }
    Node *insertNode = new Node(data);
    insertNode->next = temp->next;
    temp->next = insertNode;
}

void deleteNode(Node *&head, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *current = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = current;
            current = current->next;
            cnt++;
        }
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node *node1 = new Node(10);

    // Point node1 as head
    Node *head = node1;
    // Point node1 as tail
    Node *tail = node1;

    insertAtHead(head, 20);
    inserAtTail(tail, 30);
    insertAtMiddle(tail, head, 90, 1);
    print(head);
    cout << "After Deletion : " << endl;
    deleteNode(head, 2);
    print(head);
}
