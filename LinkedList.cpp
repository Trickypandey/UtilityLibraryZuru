/*#include <iostream>
#include <memory>

class Node {
public:
    int data;
    std::shared_ptr<Node> next; 

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    std::shared_ptr<Node> head; 

public:
    LinkedList() : head(nullptr) {}

    void insert(int data);
    void display();
    void remove();
};

void LinkedList::insert(int data) {
    std::shared_ptr<Node> newNode = std::make_shared<Node>(data); 

    if (!head) {
        head = newNode;
    }
    else {
        std::shared_ptr<Node> current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::remove() {
    if (!head) {
        return;
    }
    else if (head->next == nullptr) {
        head = nullptr;
    }
    else {
        std::weak_ptr<Node> current = head;
        std::weak_ptr<Node> nextNode = head->next;
        while (nextNode.lock() == nullptr) {
            current = nextNode;
            nextNode = nextNode.lock()->next;
        }
        current.lock()->next = nullptr;
    }
}

void LinkedList::display() {
    std::shared_ptr<Node> current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.display();

    std::cout << "\n";
    list.remove();
    list.remove();
    list.remove();
    list.remove();
    list.display();

    return 0;
}
*/

