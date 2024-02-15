#include "iostream"
#include "./Includes/Log.h"
#include "./Includes/Date.h"
#include "./Includes/String.h"
#include "./Includes/Exception.h"
#include "./Includes/Complex.h"
#include "./Includes/ComplexString.h"
#include <complex> 
#include <string> 


using namespace Util;


int main()
{

   /* Log log{ Log::Level::LevelInfo, std::move(Date{1,12,2024}) };
    log.Info("Fine!");
    log.Warn("Carefull!");
    log.Error("Stop!");
    log.ChangeDate(std::move(Date{ 10,10,2024 }));
    log.Info("Fine!");
    log.Warn("Carefull!");
    Log log2{ Log::Level::LevelInfo, std::move(Date{10,11,2024}) };
    log2.Info("Fine!");
    log2.Warn("Carefull!");
    log2.Error("Stop!");
    log.Error("Stop!");*/

   /* String s{ "sourabh" };
    String a{ s };
    a.append(s);
    std::cout << a*/;
    /*std::complex<double> mycomplex(10.0, 2.0);
    cout << mycomplex;*/

    /*Date d1{ 1,12,1023 };
    Date d2{ 1023,1,12 };*/
    try
    {
        //Date d{ 1,13,2033 };
        Complex c1{ 1,2 };
        Complex c2{ 0,0 };

        std::cout << c1 / c2;
    }
    catch (const MyException& e)
    {
        std::cout << e.what();
    }
    /*std::string s{ "3" };
    std::string j{ "3i" };
    std::cout << s.find('i') << "\n";
    std::cout << j.find('i');*/

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