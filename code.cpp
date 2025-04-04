#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node
struct Node {
    int data;
    Node* next;
};

// Khởi tạo danh sách liên kết rỗng
void init(Node*& pHead) {
    pHead = nullptr;
}

// Kiểm tra danh sách rỗng
bool isEmpty(Node* pHead) {
    return pHead == nullptr;
}

// Hiển thị danh sách
void ShowList(Node* pHead) {
    Node* p = pHead;
    while (p != nullptr) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

// Thêm phần tử vào đầu danh sách
void InsertFirst(Node*& pHead, int x) {
    Node* p = new Node;
    p->data = x;
    p->next = pHead;
    pHead = p;
}

// Thêm phần tử vào sau một Node
void InsertAfter(Node* q, int x) {
    if (q == nullptr) return;
    Node* p = new Node;
    p->data = x;
    p->next = q->next;
    q->next = p;
}

// Xóa phần tử đầu danh sách
void DeleteFirst(Node*& pHead) {
    if (pHead == nullptr) return;
    Node* p = pHead;
    pHead = pHead->next;
    delete p;
}

// Xóa phần tử sau một Node
void DeleteAfter(Node* q) {
    if (q == nullptr || q->next == nullptr) return;
    Node* p = q->next;
    q->next = p->next;
    delete p;
}

// Tìm kiếm phần tử trong danh sách
Node* Find(Node* pHead, int x) {
    Node* p = pHead;
    while (p != nullptr && p->data != x) {
        p = p->next;
    }
    return p;
}

// Xóa toàn bộ danh sách
void ClearList(Node*& pHead) {
    Node* p;
    while (pHead != nullptr) {
        p = pHead;
        pHead = pHead->next;
        delete p;
    }
}

// Loại bỏ phần tử có giá trị x trong danh sách
void Remove(Node*& pHead, int x) {
    Node* tp = nullptr;
    Node* p = pHead;
    bool found = false;
    while (p != nullptr && !found) {
        if (p->data != x) {
            tp = p;
            p = p->next;
        } else {
            found = true;
        }
    }
    if (found) {
        if (p == pHead) // Loại bỏ phần tử đầu tiên
            pHead = p->next;
        else
            tp->next = p->next;
        delete p;
    }
}

// Sắp xếp danh sách bằng Selection Sort
void SelectionSort(Node*& pHead) {
    for (Node* i = pHead; i != nullptr; i = i->next) {
        Node* minNode = i;
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (j->data < minNode->data) {
                minNode = j;
            }
        }
        swap(i->data, minNode->data);
    }
}

// Hàm main để kiểm tra chương trình
int main() {
    Node* pHead;
    init(pHead);
    InsertFirst(pHead, 5);
    InsertFirst(pHead, 2);
    InsertFirst(pHead, 8);
    InsertFirst(pHead, 1);
    
    cout << "Danh sách ban đầu: ";
    ShowList(pHead);
    
    SelectionSort(pHead);
    cout << "Danh sách sau khi sắp xếp: ";
    ShowList(pHead);
    
    Remove(pHead, 2);
    cout << "Danh sách sau khi xóa phần tử 2: ";
    ShowList(pHead);
    
    ClearList(pHead);
    return 0;
}