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
    Elem* result;
    int index;
    Elem* newElem = new Elem(addr, cont, true);
    if(p >= 0 && p < MAXSIZE){ //in case cache is not full
        arr[p] = newElem;
        createPrio(p);
        p++;
        return NULL;
    }
    else if (p = MAXSIZE){ //in case cache is full
        if(addr % 2 == 0){
            index = queuePrio();
            result = arr[index];
            arr[index] = newElem;
            return result;
        }
        else{
            index = stackPrio();
            result = arr[index];
            arr[index] = newElem;
            return result;
        }
    }
    return NULL;
}
// method write: sync = false.
Elem* Cache::write(int addr, Data* cont) {
    for(int i = 0; i < MAXSIZE; i++){
        if(arr[i]->addr == addr) {
            arr[i]->data = cont;
            arr[i]->sync = false;
            return NULL;
        }
    } 
    Elem* result;
    int index;
    Elem* newElem = new Elem(addr, cont, false);
    if(p >= 0 && p < MAXSIZE){ //in case cache is not full
        arr[p] = newElem;
        createPrio(p);
        p++;
        return NULL;
    }
    else if (p = MAXSIZE){ //in case cache is full
        if(addr % 2 == 0){
            index = queuePrio();
            result = arr[index];
            arr[index] = newElem;
            return result;
        }
        else{
            index = stackPrio();
            result = arr[index];
            arr[index] = newElem;
            return result;
        }
    }
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