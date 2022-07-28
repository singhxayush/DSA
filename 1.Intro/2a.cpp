// use of pointers for dynamic memory allocation

#include<iostream>
using namespace std;

int main(){
    int *p; //-> mem allocated in heap
    p = new int[5];
    p = NULL;
    delete []p;
}