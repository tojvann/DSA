# Linked List

> It is Data Structure used for storing collection of data.

Some exclusive features of Linked List

- Successive elements are connected by pointers.
- Last element points to NULL.
- Can grow or shrink in size during execution of program.
- Can be made as long as required, `during Runtime unlike Arrays` , until system's memory exhausts.
- It does not waste memory space but takes some extra memory for pointers.

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist.png)

## Linked List ADT  (Abstract Data Type)

### LL Main operations

- `Insert`: insert an element into the list.
- `Delete`: removes and returns the specified position element from the list

### LL Auxiliary operations

- `Delete List`: removes all elements of the list (disposes the list).
- `Count`: returns the number of elements in the list.
- Find nth node from the end of the list. (Counting from right (tail) i.e. we need to maintain a tail pointer as well)

## Differences between Linked List and Arrays

- `Arrays`

  - In case of an array one contiguous memory block is allocated for the entire elements of the array.

    Because of this array elements can be accessed in a constant time using the index of the particular element as the subscript.

### The concept of constant access time to access elements of an array

- To access an array element, address of an element is computed as an offset from the base address of the array and one multiplication is needed to compute what is supposed to be added to the base address to get  the memory address of the element.
  - General formula to compute the memory location of an element of an array
    - `Element Address` = `Base Address `+ `Type of Data Type(Bytes required)` * `index of the element`
  - This process takes one multiplication and one addition.` Since these two operations take constant time`, we can say that the array access can be performed in a constant time.

### Advantages of Arrays:

- Simple and Easy to use.
- Faster access to the elements(Constant time)

### Disadvantages of Arrays:

- `Fixed Size:` The size of the array is static i.e. we need to specify the size of the array before using it. *Although there exists the concept of dynamic array where the size of the array is specified in runtime but still once the size of the array is specified it cannot be changed.*
- `One Block Allocation:` To allocate an array at the beginning itself, sometimes it may not be possible to get the memory for the complete array (if the size is big).
- `Complex position based insertion:` To insert an element at a given position we may need to shift the existing elements. This will create a position for us to insert the new element at the desired position. If the position at which we want to insert an elements is at the beginning then the shifting operation is very expensive. ***The more the insertion is towards the beginning of the array the costlier is the insertion operation.***



### Dynamic Arrays

Other names for Dynamic arrays are: Grow-able arrays, Re-sizable arrays, dynamic table, Array list.

- Dynamic array is a random access variable size list Data Structure that allows elements to be added or removed.
- One simple way of implementing dynamic array is, initially start with some fixed size array. As soon as that array becomes full, create the new array of size double than the original array. Similarly, reduce the array size to half if the elements in the array are less than half.



### Advantages of Linked Lists

- `Constant time expansion:` Linked list can be expanded in constant time. With linked list we can start with space for just one element allocated and add on new elements without the need to do any copying and reallocating.

### Disadvantages of Linked Lists

- `Slow access time to individual elements: ` Array has random access i.e. it takes O(1) to access any element in the array. `Linked list takes O(n) for access of an element in the list in the worst case`.
- `Lack of spatial locality in memory:` Arrays are defined as contiguous blocks of memory, so any element will be physically near its neighbor . This greatly benefits from modern CPU caching methods.
  - Although dynamic allocation of storage is a great advantage, the overhead with storing and retrieving data can make a big difference. Sometimes linked lists are `hard to  manipulate`. If the last item is deleted, the last but one must now have its pointer changed to hold a NULL reference. This requires that the list is traversed to find the last but one link, and its pointer set to NULL reference.
- `Memory wastage: ` Linked list wastes memory in terms of extra reference points. 





