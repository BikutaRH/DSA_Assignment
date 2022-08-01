#include "main.h"
// implement method read(): 
Data* Cache::read(int addr) {
    bool exist = false; // check address exist in cache
    int index = 0; // index of element containing this address.
    if(p == 0) return NULL;
    else{
        for (int i = 0; i < p; i++){
            if(arr[i]->addr == addr){
                exist = true;
                index = i;
               break;
            }
        }
        if(exist) return arr[index]->data;
        else return NULL;
    }
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
    else if (p == MAXSIZE){ //in case cache is full
        if(addr % 2 == 0){
            index = queuePrio();
            result = arr[index];
            arr[index] = newElem;
            p = MAXSIZE + 1;
            return result;
        }
        else{
            index = stackPrio();
            result = arr[index];
            arr[index] = newElem;
            p = MAXSIZE + 1;
            return result;
        }
    }
    return NULL;
}
// method write: sync = false.
Elem* Cache::write(int addr, Data* cont) {
    if(p <= MAXSIZE){
        for(int i = 0; i < p; i++){
            if(arr[i]->addr == addr) {
                arr[i]->data = cont;
                arr[i]->sync = false;
                return NULL;
            }
        } 
    }else{
        for(int i = 0; i < MAXSIZE; i++){
            if(arr[i]->addr == addr) {
                arr[i]->data = cont;
                arr[i]->sync = false;
                return NULL;
            }
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
    else if (p == MAXSIZE){ //in case cache is full
        if(addr % 2 == 0){
            index = queuePrio();
            result = arr[index];
            arr[index] = newElem;
            p = MAXSIZE + 1;
            return result;
        }
        else{
            index = stackPrio();
            result = arr[index];
            arr[index] = newElem;
            p = MAXSIZE + 1;
            return result;
        }
    }
    return NULL;
}
void Cache::print() {
    if(p == 0) return;
    else if(p > 0 && p <= MAXSIZE){
        for(int i = p - 1; i >= 0; i--){
            arr[i]->print();
        } 
    }
    else if(p == MAXSIZE + 1){
        sort();
        for(int i = 0; i < MAXSIZE; i++){
            arr[indexSort[i]]->print();
        }
    }
}

void Cache::preOrder() {
    BST* temp = new BST();
    if(p == 0) return;
    else if(p > 0 && p <= MAXSIZE){
        for(int i = 0; i < p; i++){
            temp->insert(arr[i]->addr, arr[i]->data, arr[i]->sync,i,temp->root);    
        }
    }
    else if(p == MAXSIZE + 1){
        sort();
        int temp_index = 0;
        int temp_addr = 0;
        Data* temp_data = NULL;
        bool temp_sync = true;
        for(int i = MAXSIZE - 1; i>=0; i--){
            temp_index = indexSort[i];
            temp_addr = arr[temp_index]->addr;
            temp_data = arr[temp_index]->data;
            temp_sync = arr[temp_index]->sync;
            temp->insert(temp_addr, temp_data, temp_sync, temp_index,temp->root);
        }
    }
    // print preorder
    temp->printPreOder(temp->root);
    delete temp;
}
void Cache::inOrder() {
    BST* temp = new BST();
    if(p == 0) return;
    else if(p > 0 && p <= MAXSIZE){
        for(int i = 0; i < p; i++){
            temp->insert(arr[i]->addr, arr[i]->data, arr[i]->sync,i,temp->root);    
        }
    }
    else if(p == MAXSIZE + 1){
        sort();
        int temp_index = 0;
        int temp_addr = 0;
        Data* temp_data = NULL;
        bool temp_sync = true;
        for(int i = MAXSIZE - 1; i>=0; i--){
            temp_index = indexSort[i];
            temp_addr = arr[temp_index]->addr;
            temp_data = arr[temp_index]->data;
            temp_sync = arr[temp_index]->sync;
            temp->insert(temp_addr, temp_data, temp_sync, temp_index,temp->root);
        }
    }
    temp->printInOder(temp->root);
    delete temp;
}