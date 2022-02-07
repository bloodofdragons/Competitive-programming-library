:~ Graph is denoted by :- G(V,E) where 'V' is vertex set and 'E' is edge set 

:~ There is also a general input format like 'N' nodes and 'M' edges

:~ Un/Weighted --> If all the edges are of "same kind" then unweighted else weighted

:~ Undirected / Bidirectional --> We can move from 1 to 2 and 2 to 1 using the same edge. (A---B)

:~ Directed / Unidirectional --> There is a direction associated with the edge.   (A--->B)

:~ Sparse / dense --> If there are 'N' nodes then there can be O(N^2) edges. So, the range of edges is O(1) to O(N^2)
                      If number of edges <= O(N.sqrt(N)) then we can consider it Sparse else it's dense. Most of the 
                      inputs will be sparse graph. (N<=10^5 and M<=10^5)

:~ In/Out degree --> There is no in/out in undirected graphs. There is only degree which is equal to the number of edges 
                     connected to any node. We can also see degree as number of neighbours a particular node has.

                     In directed graphs, Indegree = Number of edges coming towards the node.
                                         Outdegree = Number of edges going away from the node.

:~ Path --> The route which we follow to go from one node to another node.
            Path allows repetition but in "simple paths" there is no repetition.

            Ex :- V1 V2 V3 ----- Vk


:~ Cycle --> If there is a path (V1 V2 V3 ---- Vk) then if (V1==Vk) then it is a cycle.
             Basically, you end from where you start. 


:~ Isolated --> All alone. There is no edge associated with the node. OR the degree is 0.
                (note:- the node can contain self-loop)


:~ Reachable --> Two nodes are reachable from each other if there is some path between them.

:~ Connected --> Some nodes will be said connected if there is some path between any two nodes.

:~ Self loop --> If there is an edge starting at the same node and ending at the same node.

:~ Multiple edges --> There can be two edges from node 'A' to node 'B'. (Ex:- there can be 2 roads between two cities)
                      The direction of both the edges in a directed graph goes from node 'A' to node 'B'.

:~ Simple graph --> Any graph which doesn't contain self loop and multiple edges are known as simple graph.
                    Generally, we are given simple graphs in a problem. 

:~ Multigraph --> Any graph which is not a simple graph is multigraph.


:~ Sub-graph --> A graph G'(V',E') is subgraph of G(V,E) if V' is subset of V and E' is subset of E.

:~ Directed acyclic graph (DAG) --> A graph which is directed and contains no cycle.


:~ Tree --> A graph is called tree if it satisfies following conditions :-
            
            1- There are 'N' nodes and 'N-1' edges in the graph.
            2- All the nodes are connected.
            3- There always exist a path between any two nodes in a graph.
            4- Graph doesn't contains a cycle. (Min. edges required to connect all nodes if there is cycle = 'N' edges)


:~ Forest --> If a graph is collection of trees inside it then it is known as forest.
              Basically, there are more than 1 connected components and all the components are trees.



:~ Eulerian path --> A path in which each 'edge' is covered exactly once.



:~ Hamiltonian path --> A path in which each 'node' is visited only once.



:~ Bipartite --> If you can colour a graph with 2 colours such that no two neighbouring nodes have same colour, then
                 the graph is known as 2-colourable graph or bipartite graph.

                 We can also say, that we have to divide the nodes into two sets such that there is no connection
                 between the nodes of the same set.

                 Sometimes, bipartite graphs are represented by K(n,m) i.e. n nodes on left side and m nodes on right side.


:~ Complete graph :- Every two node should have edge between them. 
                     A complete graph of 'n' nodes is represented by K(n).

                     

