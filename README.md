# victor_cheng_cpp_used_4

### Q2 
## Algorithm Explanation 
For question 2, I read the input file for q2 and initialized my graph in an adjaceny matrix in a map that holds strings to hold x1 .. or alphabet chars and a vector to hold its neighboring nodes. Then I called another function to start a version of Depth First Search approach on seeing if this graph is cyclic or not. I created a set of visited nodes so there arent any repeated values and another map to hold the parent values of my nodes. Then by calling a DFS implemented function which finds the largest path a graph can take, if a nodes neighboring node is already visited and is not the parent of the node there are cycles, else if the node is unvisited or is the parent of the node move on. 

This comes to O(V * S) for my visited map of nodes, another O(V*S) for the parentMap comparison and O(V) for the recursion stack. 
Time Complexity: O(V*S)

## Results
# a)
x2, y3, x3, y1, x2

Running Time: 58 microseconds.

# b)
c, b, a, c

#Running Time: 25 microseconds.

### Q5
## Algorithm Explanation
For question 5, similary with 2 I read and initialized my graph the same way except all my nodes are inputed into both my set of all nodes and map graph. But then measure the time, edge type between each two vertices, and then to topologically sort them. To do this, I initialized 3 more maps to hold again my visited nodes for my DFS which holds 3 colors, 0 = white, 1 = gray, 2 = black, then discovery and finish time for my topological sort, each as a map that holds two ints. While going through every unique allNode (unique because if there was a loop it would be a back edge and could cause and infinite loop), if visited was white then it would call DFS on that node. Everytime the pointer moves to another node, discoverytime increments by 1. Now for the node that is using the DFS we check our graph that holds its neighbors, if its first neighbor is unvisited (white in the visited map), run DFS on that map recursively and mark that edge as a Tree Edge, however if the neighbor was black or visited = 2 and the time that current node was discovered is less than neighboring node was discovered mark the edge as a forward edge, else it is a cross edge for neighboring > current node. Then the original node searched in the DFS is now set to black (visited = 2) and the finish time being the current finish time. Then push_back into the vector. 

At the end to sort in topological order I had to reverse my vector because it was in the reverse order. node 6 comes before node 5 etc.. 

The time complexity is O(V+E) due to O(V+E) for the depth first search algorithm implemented and then O(V) for reversing the results of DFS which comes down to O(V+E).
Time Complexity: O(V+E).

## Results
# Topological sorted nodes in sequence

Edge (1, 2) -- Type: T (Tree)
Edge (2, 3) -- Type: T (Tree)
Edge (2, 7) -- Type: T (Tree)
Edge (7, 3) -- Type: C (Cross)
Edge (1, 4) -- Type: T (Tree)
Edge (4, 8) -- Type: T (Tree)
Edge (1, 7) -- Type: F (Forward)
Edge (5, 2) -- Type: C (Cross)
Edge (5, 3) -- Type: C (Cross)
Edge (6, 2) -- Type: C (Cross)
Edge (6, 4) -- Type: C (Cross)
Edge (6, 5) -- Type: C (Cross)


6 5 1 4 8 2 7 3 

Running Time: 
1317 microseconds.


### Q10 or B1
## Algorithm Explanation

## Results
Minimum Semesters Required: 5

Running Time: 
641 microseconds.

### Q11 or B2
## Algorithm Explanation
# Pseudo Code Explanation

## Results
Minimum Cost: $0.66
Cups of Drink X: 3
Cups of Drink Y: 2