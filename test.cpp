#include <iostream>
using namespace std;
int main(){
    int** arr = new int*[5];
    
    delete[] arr;//1
    
    for(int i=0; i < 5; i++) delete arr[i];//2
    delete[] arr;//2

    return 0;
}