#include <iostream>

using namespace std;

int main(){
    int *p = new int[4];
    for(int i =0 ; i < 3 ; i++){
        cin >> p[i];
    }
    cout << p <<endl; // print address of first element in arrary
    cout << *p << " = " << p[0]<< endl;
    delete []  p;
    // 2D - Dynamic Array
    // create pointer points to array of pointers
    int* *a = new int* [5];
    for (int j =0 ; j < 5 ; j ++){
        a[j] = new int [3] ;
    }
    // Access 2D array
    for(int i = 0 ; i < 5 ; i++){
        for (int j = 0 ; j < 3 ; j++){
            cin >> a[i][j];
        }
    }

    // Delete 2D Array
    for (int i =0  ; i < 5 ; i++){
        delete[] a[i];
    }
    delete[] a;
    return 0;
}