#include <iostream>
using namespace std;
// SElection Sorting
void SelectionSort(int arr[] , int n){
    for(int i =0 ; i < n -2 ; i++){
        int mn = arr[i];
        int idx = i;
        for(int j = i+ 1 ; j < n  ; j++){
            if(arr[j] < mn){
                mn = arr[j];
                idx = j;
            }
        }
        // swap
        swap(arr[i] , arr[idx]);
    }
}
// Insertion sort
void insertionSort(int arr[] , int siz){
    for(int i = 1 ; i < siz ; i++){
        int val = arr[i];
        int j;
        for(j = i ; j > 0 && arr[j -1] > val; j--){
            arr[j] = arr[j -1];
        }
        arr[j] = val;
    }
}
// bubble sort
void bubbleSort(int arr[] , int n){
    for(int i = 0 ; i < n -1 ; i++){
        for(int j  = 1 ; j <= n -1 - i ; j ++){
            if(arr[j -1] > arr[j]){
                swap(arr[j] , arr[j - 1]);
            }
        }
    }
}
// Counting Sort
void countSort(int arr[] , int n){
    // Crete Freq array - size
    int mx = arr[0];
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > mx){
            mx = arr[i];
        }
    }
    int *freq = new int[mx + 1]{0};
    for(int i =  0 ; i< n ; i++){
        freq[arr[i]]++;
    }
    // creat sorted arr
    int j = 0;
    for(int i =0 ; i <= mx ; i++){
        while (freq[i] > 0)
        {
            arr[j] = i;
            freq[i]--;
            j++;
        }
    }
    delete [] freq;
}
int main(){
    int arr[6] = {4 , 5 , 7 , 2, 8 ,0};
    // SelectionSort(arr , 6);
    // insertionSort(arr , 6);
    // bubbleSort(arr , 6);
    countSort(arr , 6);
    for(int i =0 ; i < 6 ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}