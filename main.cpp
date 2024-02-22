#include "iostream"
#include "./Includes/Log.h"
//#include "./Includes/Date.h"
//#include "./Includes/String.h"

#include "./Includes/Exception.h"
//#include "./Includes/Complex.h"
//#include "./Includes/ComplexString.h"
#include<thread>







int main()
{

    /*Log log{ Log::Level::LevelInfo };
    log.Info("Fine!");
    log.Error("Error!");
    log.Warn("Carefull!" );
 
    log.Warn("Carefull!" );
    log.Info("Fine!");
    log.Error("Error!");
    log.Warn("Carefull!" );
    log.Info("Fine!");
    log.Error("Error!");*/

    Util::Log log("MyLogger", Util::Log::Level::LevelWarning,"dump.log");
    //log.dumpToFile("./logs/dump.log");
    //log.setLogLevel(Level::Debug);
    log.error("Stop!");
    log.warn("Careful!");
    /*log.critical("Dead");
    log.debug("Fine!");*/
    log.info("Info", std::this_thread::get_id());
    log.info("Info", std::this_thread::get_id(), 535, "avxc", 'c');

    return 0;
}


/*

    #include <iostream>
#include <memory>

class Node {
public:
    std::shared_ptr<Node> next;

    Node() {
        std::cout << "Node constructed" << std::endl;
    }

    ~Node() {
        std::cout << "Node destructed" << std::endl;
    }
};

int main() {
    std::shared_ptr<Node> node1 = std::make_shared<Node>();
    std::shared_ptr<Node> node2 = std::make_shared<Node>();

    // Creating a cyclic reference
    node1->next = node2;
    node2->next = node1;

    // Destruction of shared_ptrs doesn't trigger the destructor of Node due to the cyclic reference
    return 0;
}

*/


/*
    #include <iostream>


class Node {
public:
    int data;
    std::unique_ptr<Node> next;

    Node(int data);
};

Node::Node(int data) : data(data), next(nullptr) {}

class LinkedList {
private:
    std::unique_ptr<Node> head;

public:
    LinkedList();

    void insert(int data);
    void display();
    void remove();
};

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::insert(int data) {
    std::unique_ptr<Node> newNode = std::make_unique<Node>(data);

    if (!head) {
        head = std::move(newNode);
    }
    else {
        Node* current = head.get();
        while (current->next) {
            current = current->next.get();
        }
        current->next = std::move(newNode);
    }
}
void LinkedList::remove() {
    Node* current = head.get();
    if (current == nullptr)
    {
        return;
    }
    else if(current->next == nullptr)
    {
        head = nullptr;
        current->data = 0;
    }
    else
    {

        while (current) {

            if (current -> next -> next == nullptr)
            {
                current->next = nullptr;
            }
            current = current->next.get();
        }
    }

}
void LinkedList::display() {
    Node* current = head.get();
    while (current) {
        std::cout << current->data << " ";
        current = current->next.get();
    }
    std::cout << std::endl;
}

int main() {
    //std::unique_ptr<Node> newNode = std::make_unique<Node>();
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