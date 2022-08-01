#ifndef CACHE_H
#define CACHE_H

#include "main.h"

class Cache {
public:
        Elem** arr;
        int priority[MAXSIZE];// priority of time living: 0 == longest; maxsize - 1: shortest
        int indexSort[MAXSIZE];// sort of index element from logest  
        int maxLive; // time of element live shortest to longest
        int p; // number of the element currenly existing in cache
        class BST; // forward declare
public:
    Cache(int s) {
        arr = new Elem*[s];
        p = 0;
    }
    ~Cache() {
        delete[] arr;
    }   
		Data* read(int addr);
		Elem* put(int addr, Data* cont);
		Elem* write(int addr, Data* cont);
		void print();
		void preOrder();
		void inOrder();
    // method for stack
        // create an array to store index of priority in arr
        void createPrio(int p){
            priority[p] = p;
        }
        int stackPrio(){
            for(int i = 0; i < MAXSIZE; i++){
                if (priority[i] == MAXSIZE - 1) return i;
            }
            return 0;
        }
        int queuePrio(){
            int index = 0;
            for(int i = 0; i < MAXSIZE; i++){
                priority[i]--;
                if(priority[i] == -1){
                    index = i;
                    priority[i] = MAXSIZE - 1;
                }
            }
            return index;
        }
        // sort priority 
        void sort(){
            maxLive = MAXSIZE - 1; 
            for(int i = 0; i < MAXSIZE; i++){
                for(int j = 0; j < MAXSIZE; j++){
                    if(priority[j] == maxLive) indexSort[i] = j; 
                }
                maxLive--;
            }
        }
    class BST{
    public:
        class Node; // forward declare
        Node* root;
        Node* insert(int addr, Data* data, bool sync, int index, Node*& bst){
            if(bst == NULL){
                bst = new Node(addr,data, sync,index, NULL, NULL);
                // cout << bst->addr;
            }
            else if( addr < bst->addr){
                bst->left = insert(addr, data, sync, index, bst->left);
            }
            else if(addr > bst->addr){
                bst->right = insert(addr, data, sync, index, bst->right);
            }
            return bst; 
        }

        Node* makeEmpty(Node* bst){
            if(bst == NULL) return NULL;
            else{
                makeEmpty(bst->left);
                makeEmpty(bst->right);
                delete bst;
            }
            return NULL;
        }

        void printPreOder(Node*& bst){
            if(bst == NULL){
                // cout << "Rong";
                return;
            }
            cout << bst->addr << " " << bst->data->getValue() << " " << (bst->sync?"true":"false") << endl;
            printPreOder(bst->left);
            printPreOder(bst->right);
        }

        void printInOder(Node*& bst){
            if(bst == NULL){
                // cout << "rong";
                return;
            } 
            printInOder(bst->left);
            cout << bst->addr << " " << bst->data->getValue() << " " << (bst->sync?"true":"false") << endl;
            printInOder(bst->right);
        }
    class Node{
        public:
            int addr;
            Data* data;
            bool sync;
            int index;
            Node* left;
            Node* right;
        public:
            Node(){
                addr = 0;
                data = NULL;
                sync = true;
                index = 0;
                left = NULL;
                right = NULL;
            }
            Node(int addr, Data* data, bool sync, int index, Node* left, Node* right){
                this->addr = addr;
                this->data =  data;
                this->sync = sync;
                this->index = index;
                this->left = left;
                this->right = right;
            }
            ~Node(){};
        };         
        BST(){
            root = NULL;
        }
        ~BST(){
            root = makeEmpty(root);
        }
    };  
};

#endif