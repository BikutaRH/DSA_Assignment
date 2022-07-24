#ifndef CACHE_H
#define CACHE_H

#include "main.h"

class Cache {
        Elem** arr;
        int priority[MAXSIZE];
        int indexSort[MAXSIZE];
        int maxLive; // time of element live longest
        int p; // number of the element currenly existing in cache
	public:
    Cache(int s) {
        arr = new Elem*[s];
        p = 0;
    }
    ~Cache() {
        for(int i = 0; i < MAXSIZE; i++){
            delete[] arr[i];
        }
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
};

class BST{
private: 
    class Node; // forward declare
    Node* root;
    int count;

    Node* insert(Elem* element, Node* bst){
        if(bst == NULL){
            bst = new Node(element, NULL, NULL);
        }
        else if( element->addr < bst->element->addr){
            bst->left = insert(element, bst->left);
        }
        else if(element->addr > bst->element->addr){
            bst->right = insert(element, bst->right);
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
    
    Node* findMin(Node* bst){
        if(bst == NULL) return NULL;
        else if(bst->left == NULL) return bst;
        else return findMin(bst->left);
    }   

    Node* findMax(Node* bst) {
        if(bst == NULL) return NULL;
        else if(bst->right == NULL) return bst;
        else return findMax(bst->right);
    }

    Node* remove(Elem* element, Node* bst) {
        Node* temp;
        if(bst == NULL) return NULL;
        else if(element->addr < bst->element->addr) bst->left = remove(element, bst->left);
        else if(element->addr > bst->element->addr) bst->right = remove(element, bst->right);
        else if(bst->left && bst->right){
            temp = findMin(bst->right);
            bst->element->addr = temp->element->addr;
            bst->right = remove(bst->element, bst->right);
        }
        else
        {
            temp = bst;
            if(bst->left == NULL)
                bst = bst->right;
            else if(bst->right == NULL)
                bst = bst->left;
            delete temp;
        }

        return bst;
    }
public:
    class Node{
    public:
        Elem* element;
        Node* left;
        Node* right;
    public:
        Node(){
            left = NULL;
            right = NULL;
        }
        Node(Node* left, Node* right){
            this->left = left;
            this->right = right;
        }
        Node(Elem* elem, Node* left, Node* right){
            element = elem;
            this->left = left;
            this->right = right;
        }
    };
    BST(){
        root = NULL;
    }
    ~BST(){
        root = makeEmpty(root);
    }
    void insert(Elem* element) {
        root = insert(element, root);
    }

    void remove(Elem* element) {
        root = remove(Elem* element, root);
    }

};  
#endif