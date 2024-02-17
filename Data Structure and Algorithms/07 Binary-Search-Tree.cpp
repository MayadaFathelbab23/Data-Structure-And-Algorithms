#include <iostream>
#include <queue>
using namespace std;
template<class T>
class Node{
public:
    T value;
    Node *left , *right;
    Node(){
        value = 0;
        left = right = nullptr;
    };
    Node(T val){
        this->value = val;
        left = right = nullptr;
    };
};

template<class T>
class BST{
    Node<T> *root ;
    int TreeSize;
public:
    BST(){
        root = nullptr;
        TreeSize = 0;
    }
    Node<T>* Root(){
        return this->root;
    }
    int size(){
        return TreeSize;
    }
    Node<T> * insert1(Node<T> *r , T val){
//        Base case
        if(r == nullptr){
            Node<T> *newNode = new Node<T>(val);
            r = newNode;
        }
        if(val < r->value){
            r->left = insert1(r->left , val);
        } else if(val > r->value){
            r->right = insert1(r->right , val);
        }
        return r;

    }
    void insert1(T val){
        root = insert1(root , val);
    }
    void insert2(T val){
        if(search(val) == true){
            cout<<"Value already exists"<<endl;
            return;
        }
        TreeSize++;
        Node<T> *node = new Node<T>(val);
        if(root == nullptr){
            root = node;
            return;
        }
        Node<T> *p  = root , *prev = root;
        while (p != nullptr){
            prev = p;
            if(val < p->value){
                p = p->left;
            } else{
                p = p->right;
            }
        }
        if(val < prev->value){
            prev->left = node;
            return;
        } else{
            prev->right = node;
            return;
        }
    }
    Node<T>* Search1(Node<T> *r , T key){
        if(r == nullptr)
            return nullptr;
        else if(r->value == key)
            return r;
        else if(key < r->value)
            return Search1(r->left , key);
        else
            return Search1(r->right , key);
    }
    bool Search1(T key){
        Node<T> * node = Search1(root , key);
        if(node == nullptr)
            return false;
        else
            return true;
    }
    bool search(T val){
        Node<T> *p = root;
        while (p != nullptr){
            if(p->value == val)
                return true;
            else if(val < p->value)
                p = p->left;
            else
                p = p->right;
        }
        return false;
    }
    void BFS(){
        queue<Node<T>*> q;
        q.push(root);
        while (q.empty() == false){
            cout << q.front()->value << " ";
            if(q.front()->left != nullptr){
                q.push(q.front()->left);
            }
            if(q.front()->right != nullptr){
                q.push(q.front()->right);
            }
            q.pop();
        }
    }
    void PreOrder(Node<T> *r){ //root - left - right
        if(r == nullptr)
            return;
        cout << r->value << "   " ;
        PreOrder(r->left);
        PreOrder(r->right);
    }
    void InOrder(Node<T> *r){ //left - root - right
        if(r == nullptr)
            return;
        InOrder(r->left);
        cout << r->value << "   ";
        InOrder(r->right);
    }
    void PostOrder(Node<T> *r){ // left - right - root
        if(r == nullptr)
            return;
        PostOrder(r->left);
        PostOrder(r->right);
        cout << r->value << "   ";
    }
    Node<T> * FindMin(Node<T> *r){
        if(r == nullptr)
            return nullptr;
        else if(r->left == nullptr)
            return r;
        else
            return FindMin(r->left);
    }
    Node<T> * FindMax(Node<T> *r){
        if(r == nullptr)
            return nullptr;
        else if(r->right == nullptr)
            return r;
        else
            return FindMax(r->right);
    }
    Node<T> * Delete(Node<T> *r , T key){
        if(r == nullptr) //Empty Tree
            return nullptr;
        else if(key < r->value) //Item in the left side of tree
            r->left = Delete(r->left , key);
        else if(key > r->value) // item in the right side of tree
            r->right = Delete(r->right , key);
        else{ // we found item (key = value)
//            if item is leaf node
            if(r->left == nullptr && r->right == nullptr)
                r = nullptr;
//            item has one left child
            else if(r->left != nullptr && r->right == nullptr){
                r->value = r->left->value;
                delete r->left;
                r->left = nullptr;
            }
//            item has one right child
            else if(r->right != nullptr && r->left == nullptr){
                r->value = r->right->value;
                delete r->right;
                r->right = nullptr;
            }
//            item hase 2 childs
            else{
                Node<T> *successor = FindMin(r->right);
                r->value = successor->value;
               r->right = Delete(r->right , successor->value);
            }

        }
        return r;
    }
};
int main() {
    cout << "Hello, World!" << endl;
    BST<int> tree ;
    tree.insert1(45);
    tree.insert1(15);
    tree.insert1(79);
    tree.insert1(90);
    tree.insert1(10);
    tree.insert1(55);
    tree.insert1(12);
    tree.insert1(20);
    tree.insert1(50);
    cout << tree.search(40)<<endl;
    tree.BFS();
    cout << endl;
    tree.PreOrder(tree.Root());
    cout << endl;
    cout << "Search Result.. " << tree.Search1(100)<<endl;
    cout<< "Min value  "<<tree.FindMin(tree.Root())->value << " Max Value  "<<tree.FindMax(tree.Root())->value<<endl;
    cout << "Tree after deleting .."<<endl;
    Node<int> *newTree = tree.Delete(tree.Root() , 10);
    tree.PreOrder(newTree);
    return 0;
}
