#include "main.h"
// implement method read(): 
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
// implement method put(): put the address and the value of that address to cache from memory. So sync will be true.
Elem* Cache::put(int addr, Data* cont) {
    Elem* newElem = new Elem(addr, cont, true);
    if(p >= 0 && p < MAXSIZE){ //in case cache is not full
        arr[p] = newElem;
        stack[p] = newElem;
        queue[p] = newElem;
        p++;
        return NULL;
    }
    else if (p = MAXSIZE){ //in cace cache is full
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