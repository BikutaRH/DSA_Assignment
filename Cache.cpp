#include "main.h"
// implement read(): 
Data* Cache::read(int addr) {
    bool exist = false; // check address exist in cache
    int index = 0; // index of element containing this address.
    for (int i = 0; i < MAXSIZE; i++){
        if(arr[i]->addr == addr){
            exist = true;
            index = i;
            break;
        }
    }
    if(exist) return arr[index]->data;
    else return NULL;
}
Elem* Cache::put(int addr, Data* cont) {
    if(p >= 0 && p < MAXSIZE){
        arr[p]->addr = addr;
        arr[p]->data = cont;
        arr[p]->sync = true;
        p++;
        return NULL;
    }
    else if (p = MAXSIZE){
        if(addr % 2 == 0){
            Elem* temp = new Elem(arr[0]->addr, arr[0]->data, arr[0]->sync);
            arr[0]->addr = addr;
            arr[0]->data = cont;
            arr[0]->sync = false;
            return temp; 
        }
    }
    cout << "2" << endl;
    return NULL;
}
// test github
Elem* Cache::write(int addr, Data* cont) {
    cout << "3" << endl;
    return NULL;
}
void Cache::print() {
	for (int i = 0; i < p; i++)
        arr[i]->print();
}
void Cache::preOrder() {
	for (int i = 0; i < p; i++)
        arr[i]->print();
}
void Cache::inOrder() {
    for (int i = 0; i < p; i++)
        arr[i]->print();
}