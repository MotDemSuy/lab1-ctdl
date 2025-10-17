#include <iostream>
#include <chrono>
#include <random>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v = 0) : val(v), next(nullptr) {}
};

// ===== Thêm vào cuối danh sách =====
void push_back(Node*& head, int v) {
    if (!head) {
        head = new Node(v);
        return;
    }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = new Node(v);
}

// ===== Sinh danh sách ngẫu nhiên =====
Node* randomList(int n, int minVal = 0, int maxVal = 1000) {
    Node* head = nullptr;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(minVal, maxVal);
    for (int i = 0; i < n; ++i)
        push_back(head, dist(gen));
    return head;
}

// ===== In danh sách =====
void printlist(Node* head) {
    for (Node* cur = head; cur; cur = cur->next)
        cout << cur->val << " ";
    cout << "\n";
}

// ===== Merge Sort cho Linked List =====
Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* head = nullptr;
    if (left->val < right->val) {
        head = left;
        left = left->next;
    } else {
        head = right;
        right = right->next;
    }

    Node* tail = head;
    while (left && right) {
        if (left->val < right->val) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }
    tail->next = left ? left : right;
    return head;
}

void splitList(Node* source, Node** frontRef, Node** backRef) {
    Node* fast = source->next;
    Node* slow = source;
    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;
    Node *a, *b;
    splitList(head, &a, &b);
    a = mergeSort(a);
    b = mergeSort(b);
    return merge(a, b);
}

// ===== MAIN =====
int main() {
    int n;
    cout << "Nhap so phan tu trong danh sach: ";
    cin >> n;

    Node* list = randomList(n);

    cout << "\nDanh sach ngau nhien ban dau:\n";
    printlist(list);

    // ---- Merge Sort ----
    auto start = chrono::high_resolution_clock::now();
    list = mergeSort(list);
    auto end = chrono::high_resolution_clock::now();

    auto dur = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "\nDanh sach sau khi sap xep bang Merge Sort:\n";
    printlist(list);
    cout << "Thoi gian Merge Sort: " << dur << " microseconds\n";

    // Giải phóng bộ nhớ
    while (list) {
        Node* tmp = list;
        list = list->next;
        delete tmp;
    }

    return 0;
}
