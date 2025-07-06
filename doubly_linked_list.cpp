#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node* prev;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_item(Node* node) {
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void display_forward() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->name << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void display_backward() {
        Node* curr = tail;
        while (curr != nullptr) {
            cout << curr->name << " ";
            curr = curr->prev;
        }
        cout << endl;
    }

    void delete_value(string name) {
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->name == name) {
                if (curr == head) {
                    head = curr->next;
                    if (head != nullptr) head->prev = nullptr;
                    if (curr == tail) tail = nullptr;
                } else if (curr == tail) {
                    tail = curr->prev;
                    tail->next = nullptr;
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }
                delete curr;
                return;
            }
            curr = curr->next;
        }
    }
};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmad");
    Node* node3 = new Node("Alice");

    DoublyLinkedList std_list;
    std_list.add_item(node1);
    std_list.add_item(node2);
    std_list.add_item(node3);

    cout << "Forward before deletion: ";
    std_list.display_forward();

    cout << "Backward before deletion: ";
    std_list.display_backward();

    std_list.delete_value("Ahmad");

    cout << "Forward after deletion: ";
    std_list.display_forward();

    cout << "Backward after deletion: ";
    std_list.display_backward();

    return 0;
}

/* Expected output: 
Forward before deletion: Ali Ahmad Alice 
Backward before deletion: Alice Ahmad Ali 
Forward after deletion: Ali Alice 
Backward after deletion: Alice Ali 
*/ 
