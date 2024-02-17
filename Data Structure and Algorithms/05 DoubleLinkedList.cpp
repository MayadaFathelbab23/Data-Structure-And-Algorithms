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
class DoublelinkedList{
    Node<T> * head , *tail;
    int listSize ;
public:
    DoublelinkedList(){
        head = tail = nullptr;
        listSize = 0;
    }
    ~DoublelinkedList(){
        clear();
    }
    int size(){
        return listSize;
    }
    void insertFront(T val){
//        create node to this value (In Heap)
        Node<T> * node = new Node<T>(val);
        listSize++;
        if(head == nullptr){
            head = tail = node;
        } else{
//        let new node points to first node
            node->next = head;
            head->previous = node;
            head = node;
        }
    }
    void insertBack(T val){
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
    void removeFront(){
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
            head = head->next;
            delete head->previous;
            head->previous = nullptr;
        }
    }
    void removeBack(){
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
    void printList(){
        Node<T> *p = head ;
        while (p != nullptr){
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }
    void inserAt(int idx , T val){
        if(idx > listSize){
            cout << "Out of Bound" << endl;
        } else if(idx == 0){
            insertFront(val);
        } else if(idx == listSize){
            insertBack(val);
        } else{
            //        create node
            Node<T> *node = new Node<T>(val);
            Node<T> *p = head;
            int i = 0;
            while (i < idx){
                p = p->next;
                i++;
            }
            node->previous = p->previous;
            p->previous->next = node;
            node->next = p;
            p->previous = node;
            listSize ++;
        }
    }
    void removeAt(int idx){
        if(idx >= listSize){
            cout << "Out of Bounds";
            return;
        }if(idx == 0){
            removeFront();
        } else if(idx == listSize - 1){
            removeBack();
        } else{
            Node <T> *p = head;
            int i =0 ;
            while (i < idx){
                p = p->next ;
                i++;
            }
            p->previous->next = p->next ;
            p->next->previous = p->previous ;
            delete p;
            listSize--;
        }
    }
    void clear(){
        while (head != nullptr){
            removeFront();
        }
    }
//    Operator Overload - subscript operator
    T& operator[] (int idx){
        if(idx >= listSize || idx < 0){
            cout << "Invalid Index.."<<endl;
        } else{
            Node<T> p = head;
            int i = 0;
            while (i < idx){
                p = p.next;
                i++;
            }
            return p.value;
        }
    }
};
int main() {
    DoublelinkedList<int> a;
    a.insertBack(5);
    a.insertFront(8);
    a.insertBack(3);
    a.insertBack(10);
    a.insertFront(6);
    a.inserAt(2 , 35);
    a.removeAt(1);
    a.printList();
    int x = a.size();
    cout << x << endl;
    return 0;
}
