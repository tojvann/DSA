#include<iostream>
#include "Node.cpp"

class List{
    public:
    //Constructor
    List(){
        headNode = new Node();
        headNode->setNext(NULL);
        currentNode = NULL;
        size = 0;
    }
    void add( int addObject){
        Node* newNode = new Node();
        newNode -> set(addObject);
        if(currentNode != NULL)
        {
            newNode -> setNext(currentNode -> getNext());
            currentNode->setNext(newNode);
            lastCurrentNode = currentNode; //Useful for back() operation
            currentNode= newNode;
        }
        else // in case the newNode which is to be added is the first node
        {
            newNode -> setNext(NULL);
            headNode -> setNext(newNode);
            lastCurrentNode = headNode;
            currentNode = newNode;
            }
        size++;
    } ;
    int get() {
        if(currentNode != NULL)
        return currentNode-> get(); // it is calling the get method of the Node class
        };
    bool next() {
        if(currentNode == NULL)
            return false;
        lastCurrentNode = currentNode;
        currentNode  = currentNode -> getNext();
        if(currentNode == NULL || size == 0)  // not sure why we are checking for size == 0
            return false;
        else
            return true; 
    };
    void start(){
        lastCurrentNode = headNode;
        currentNode = headNode;
    };
    void remove() {
        if(currentNode != NULL && currentNode != headNode){
            lastCurrentNode->setNext(currentNode->getNext());
            delete currentNode;
            currentNode = lastCurrentNode->getNext();
            size--;
        }
    };
    int length(){
        return size;
    };
    private:
        int size;
        Node* headNode;
        Node* currentNode;
        Node* lastCurrentNode;
    
};