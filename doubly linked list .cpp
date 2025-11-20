// Doubly Linked List (core structure and menu)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node* insert(Node* head, int data, int pos) {
    Node* n = new Node{data, nullptr, nullptr};
    if (!head || pos == 1) { // Insert at head
        n->next = head;
        if (head) head->prev = n;
        return n;
    }
    Node* curr = head;
    for (int i = 1; i < pos - 1 && curr->next; i++) curr = curr->next;
    n->next = curr->next;
    n->prev = curr;
    if (curr->next) curr->next->prev = n;
    curr->next = n;
    return head;
}

Node* deleteNode(Node* head, int key) {
    Node* curr = head;
    while (curr && curr->data != key) curr = curr->next;
    if (!curr) return head;
    if (curr->prev) curr->prev->next = curr->next;
    else head = curr->next; // handle head
    if (curr->next) curr->next->prev = curr->prev;
    delete curr;
    return head;
}

bool search(Node* head, int key) {
    for(Node* t=head;t;t=t->next) if (t->data==key) return true;
    return false;
}

void display(Node* head) {
    for(Node* t=head;t;t=t->next) cout<<t->data<<" ";
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int ch, val, pos;
    do {
        cout<<"1.Insert 2.Delete 3.Search 4.Display 5.Exit\n";
        cin>>ch;
        if (ch == 1) {
            cout<<"Value and pos? "; cin>>val>>pos;
            head = insert(head, val, pos);
        } else if (ch == 2) {
            cout<<"Value? "; cin>>val;
            head = deleteNode(head, val);
        } else if (ch == 3) {
            cout<<"Search value? "; cin>>val;
            cout << (search(head, val) ? "Found\n" : "Not found\n");
        } else if (ch == 4) { display(head); }
    } while (ch != 5);
    return 0;
}


// CIRCULAR LINKED LIST
struct CNode {
    int data;
    CNode* next;
};

CNode* insertC(CNode* head, int val) {
    CNode* n = new CNode{val, nullptr};
    if (!head) { n->next = n; return n; }
    CNode* t = head;
    while (t->next != head) t = t->next;
    t->next = n; n->next = head;
    return head;
}

void displayC(CNode* head) {
    if (!head) return;
    CNode* t = head;
    do { cout << t->data << " "; t = t->next; } while (t != head);
    cout << endl;
}

void displayCircularWithHead(CNode* head) {
    if (!head) return;
    CNode* t = head;
    do { cout << t->data << " "; t = t->next; } while (t != head);
    cout << head->data << endl;
}


int sizeDoubly(Node* head) {
    int c=0;
    for(; head; head=head->next) c++;
    return c;
}

int sizeCircular(CNode* head) {
    int c=0;
    if (!head) return 0;
    CNode* t=head; do { c++; t=t->next; } while(t!=head);
    return c;
}

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node *left = head, *right = head;
    while (right->next) right = right->next;
    while (left != right && left->prev != right) {
        if (left->data != right->data) return false;
        left = left->next; right = right->prev;
    }
    return true;
}


