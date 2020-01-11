### Lecture 2

# Implementing Lists

We have designed the `interface `for the list, we now must consider how to implement this `interface`.

- __Implementing list using an array__:

  for example, the list of integers (2,6,8,7,1) could be represented as:

  ![](https://imgur.com/Dwn44N9.png)

### add()	

- add(9); current position is 3. The new list would thus be: (2, 6, 8, 9, 7, 1)
- we will need to `shift` everything to the right of 8 one place to the right to make place for the new element '9'.

![](https://imgur.com/CuD4XDx.png)

​	Here we have done two operations in order to insert an element in between the list./

- Update the current pointer to now point to location 4
- Increase the size of the list by 1, since a new element is added in the list

### next()

![](https://imgur.com/MyQgx4G.png)

_note here we have used indexing tarting with 1_

- There are special cases for positioning the current pointer:

  - past the last array cell
  - before the first cell

  _The upper cases are boundary cases_

  We will have to worry about these cases when we write the actual code.

### remove()

- remove(): removes the element at the current index.
- ![](https://imgur.com/smQoOv5.png)
- ![](https://imgur.com/VASKscp.png)

Note: here we have done two operations in order to remove an element from the list.

1. Reduce the size of the list by 1.
2. Shift Left the elements to the right of the element to be removed.

_now the current pointer points to the element to the right of the element which was removed from the list i.e. 1_

### find(X)

- find(X): traverse the array until X is located.

- ```c++
  int find(int X)
  {
  	int j;
  	for(j = 1; j < size + 1; j++)
  		if(A[j] == X) 
              break;
      if(j < size + 1)	//found X
      {
      	current = j;    // current now points to where X is found
          return 1;       // 1 for true
      }
      return 0; 			// 0(false) indicates not found
  }
  ```

### Other operations:

- **get()** : return A[current];
- **update(X)**: A[current] = X;
- **length()**: return size;
- **back()**: current--;
- **start()**: current = 1;  // 1 based indexing 
- **end()**: current = size;



## Analysis of Array Lists

- **add**
  - we have to move every element to the right of current to make space for the new element.
  - `Worst-Case`: is when we insert at the beginning; we have to move every element right one place.
  - `Average-Case`: on average we have to move half of the elements
- __remove__
  - `Worst-Case`: remove at the beginning, must shift all remaining elements to the left.
  - `Average-Case`: expect to move half of the elements.
- __find__
  - `Worst-Case`: may have to search the entire array.
  - `Average-Case`: search at most half the array
- __Other operations__ are one-step.



## List using Linked Memory

- Various cells of memory are not allocated consecutively in memory.
- With Arrays, the second element was right next to the first element.
- In linked list, now the first element must explicitly tell us where to look for the second element.
- Do this by holding the memory address of the second element



### Linked List

- Create a structure called node.

  ![](https://imgur.com/3vMZZlW.png)

  

- The `object` field will hold the actual list element.

- The `next` field in the structure will hold the starting location of the next node.

- Chain the nodes together to form the `linked` list.

- Picture of our list (2, 6, 7, 8, 1) stored as a linked list:



![](https://imgur.com/Jevl9rb.png)

Note: some features of the list

- Need a `head` to point to the first node of the list. Otherwise we won't know where the start of the list is.
- The `current` here is a pointer not an index.
- The `next` field in the last node points to nothing. We will place the memory address `NULL` which is guaranteed to be inaccessible. 



### Linked List: Actual picture in memory

![](https://imgur.com/D0G7o3x.png)





