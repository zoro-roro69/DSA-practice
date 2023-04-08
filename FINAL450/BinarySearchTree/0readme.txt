A tree is a data structure composed of nodes that has the following characteristics:

    1. Each tree has a root node (at the top) having some value.
    2. The root node has zero or more child nodes.
    3. Each child node has zero or more child nodes, and so on. This create a subtree in the tree. Every node has it’s own subtree made up of his children and their children, etc. This means that every node on its own can be a tree.


A binary search tree (BST) adds these two characteristics:

    1. Each node has a maximum of up to two children.
    2. For each node, the values of its left descendent nodes are less than that of the current node, which in turn is less than the right descendent nodes (if any)

Complexity is O(logn) for searching, insertion and deletion

    The BST is built up on the idea of the binary search algorithm, which allows for fast lookup,
    insertion and removal of nodes. The way that they are set up means that, on average, each comparison
    allows the operations to skip about half of the tree, so that each lookup, insertion or deletion takes
    time proportional to the logarithm of the number of items stored in the tree, O(log n)

But becomes O(n) in worst case scenario

    However, some times the worst case can happen, when the tree isn’t 
    balanced and the time complexity is O(n) for all three of these functions. 
    That is why self-balancing trees (AVL, red-black, etc.) are a lot more 
    effective than the basic BST.

    Worst case scenario example: This can happen when you keep adding nodes that
    are always larger than the node before (it’s parent), the same can happen when 
    you always add nodes with values lower than their parents.

the InOrder traversal of a binary search tree gives an ascending sorted array.

Basic operations on a BST

    Create: creates an empty tree.
    Insert: insert a node in the tree.
    Search: Searches for a node in the tree.
    Delete: deletes a node from the tree.

    Create
        Initially an empty tree without any nodes is created. The variable/identifier which must point to the root node is initialized with a NULL value.

    Search
        You always start searching the tree at the root node and go down from there. You 
        compare the data in each node with the one you are looking for. If the compared node 
        doesn’t match then you either proceed to the right child or the left child, which depends
        on the outcome of the following comparison: If the node that you are searching for is 
        lower than the one you were comparing it with, you proceed to to the left child, otherwise 
        (if it’s larger) you go to the right child. Why? Because the BST is structured (as per its definition), 
        that the right child is always larger than the parent and the left child is always lesser.

    Insert
        It is very similar to the search function. You again start at the root of the tree 
        and go down recursively, searching for the right place to insert our new node, in
        the same way as explained in the search function. If a node with the same value is
        already in the tree, you can choose to either insert the duplicate or not. Some trees
        allow duplicates, some don’t. It depends on the certain implementation

    Delete

        There are 3 cases that can happen when you are trying to delete a node. If it has,

            1. No subtree (no children): This one is the easiest one. You can simply just delete the node, without any additional actions required.
            2. One subtree (one child): You have to make sure that after the node is deleted, its child is then connected to the deleted node’s parent.
            3. Two subtrees (two children): You have to find and replace the node you want to delete with its successor (the letfmost node in the right subtree).

The time complexity for creating a tree is O(1). The time complexity for searching, inserting or 
deleting a node depends on the height of the tree h, so the worst case is O(h).

Real-time Application of Binary Search tree:

    BSTs are used for indexing in databases.
    It is used to implement searching algorithms.
    BSTs are used to implement Huffman coding algorithm.
    It is also used to implement dictionaries.
    Used for data caching.
    Used in Priority queues.
    Used in spell checkers

Advantages of Binary Search Tree:

    BST is fast in insertion and deletion when balanced. It is fast with a time complexity of O(log n).
    BST is also for fast searching, with a time complexity of O(log n) for most operations. 
    BST is efficient. It is efficient because they only store the elements and do not require additional memory for pointers or other data structures.
    We can also do range queries – find keys between N and M (N <= M).
    BST code is simple as compared to other data structures.
    BST can automatically sort elements as they are inserted, so the elements are always stored in a sorted order.
    BST can be easily modified to store additional data or to support other operations. This makes it flexible.

Disadvantages of Binary Search Tree:

    The main disadvantage is that we should always implement a balanced binary search tree.Otherwise the cost of operations may not be logarithmic and degenerate into a linear search on an array.
    They are not well-suited for data structures that need to be accessed randomly, since the time complexity for search, insert, and delete operations is O(log n), which is good for large data sets, but not as fast as some other data structures such as arrays or hash tables.
    A BST can be imbalanced or degenerated which can increase the complexity.
    Do not support some operations that are possible with ordered data structures.
    They are not guaranteed to be balanced, which means that in the worst case, the height of the tree could be O(n) and the time complexity for operations could degrade to O(n). 
