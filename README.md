HW7

Github: https://github.com/lding-code/EE599-HW7

Q1

1. A path in a graph is a set of connected edges that connects one vertex to another.
2. A simple path is a path that does not have cycles (no repeated vertices).
3. A cycle is a path in which a vertex is included for multiple times in a path.
4. Topological sort is defined in graphs that are directed and acyclic. In topological sort, origin vertices always come before destination vertices.

Q2

see inclueded png picture "Q2 Floyd-Warshall.png".

Q3

3.1: implemented as BFS_dist() method of Graph class. The return value is a map of shortest distances to all nodes.

Runtime = O(E+V): every node and edge is visited once. The distance to each  node is simply calculated by adding 1 to distance to the previous visited node during the BFS. The complexity is not changed by introducing such addition.

3.2: implemented as BFS_path() method of Graph class. The return calue is a map of nodes and corresponding vector representing shortest path to each node.
Runtime = O (E+V): same reason as 3.1

Q4

The function is splitted into two methods:
4.1: findRoot() of class Graph that finds root nodes.

Runtime = O(E+V): each node and edge are visited for once to find the root nodes.

4.2: topoSort() of class Graph that finds topological sort of the graph.

Runtime = O(E+V+E+V) = O(2(E+V)) = O(E+V): a DFS is used to traverse all nodes and find deepest nodes possible and put them in a stack. After ndoes are pushed into stack in the order of depth. The stack is popped to get the topological sort. Traversal takes O(E+V) and using the stack take another O(E+V)

Q5

implemented as inShortest() methods of class Graph. It utilizes a helper function inShortestHelper() that traverses the graph recursively using DFS and return true if a shrotest path is reached. Comments in the source file explains how it is implemented.

Runtime = O(E+V): In worst case, all nodes will be visited which takes O(E+V). it could take less time if the "end node" is not at the very end (largest depth) of the graph.  

All code passed GTest. Please see comment for implementation details.