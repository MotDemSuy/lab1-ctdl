#include <iostream>
#include <chrono>
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
    Node* head = nullptr;
    int n, x;

    cout << "Nhap so phan tu: ";
    cin >> n;

    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        append(head, x);
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
