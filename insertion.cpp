#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;

struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class InsertionSort{
    public:
        ListNode* insertionSortList(ListNode* head){
            ListNode* dummy=new ListNode(10000);
            while(head){
                ListNode* next = head->next;
                ListNode* temp = dummy;

                while(temp->next && temp->next->val < head->val){
                    temp = temp->next;
                }
                head->next=temp->next;
                temp->next=head;
                head=next;
            }
            return dummy->next;
        }    
};

ListNode* generateRandomList(int n, int minVal = 0, int maxVal = 1000) {
    srand(time(nullptr));
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int val = minVal + rand() % (maxVal - minVal + 1);
        ListNode* node = new ListNode(val);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

/*void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
*/
void freeList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    int n = 10000; 
    ListNode* head = generateRandomList(n, 0, 10000);

/*  cout << "Danh sach ban dau: ";
    printList(head);
*/
    InsertionSort sorter;

    auto start = chrono::high_resolution_clock::now();
    ListNode* sorted = sorter.insertionSortList(head);
    auto end = chrono::high_resolution_clock::now();
/*
    cout << "Danh sach sau khi sap xep: ";
    printList(sorted);
*/
    chrono::duration<double, milli> duration = end - start;
    cout << "Thoi gian thuc hien: " << duration.count() << " ms" << endl;

    freeList(sorted);
    return 0;
}