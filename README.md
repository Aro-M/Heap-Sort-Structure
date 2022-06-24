# Heap-Sort-Structure 

Introduction to Heap in Data Structures

A Heap is a special Tree-based data structure in which the tree is a complete binary tree. Generally, Heaps can be of two types:

Max-Heap: In a Max-Heap the key present at the root node must be greatest among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.

Min-Heap: In a Min-Heap the key present at the root node must be minimum among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.


![2](https://user-images.githubusercontent.com/58858618/175516059-827fcb47-c64e-4da8-b7b8-7a4d3f46ee68.png)


Time complexity in big O notation

Algorithm		                 Average	     Worst case

Insert		                    O(log n)      O(log n)

Delete		                    O(log n)      O(log n)


The elements in the data structure are T type (template).

I have performed these functions։
insert () --- This function enters my values
 
height () --- This function shows the height of my heap

parent () --- This function shows the value of my parent

max_heapify () --- This function sorts Max Heap and Min Heap

delete_element ()  --- I pass a value to this function, if it finds a value, remove it and sort again, if it doesn't find the same value, it returns

extract_max_element () --- Returns the largest value in the case of Max heap and returns the significant value in the case of Min heap

left () --- Returns the left child nodes

right () --- Returns the left child nodes

linear_search () --- Passes the meaning of this function, if it finds the meaning, returns the index, if it does not return, returns -1

void print()  --- Prints Max Heap or Min Heap։

Same functions for min_heap

And a few other helpful functions։


I also made these constructors

---Default constructor:

---Constructor with parameters (+std::initializer_list)

---Copy constructor:

---Move constructor:

---Destructor:

I also made these operators

---Copy operator assignment =

---Move operator assignment =

---Operator stream out (cout) <<

---Operator is equal to ==

---Operator not equal to !=

---Operator +, +=



