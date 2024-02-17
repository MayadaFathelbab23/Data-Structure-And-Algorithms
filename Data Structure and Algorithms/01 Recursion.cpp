#include <iostream>

using namespace std;
// EX1 - Factorial
int fact(int n){
    // Base Case (fact(0) = 1)
    if(n == 0)
        return 1;
    int result = n * fact(n - 1);
    return result;
}
// EX2 - Sum of Digits
int sumOfDigits(int num){
    if(num < 10)
        return num;
    int sum = (num % 10) + (sumOfDigits(num / 10));
    return sum;
}
// EX3 - Fibonacci Series
int fib(int index){
    if(index == 0)
        return 0;
    if(index == 1)
        return 1;
    int res = fib(index -1) + fib(index - 2);
    return res; 
}
// EX4 - Count number of digits
int countOfDigits(int num){
    if(num < 10)
        return 1;
    int res = 1 + countOfDigits(num / 10);
    return res;
}
// EX5 - Binary Representation
void binary(int dec){
    if(dec == 0)
        return;
    binary(dec / 2);
    cout << dec % 2 ;
    
}
int main(){
    binary(8);
    return 0;
}