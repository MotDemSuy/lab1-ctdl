#include <iostream>
#include <chrono>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
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

// ===== In danh sách =====
void printList(Node* head) {
    bool first = true;
    for (Node* cur = head; cur; cur = cur->next) {
        if (!first) cout << ' ';
        cout << cur->val;
        first = false;
    }
    cout << '\n';
}

// ===== Hàm tạo danh sách ngẫu nhiên =====
Node* randomList(int n) {
    Node* head = nullptr;
    srand(time(0)); // Seed ngẫu nhiên theo thời gian hiện tại
    for (int i = 0; i < n; ++i) {
        int x = rand() % 999999; // Sinh số ngẫu nhiên trong [0, 999]
        push_back(head, x);
    }
    return head;
}

// ===== Hoán đổi giá trị =====
template <class Object>
void swapValues(Object &lhs, Object &rhs) {
    Object tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

// ===== Selection Sort trên danh sách liên kết =====
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

// ===== MAIN =====
int main() {
  

    int n;
    cout << "Nhap so phan tu muon tao: ";
    cin >> n;

    // Tạo danh sách ngẫu nhiên
    Node* head = randomList(n);
    cout << "Danh sach ngau nhien vua tao:\n";
    printList(head);

    // Đo thời gian chạy selection sort
    auto t0 = chrono::high_resolution_clock::now();
    selectionSort<int>(head);
    auto t1 = chrono::high_resolution_clock::now();

    // Tính thời gian chạy
    auto dur_us = chrono::duration_cast<chrono::microseconds>(t1 - t0).count();
    double dur_ms = dur_us / 1000.0;

    cout << "\nDanh sach sau khi sap xep:\n";
    printList(head);
    cout << "Elapsed time: " << dur_us << " microseconds (" << dur_ms << " ms)\n";

    // Giải phóng bộ nhớ
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}
