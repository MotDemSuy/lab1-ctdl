#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v = 0) : val(v), next(nullptr) {}
};

// Them vao cuoi danh sach
void push_back(Node*& head, int v) {
    if (!head) {
        head = new Node(v);
        return;
    }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = new Node(v);
}

// In danh sach
void printList(Node* head) {
    bool first = true;
    cout << "Selection Sorted list:\n";
    for (Node* cur = head; cur; cur = cur->next) {
        if (!first) cout << ' ';
        cout << cur->val;
        first = false;
    }
    cout << '\n';
}

// Đọc danh sách: định dạng input: n a1 a2 ... an
Node* readList() {
    int n;
    cout << "Nhap so phan tu:\n";
    if (!(cin >> n)) return nullptr;
    Node* head = nullptr;
    cout << "Nhap cac phan tu:\n";
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        push_back(head, x);
    }
    return head;
}

// Hoan doi gia tri
template <class Object>
void swapValues(Object &lhs, Object &rhs) {
    Object tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

// Selection sort dua tren danh sach lien ket
template <class Item>
void selectionSort(Node* head) {
    for (Node* i = head; i; i = i->next) {
        Node* mn = i;
        for (Node* j = i->next; j; j = j->next) {
            if (j->val < mn->val) mn = j;
        }
        if (mn != i) swapValues<Item>(i->val, mn->val);
    }
}

int main() {
   
    
    // Đọc danh sách
    Node* head = readList();
    if (!head) return 0;

    // Sắp xếp và in danh sách
    selectionSort<int>(head);
    printList(head);

    // Giải phóng bộ nhớ
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    return 0;
}