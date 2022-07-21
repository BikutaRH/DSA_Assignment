#ifndef CACHE_H
#define CACHE_H

#include "main.h"

class Cache {
        Elem** arr;
        Elem** stack; // stack for LIFO
        Elem** queue; // queue for FIFO
        int p; // number of the element currenly existing in cache
        int top;// top of stack
        int front; //front of queue
        int rear;  // end of queue
	public:
    Cache(int s) {
        arr = new Elem*[s];
        stack = new Elem*[s];
        queue = new Elem*[s];
        top = -1;
        front = 0;
        rear = -1;
        p = 0;
    }
    ~Cache() {
        for(int i = 0; i < MAXSIZE; i++){
            delete[] arr[i];
            delete[] stack[i];
            delete[] queue[i];
        }
        delete[] arr;
        delete[] stack;
        delete[] queue;
    }   
		Data* read(int addr);
		Elem* put(int addr, Data* cont);
		Elem* write(int addr, Data* cont);
		void print();
		void preOrder();
		void inOrder();
    // method for stack
        bool isEmpty(){
            return top == -1 ? true : false;
        } 
        bool isStackFull(){
            return top + 1 == MAXSIZE ? true : false;
        }
        // push an item to stack
        void push(Elem* element){
            if(isStackFull()){
                for(int i = 0; i < top; i++){
                    stack[i] = stack[i+1];
                }
                top++;
                stack[top] = element;
            }
            else{
                top++;
                stack[top] = element;
            }
        }
        // pop an item from stack
        Elem* pop(){
            return stack[top];
            top--;
        }
    // methods for queue
        bool isQueueFull(){
            return rear + 1 == MAXSIZE ? true : false;
        }
        // add an item to queue
        void enqueue(Elem* element){
            if(isQueueFull()){
                for(int i = 0; i < rear; i++){
                    queue[i] = queue[i+1];
                }
                rear++;
                queue[rear] = element;
            }
            else{
                rear++;
                queue[rear] = element;
            }
        }
        // get an item from queue
        Elem* dequeue(){
            rear--;
            return queue[front];
        }

};      
#endif