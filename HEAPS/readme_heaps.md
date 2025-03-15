**INTRODUCTION**
1. Heaps are a complete Binary trees that come with HEAP order property
2. Mostly used for 
- priority Queues 
- Dijkstra's algorithm 
- Heapsort

Complete Binary trees --> two properties 
- every level is completely filled expect last level
- Nodes always added from the left lean towards the left


HEAP order property --> two types 
1. Max heap : Every parent is bigger than child 
2. Min Leap : Every child is bigger than parent 




How to delete the node(root node)?
1. First, when we delete → Swap the last node in the array with the root node
- Since the heap is a complete binary tree, we replace the root node with the last element in the array.
2. Pop the last number in the array
- Reduce the size of the heap to remove the last element (which was swapped to the root).

3. Restore the heap property using Heapify Down (Max-Heapify)
- Start at the root (index = 1).
- Compare it with its left and right children.
- Swap it with the largest child if it's smaller.
- Continue this process recursively until the heap property is restored (i.e., no swaps are needed).


Heapify Algorithm or Heap Sort: 
Heap sort is a comparison-based sorting technique based on Binary Heap Data Structure. It can be seen as an optimization over selection sort where we first find the max (or min) element and swap it with the last (or first). We repeat the same process for the remaining elements. In Heap Sort, we use Binary Heap so that we can quickly find and move the max element in O(Log n) instead of O(n) and hence achieve the O(n Log n) time complexity.

