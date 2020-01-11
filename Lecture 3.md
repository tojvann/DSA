### Lecture 3

## Linked List: Actual picture in memory

![](https://imgur.com/D0G7o3x.png)

## Linked Lists Operations

- __add(9)__: Create a new node in memory to hold '9'.

- ```c++
  Node* newNode = new Node(9);
  
  /* Make an object of class Node. Call its constructor by passing '9' as a parameter.
  Now a memory address will be returned which holds the starting address of the created node which is assigned to the pointer newNode.
  */
  
  // same procedure was used in order to create a dynamic array
  ```

  

- ![](https://imgur.com/XpCyJkn.png)

- Link the new node into the list.

- ![](https://imgur.com/9elGVjT.png)

  - 1. store the address of node containing '7' in the next field of the newNode.
    2. point the next field of the current pointer to newNode.
    3. move the current pointer to now point to the newNode.

- ```c++
  // Node.cpp
  // C++ Code for Linked List
  class Node{
  public: 
  	int get(){
  	return object;
  	};
  	void set(int object){
  	this->object = object;
  	};
  	Node* getNext(){
  		return nextNode;
  	};
  	void setNext(Node* nextNode){
  		this->nextNode = nextNode;
  	};
  private:
  	int object;
  	Node* nextNode;
  }
  ```

- ```c++
  #include <stdlib.h>
  #include "Node.cpp"
  
  class List{
      public:
      // Constructor
      List(){
          headNode = new Node();
          headNode->setNext(NULL);
          currentNode = NULL;
          size = 0;
      }
      void add(int addObject) {
          Node* newNode = new Node();
          newNode -> set(addObject) ;
          if( currentNode != NULL )
          {
              newNode -> setNext(currentNode -> getNext());
              currentNode -> setNext(newNode);
              lastCurrentNode = currentNode;  //Useful for back() operation
              currentNode = newNode;
          }
          else //in case the newNode to be added is the first node
          {
              newNode -> setNext(NULL);
              headNode -> setNext(newNode);  //Note: the headNode is not just a pointer 													 variable it is a node itself
              lastCurrentnode = headNode;
              currentNode = newNode;
          }
          size++;
      } ;
      int get() {
          if(currentNode != NULL)
              return currentNode-> get();  //Note: it is calling the get() methjod of 												 class node 
      };
      bool next() {
          if(currentNode == NULL)
              return false;
          lastcurrentNode = currentNode;
          currentNode = currentNode->getNext();
          if (currentNode == NULL || size == 0)
              return false;
          else
              return true;
      }
      
  }
  ```

![](https://imgur.com/tuJQOCR.png)

![](https://imgur.com/r1nVbb0.png)

![](https://imgur.com/QxilxpF.png)

![](https://imgur.com/MUBisjJ.png)



