#include<iostream>

using namespace std; 

// Define Heap constructor 
class heap{

    public: 
    int arr[100]; // array to store heaps
    int size; // size of heap 

    heap(){ 
        arr[0]= -1; /*This ensures 1-based indexing, 
        simplifying heap operations, maintaining 
        correct parent-child calculations, and preventing logical errors.*/
        size=0; // initialising a heap with no elements 
    }

    //INSERTION FUNCTION

    void insert(int val){
        size = size+1; // Increase the heap size
        int index = size; // Set index to the last position
        arr[index]= val; // Place the new value at the last position


        /* we need to Heapify UP
        (Bubble Up process to maintain max-heap property)*/

        while(index>1){ // Continue until we reach the root
            int parent = index/2; // Find parent index

            if(arr[parent]< arr[index]){ // If parent is smaller, swap
                swap(arr[parent],arr[index]);
                index = parent; // Move index to parent and continue
            }

            else{
                return; // If parent is larger, heap property is satisfied
            }
        }
    }
    
    
    // Function to print the heap elements
    void print(){ 
        for(int i=1; i<=size; i++){ // Start from index 1 (heap root)
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};


// Main function to test the heap class
int main(){
    heap h; 

    h.insert(50); 
    h.insert(55); 
    h.insert(35); 
    h.insert(45); 
    h.insert(125); 


    h.print();
    return 0; 
}