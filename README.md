# Data-Structures
## *_Simple implementation of different Algorithms_*

This repository contains simple implementations of data structures with example. Please message me for any doubt or query related to implementation.<br />
&nbsp;
Following ML algos has been implemented.<br />
1. Merge Sort
2. BST based on AVL tree
3. TRIE
4. Multiply Strings [Leetcode]
5. MinHeap & MaxHeap
6. Bit Manipulation

* ### *Merge Sort:*
It is divide & conquer based sorting algorithm.<br />
It first divides unsorted list into n sublist & then repeatedly merge sorted sublist till all sublists get merged.<br />
Below is the diagram from wikipedia visualising the merge-sort algorithm.

<p align="center">
  <img src="https://github.com/mayur-aggarwal/Data-Structures/blob/master/300px-Merge_sort_algorithm_diagram.svg.png">
</p>
<p align="center">Figure 1: Merge Sort.</p>

* ### *AVL Tree:*
It is also known as self balancing tree.

* ### *Trie:*
It is tree like data structure whose each node stores an alphabet.

* ### *Multiply strings:*
Explanation of algorithm to perform multiplication of two given numbers as strings and no inbuilt library used for converting int to str or vice versa.<br />
Below is the explanation of Multiply Strings:
<p align="center">
  <img src="https://github.com/mayur-aggarwal/Data-Structures/blob/master/MultiplyStrings_png/Multiply_Strings_1.png">
</p>
<p align="center">Figure 4.1.</p>

<p align="center">
  <img src="https://github.com/mayur-aggarwal/Data-Structures/blob/master/MultiplyStrings_png/Multiply_Strings_2.png">
</p>
<p align="center">Figure 4.2.</p>

<p align="center">
  <img src="https://github.com/mayur-aggarwal/Data-Structures/blob/master/MultiplyStrings_png/Multiply_Strings_3.png">
</p>
<p align="center">Figure 4.3.</p>

&nbsp;
* ### *Heap Sort:*
A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible (Source Wikipedia).<br />If the parent node is stored at index I, the left child can be calculated by 2 * i + 1 and right child by 2 * i + 2 (assuming the indexing starts at 0).<br />
#### MinHeap - the smallest item is stored at the root of the heap<br />
#### MaxHeap - the largest item is stored at the root of the heap<br />
&nbsp;Mainly all important API's are covered like<br />
i) extractMin()<br />
ii) deletekey(int idx)<br />
iii) changeValue(index, value)<br />
iv) MinHeapify<br />
v) MaxHeapify<br />
vi) Conversion from MinHeap to MaxHeap.<br />
&nbsp;

* ### *Bit Manipulation:* [Ref: https://graphics.stanford.edu/~seander/bithacks.html#CopyIntegerSign]
  [This is a relative link to a BitManipulation.cpp File](../master/Bit_Manipulation/BitManipulation.cpp)
