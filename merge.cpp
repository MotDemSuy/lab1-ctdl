#include <iostream>
using namespace std;
struct Node {
    int val;
    Node* next;
    Node(int v = 0) : val(v), next(nullptr) {}
};

void push_back(Node*& head, int v) {
    if (!head) {
        head = new Node(v);
        return;
    }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = new Node(v);
}

Node* readlist1() {
    int n;
    cout << "Nhap so phan tu cua day a:\n";
    if(!(cin >> n)) return nullptr;
    Node* head = nullptr;
    cout << "Nhap cac phan tu cua day a:\n";
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        push_back(head, x);
}
    return head;
}

Node* readlist2() {
    int n;
    cout << "Nhap so phan tu cua day b:\n";
    if(!(cin >> n)) return nullptr;
    Node* head = nullptr;
    cout << "Nhap cac phan tu cua day b:\n";
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        push_back(head, x);
}
    return head;
}

void printlist(Node* head) {
    bool first = true;
    cout << "Merged Sort list:\n";
    for (Node* cur = head; cur; cur = cur->next) {
        if (!first) cout << ' ';
        cout << cur->val;
        first = false;
    }
    cout << '\n';
}

template <class Object>
void swapValues(Object &lhs, Object &rhs) {
    Object tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

Node* mergeTwoSortedList(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    Node* head = nullptr;
    Node* tail = nullptr;
    if (a->val < b->val) {
        head = tail = a;
        a = a->next;
    } else {
        head = tail = b;
        b = b->next;
    }
    while (a && b) {
        if (a->val < b->val) {
            tail->next = a;
            tail = a;
            a = a->next;
        } else {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    if (a) tail->next = a;
    if (b) tail->next = b;
    return head;
}

template <class Item>
void selectionSort(Node* head) {
    for (Node* i = head; i; i = i->next) {
        Node* mn = i;
        for (Node* j = i->next; j; j = j->next) {
            if (j->val < mn->val) mn = j;
        }
        if (mn != i) {
            Item tmp = i->val;
            i->val = mn->val;
            mn->val = tmp;
        }
    }
}


int main() {
Node* a = readlist1();
Node* b = readlist2();
selectionSort<int>(a);
selectionSort<int>(b);
Node* merged = mergeTwoSortedList(a, b);
printlist(merged); 
return 0;
}