#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_item(Node* node) {
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    void display_list() {
        Node* currNode = head;
        while (currNode != nullptr) {
            cout << currNode->name << " ";
            currNode = currNode->next;
        }
        cout << endl;
    }

    void delete_value(string name) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->name == name) {
                if (prev == nullptr) { // Deleting head
                    head = curr->next;
                    if (curr == tail) tail = nullptr; // If head was also tail
                } else {
                    prev->next = curr->next;
                    if (curr == tail) tail = prev;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmad");
    Node* node3 = new Node("Alice");

    LinkedList std_list;
    std_list.add_item(node1);
    std_list.add_item(node2);
    std_list.add_item(node3);

    cout << "Before deletion: ";
    std_list.display_list();

    std_list.delete_value("Ahmad");

    cout << "After deletion: ";
    std_list.display_list();
}


/* Expected output: 
Before deletion: Ali Ahmad Alice 
After deletion: Ali Alice
*/ 

