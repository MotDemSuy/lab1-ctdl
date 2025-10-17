#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void bubbleSort(Node* head) {
    if (!head) return;
    bool swapped;
    Node* ptr1;
    Node* last = nullptr;

    do {
        swapped = false;
        ptr1 = head;
        while (ptr1->next != last) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        last = ptr1;
    } while (swapped);
}

int main() {
    srand(time(0)); // khởi tạo seed ngẫu nhiên
    Node* head = nullptr;
    int n, x, choice;

    cout << "Nhap so phan tu: ";
    cin >> n;

    cout << "Ban muon:\n";
    cout << "1. Tu nhap cac phan tu\n";
    cout << "2. Tao ngau nhien cac phan tu\n";
    cout << "Lua chon: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Nhap cac phan tu: ";
        for (int i = 0; i < n; i++) {
            cin >> x;
            append(head, x);
        }
    } 
    else if (choice == 2) {
        for (int i = 0; i < n; i++) {
            int randomValue = rand() % 1000; // tạo số ngẫu nhiên 0–999
            append(head, randomValue);
        }
        cout << "Danh sach ngau nhien: ";
        printList(head);
    } 
    else {
        cout << "Lua chon khong hop le.\n";
        return 0;
    }

    auto start = high_resolution_clock::now();
    bubbleSort(head);
    auto end = high_resolution_clock::now();

    cout << "Danh sach sau khi sap xep: ";
    printList(head);

    auto duration = duration_cast<microseconds>(end - start);
    cout << "Thoi gian thuc hien: " << duration.count() << " microseconds" << endl;

    return 0;
}
