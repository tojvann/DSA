### Lecture 3 and 4

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
              headNode -> setNext(newNode);  //Note: the headNode is not just a pointer variable it is a node itself
              lastCurrentnode = headNode;
              currentNode = newNode;
          }
          size++;
      } ;
      int get() {
          if(currentNode != NULL)
              return currentNode-> get();  //Note: it is calling the get() methjod of class node 
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
      };
      //position current before the first element
      void start() {
          lastCurrentNode = headNode;
          currentNode = headNode;
      };
      void remove() {
          if(currentNode != NULL && currentNode !=headNode){
              lastCurrentNode->setNext = (currentNode->getNext());
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
      Node* currentNode, lastCurrentNode;
      
  }
  ```

### add() :

![](https://imgur.com/tuJQOCR.png)

![](https://imgur.com/r1nVbb0.png)

![](https://imgur.com/QxilxpF.png)

![](https://imgur.com/MUBisjJ.png)

### remove() :

![](https://imgur.com/D8JNg6U.png)



![](https://imgur.com/SxyItM8.png)

![](https://imgur.com/QHtr90P.png)

![](https://imgur.com/NDbemIQ.png)

### Example of List Usage

```c++
#include <iostream>
#include <stdlib.h>
#include "List.cpp"

int main() {
    List list;
    list.add(5);
    list.add(13);
    list.add(4);
    list.add(8);
    list.add(24);
    list.add(48);
    list.add(12);
    list.start();
    while(list.next()) {
        cout<< "List Element: " << list.get() << endl;
    }
}
```



## Analysis of Linked List

- __add()__
  - We simply add a new node after the current node. So add is a one step operation. We don't need to create space in-between in order to accommodate the new element as was the case with array.
- **remove()**
  - remove is also a one-step operation, unlike array we don't need to shift elements to the left in order to fill the space created by the element removal.
- **find()**
  - `Worst-Case`: may have to search the entire list.
- **back()**
  - In case of Singly Linked List, moving the current pointer back one node requires traversing the list from the start until the node whose next pointer points to the current node.





# Doubly Linked List

- Moving forward in a singly linked list is easy but moving backwards is not so easy.

- To move back one node, we have to start at head of the singly link and move forward until the node before the current.

- To avoid this we can use two pointers in a node: one to point to the next node and another to point to the previous node.

  ![](https://imgur.com/5R3vYKY.png)

  ## Doubly linked list node:

  ```c++
  class Node {
    public:
      int get() {
          return object;
      };
      void set(int object) {
          this -> object = object;
      };
      Node* getNext() {
          return nextNode;
      };
      void setNext(Node* nextNode) {
          this -> nextNode = nextNode;
      };
      Node* getPrev() {
          return prevNode;
      };
      void setPrev(Node* prevNode) {
          this -> prevNode = prevNode;
      };
    private:
      int object;
      Node* nextNode;
      Node* prevNode;
  };
  ```



- Need to be more careful when adding or removing node.

- Consider add: the order in which pointers are reorganized is important:

  - Step 1: newNode -> setNext (currentNode -> getNext());
  - ![](https://imgur.com/9Fmzr3r.png)
  - Step 2: newNode -> setPrev(current);
  - ![](https://imgur.com/4DFqTOR.png)
  - Step 3: (current ->getNext()) ->setPrev (newNode);
  - ![](https://imgur.com/J3wUiG7.png)

  - Step 4: current -> setNext (newNode);
  - ![](https://imgur.com/AsjhDVR.png)
  - Step 5: current = newNode;
  - Step 6: size++; 



# Circularly-linked Lists

- The next field in the last node in a Singly Linked List is set to NULL.
- Moving along a Singly linked list has to be done in a watchful manner.
- Doubly-Linked lists have two NULL pointers: prev in first node and next in last node.
- A way around this potential hazard is to link the last node with the first node in the list to create a _circularly-linked list_.



Two views of Circularly-Linked Lists

​	![](https://imgur.com/bKCahLC.png)

![](https://imgur.com/ierA7V4.png)



 

Note: Doubly Linked list can also be made into Circularly linked list.

## Josephus Problem

- A case where Circular-linked list comes in handy is the solution of the Josephus Problem.
- Consider there are 10 persons. They would like to choose a leader.
- The way they decide is that all 10 sit in a circle.
- They start a count with person 1 and go in clockwise direction and skip 3. Person 4 reached is eliminated.
- The count starts with the fifth and the next person to go is fourth in the count.
- Eventually a single person remains.

  

![](https://imgur.com/mwjb2Br.png)

![](https://imgur.com/5JQsLH1.png)

