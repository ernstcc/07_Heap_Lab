07_HeapLab
==============

Implement a heap in C++

Requirements
------------

1. `add` and `remove` should be O(log n), except for `grow` which can be O(n)
2. Do not leak memory

Reading
=======
"Open Data Structures," Chapter 10, just the intro and section 1. http://opendatastructures.org/ods-cpp/10_Heaps.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. If grow is not called in the add function, then the runtimes of add and remove will be equal to the runtimes of bubbleUp and trickleDown respectively.  The runtimes for bubbleUp and trickleDown are O(log n) because each will need to traverse from the Heap root to the furthest leaf in the worst case.  If grow is called then the runtime will be O(n) because the entire Heap must be iterated and copied.      
2. The destructor and grow functions both delete unusuable objects.  

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
10.1) http://imgur.com/c4Ppp3j
 
10.2) http://imgur.com/KdUjSYt

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
By following Eytzinger's method, the locations of value within a d-ary tree are obtainable by using d, the number of children.  The process to find the parent of a node given an index is:   int parent = (index - 1)/d;
To the children on a given index will be stored in the index locations starting at d * index + 1 and ending at d * index + d.

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I spent the whole time trying to figure out why my program wasn't working and the tree had incorrect shape until I discovered a simple mistake of incrementing numItems too early in the add fucntion.  