#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node(int val)
    {
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

void delete_at_head(Node *&head, Node *&tail)
{
    Node *deleteNode = head;
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        head = NULL;
        tail = NULL;
        delete deleteNode;
        return;
    }
    head->next->prev = NULL;
    head = head->next;
    delete deleteNode;
}

void delete_at_tail(Node *&head, Node *&tail)
{
    Node *deleteNode = tail;
    if (tail == NULL)
        return;
    if (tail->prev == NULL)
    {
        head = NULL;
        tail = NULL;
        delete deleteNode;
        return;
    }
    tail->prev->next = NULL;
    tail = tail->prev;
    delete deleteNode;
}

int size(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void delete_at_position(Node *&head, Node *&tail, int pos)
{
    Node *deleteNode = head;
    int element = size(head);
    if (pos >= element)
    {
        cout << "Invalid position" << endl;
        return;
    }
    if (pos == 0)
    {
        delete_at_head(head, tail);
        return;
    }
    if (pos == element - 1)
    {
        delete_at_tail(head, tail);
        return;
    }
    for (int i = 0; i < pos; i++)
    {
        deleteNode = deleteNode->next;
    }
    deleteNode->prev->next = deleteNode->next;
    deleteNode->next->prev = deleteNode->prev;
    delete deleteNode;
}



void print(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
void print_reverse(Node *tail)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    Node *tail = b;
    print(head);
    delete_at_tail(head, tail);
    print(head);
    delete_at_tail(head, tail);
    print(head);
    delete_at_tail(head, tail);
    print(head);
    insert_at_tail(head, tail, 10);
    insert_at_tail(head, tail, 20);
    insert_at_tail(head, tail, 30);
    insert_at_tail(head, tail, 40);
    insert_at_tail(head, tail, 50);
    print(head);
    delete_at_position(head, tail, 5);
    print(head);
    print_reverse(tail);
    return 0;
}