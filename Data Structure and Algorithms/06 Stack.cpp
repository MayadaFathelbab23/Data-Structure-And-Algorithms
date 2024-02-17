#include <iostream>
using namespace std;
template<class T>
class Node{
public:
    T value;
    Node * next , *previous;
    Node(T val){
        value = val;
        next = previous = nullptr;
    };
};
template<class T>
class Stack{
    Node<T> * head , *tail;
    int listSize ;
public:
    Stack(){
        head = tail = nullptr;
        listSize = 0;
    }
    ~Stack(){
        clear();
    }
    int size(){
        return listSize;
    }
    void insertTop(T val){
        Node<T> *node = new Node<T>(val);
        listSize ++;
//        check if list is empty
        if(head == nullptr){
            head = tail = node ;
        } else{
            tail->next = node ;
            node->previous = tail ;
            tail = node;
        }
    }
    void removeTop(){
//        1- empty list
        if(head == nullptr){
            cout<<"Empty List..";
            return;
        }
        listSize--;
//        one element
        if(head->next == nullptr){
            delete head;
            head = tail = nullptr;
        } else{
//        more than one element
            tail = tail->previous;
            delete tail->next;
            tail->next = nullptr;
        }
    }
    T top(){
        if(head != nullptr){
            return tail->value;
        } else{
            cout << 'Stack is empty' ;

        }
    }
    void clear(){
        while (head != nullptr){
            removeTop();
        }
    }
    bool isEmpty(){
        if(head == nullptr){
            return true;
        } else{
            return false;
        }
    }

};
int main() {
    Stack <int> s;
    s.insertTop(10);
    s.insertTop(15);
    s.insertTop(3);
    s.insertTop(22);
    s.insertTop(50);
    cout << s.top();

    return 0;
}
