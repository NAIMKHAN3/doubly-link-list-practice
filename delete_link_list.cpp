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
    if (tail == NULL) return;
    if(tail->prev == NULL){
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
    return 0;
}