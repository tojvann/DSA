### _Lecture 1_

## Cover well-known data structures such as:

- Dynamic Arrays
- Linked List
- Stacks
- Queues
- Tree
- Graphs



_All the Data Structures are implemented in C++_



### Need for Data Structures

- Data structures organize data, this leads to more efficient programs. By efficiency i mean efficient in terms of both time and space.
- More powerful computer => More complex applications => Demand more calculations





> The choice of a data-structure and algorithm can make the difference between a program running in  a few seconds or many days.





## Efficiency

- A solution is said to be efficient if it solves the problem within its resource constraints.
  - Space
  - Time
- The cost of a solution is the amount of resources that solution consumes.





## Selecting a Data-Structure

1. Analyze the problem to determine the resource constraints a solution must meet.
2. Determine the basic operation that must be supported. Quantify the resource constraints for each operation.
3. Select the data structure that best meets these requirements





## Some questions to ask

- Are all the data inserted into the data structure at the beginning, or are insertions interspersed with other operations ?
- Can data be deleted ?
- Are all data processed is some well-defined order, or is random access allowed ?





## Data-Structure Philosophy

- Each  data structure has cost and benefits.
- Rarely is one data structure better than another in all situations.
- A data structure requires:
  - space for each data  item it stores
  - time to perform each basic operation
  - programming effort





# Arrays

Elementary data structure that exists as built-in in most programming languages.

- Array declaration: 

​		<data-type>  array-name [array-size] ;		

​		 int x[6] ;

- An array is  collection of cells of the same type.
- The collection has the name 'x'
- The cells are numbered with consecutive integers.
- To access a cell, use the array name and an index:
  - x[0], x[1], x[2], x[3], x[4], x[5]

Array cells are contiguous in computer memory.

The memory can be thought of as an array.

![Array Layout](https://imgur.com/j2IxQMx.png)

​	_Array layout_

### What is Array name ?

- 'x' is an array name but there is no variable x. 'x' is not an  _lvalue_

  - _lvalue_ are those variable in an assignment / expression that can appear on the left side, i.e. _lvalue_ refers to a location in memory.

  - Example: 

  - ```
    int a, b;
    // we can write
    b = 2;
    a = b;    //copy value of b in variable a
    a = 5;
    //Bit we cannot write
    2 = a;
    // since 2 is not a lvalue it is a constant
    ```

  - ```
    // x is not a lvalue
    int x[6];
    int n;
    x[0] = 5;
    x[1] = 2;
    // following statements are not allowed
    x = 3;
    x = a + b;
    x = &n;  //name of the array is const pointer to the first element of the array
    ```



## Dynamic Arrays

- You would like to use the array data-structure but you do not know the size of the array at compile time.

- You find out when the program executes that you need an integer array of size n = 20

- Allocate an array using the new operator:

- ```
  int* y = new int[20];
  y[0] = 10;
  y[1] = 13;
  ```

- NOTE: Here y is an _lvalue_; it is a pointer that holds the address of 20 consecutive cells in the memory(starting address).

- It can be assigned a value. The new operator return an address that is store in y.

- We can write:

  - y = &x[0] ;
  - y = x ;  //x can appear on the right; y gets the address of the first cell of the x array

- We must free the memory we got using the new operator once we are done with the y array.

- ```
  delete[] y;
  ```

- We would not do this to x array because we did not use new to create it.



## The LIST Data Structure

- The list is among the most generic of data structures.
- Real life examples:
  - shopping list
  - groceries list
  - list of people to invite for a party
- A list is a collection of items that are all of the __same type__ (grocery items, integers, names)
- The items, or elements of the list, are stored in some particular order.
- It is possible to insert new elements into various positions in the list and remove any element of the list.
- List is a set of elements in a linear order.
  - For example: data values a1, a2, a3, a4 can be arranged in a list:
  - (a3, a1, a2, a4)
  - In this list, a3 is the first element, a1 is the second element, and so on.
- The order is important here; This is not just a random collection of elements, it is an ordered collection.



## List operations

- createList(): create a new list; (presumably empty)
- copy(): set one list to be a copy of  another.
- clear(): clear a list (remove all elements)
- insert(X, ?): Insert element X at a particular position in the list.
- remove(): Remove element at some position in the list.
- update(X, ?): replace the element at a given position with X.
- find(X): determine if the element X is present in the list.
- length(): return the length of the list.



We need to decide what is meant by "particular position"; we have used "?" for this.

There are two possibilities.

- use the actual index element: insert after element 3, get element number 6; This approach is used by arrays.
- Use a "current" marker or a pointer to refer to a particular position in the list.
- If we use the "current" marker, the following four methods would be useful:
  - start(): moves the "current" pointer to the very first element.
  - tail(): moves the "current" pointer to the very last element.
  - next(): move the current position forward one element.
  - back(): move the current position backward one element.



