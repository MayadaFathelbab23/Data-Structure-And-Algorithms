#include <iostream>
#include "stack"
using namespace std;
template<class T>
class Node{
public:
    T value;
    Node * next;
    Node(T val){
        value = val;
        next = nullptr;
    };
};
template<class T>
class linkedList{
    Node<T> * head;
    int listSize ;
public:
    linkedList(){
        head = nullptr;
        listSize = 0;
    }
    int size(){
        return listSize;
    }
    void insertFront(T val){
//        create node to this value (In Heap)
        Node<T> * node = new Node<T>(val);
//        let new node points to first node
        node->next = head;
        head = node;
        listSize++;
    }
    void insertBack(T val){
        Node<T> *node = new Node<T>(val);
        listSize ++;
//        check if list is empty
        if(head == nullptr){
            head = node ;
        } else{
            Node<T> *p = head ;
            while (p->next != nullptr){
                p = p->next ;
            }
            p->next = node;
        }
    }
    void reverseList() {
        stack<Node<T> *> s ;
        Node<T> * p = head;
        while (p->next != nullptr){
            s.push(p);
            p = p->next;
        }
        head = p;
        while (!s.empty()){
            p->next = s.top();
            s.pop();
            p = p->next;
        }
        p->next = nullptr;

    }

    void printList(){
        Node<T> *p = head ;
        while (p != nullptr){
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }
};
int main() {
    linkedList<int> a;
    a.insertBack(5);
    a.insertFront(8);
    a.insertBack(3);
    a.insertBack(10);
    a.insertFront(6);
    a.printList();
    a.reverseList();
    a.printList();
    int x = a.size();
    cout << x << endl;
    return 0;
}
