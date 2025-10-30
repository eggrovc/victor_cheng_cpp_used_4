# victor_cheng_cpp_used_4

### Q2 
## Algorithm Explanation 
For question 2, I read the input file for q2 andtxt initialized my graph in an adjacency list with a map that holds strings to hold x1 .. or alphabet chars and a vector to hold its neighboring nodes. Then I called another function to start a version of Depth First Search approach on seeing if this graph is cyclic or not this search will look through the . I created a set of visited nodes so there arent any repeated values and another map to hold the parent values of my nodes. Then by calling a DFS implemented function which finds the largest path a graph can take, if a nodes neighboring node is already visited and is not the parent of the node there are cycles, else if the node is unvisited or is the parent of the node then move on this makes it so there wont be any loops between two nodes. 


## Results
# a)
x2, y3, x3, y1, x2

Running Time: 58 microseconds.

# b)
c, b, a, c

#Running Time: 25 microseconds.

### Q5
## Algorithm Explanation
For question 5, similary with 2 I read and initialized my graph the same way except all my nodes are inputed into both my set of all nodes and map graph. But then measure the time, edge type between each two vertices, and then to topologically sort them. To do this, I initialized 3 more vectors to hold again my visited nodes for my DFS which holds 3 colors, 0 = white, 1 = gray, 2 = black, then discovery and finish time for my topological sort. While going through every unique allNode (unique because if there was a loop it would be a back edge and could cause and infinite loop), if visited was white then it would call DFS on that node. Everytime the pointer moves to another node, discoverytime increments by 1 and the time for that node is set. Now for the node that is passed through the DFS we check our graph that holds its neighbors, if its first neighbor is unvisited (white in the visited vector), run DFS on my graph recursively and mark that edge as a Tree Edge and gray, however if the neighbor node was black or visited = 2 and the time that current node was discovered is less than neighboring node was discovered mark the edge as a cross edge, else it is a forward edge for neighboring > current node. Then the original node searched in the DFS is now set to black (visited = 2) after it finishes all its paths and the finish time being the current finish time. Then its node value push_back into the vector. 

At the end to sort in topological order I had to reverse my vector because it was in the reverse order so node 6 can come before node 5 etc.. 


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

# Running Time: 
765 microseconds.


### Q10 or B1
## Algorithm Explanation
And again similarly to the other 2 questions, for B1, I initialized my graph similarly except if the node inserted was alone without a prerequisit then nothing would be added to the adjacency lists so it would not over count the max number of sums for a non existent prerequisit. Then for every node starting at the courses without prerequisits using a depth first search way, then using the neighbors of that node, it searches for the longest pathed semester and returns that to compare with the current longest. At the end 5 semesters was the longest time itll take for us to complete our degree.


## Results
Minimum Semesters Required: 5

Running Time: 
641 microseconds.

### Q11 or B2
## Algorithm Explanation
In question 11 or B part 2, I initialized all my values into matrix that holds vectors of vectors. Each element of the matrix will hold the line of values that represent the constraints of the problem. Then my graphicalSol function will increment through my matrix to compare every line with each other to find the intersection coordinates of the constraint lines. Which then is passed into check if it even fits the constraint conditions, if it does push it into the solutions vector. Now using the possible solutions that are valid, we will find the solution that results in the lowest costs using our objective function and the coordinates, P = 0.12x + 0.15y.

The time complexity is O(N^3) because in my graphicalSol function there are 2 nested loops which checks every value of my matrix, which then calls the check function to make sure my coordinate values are within the bounded restrictions as in the number of calories in the total amount of both drinks doesnt go over the maximum allowed calories. 
Time Complexity: O(N^3)

## Results
Minimum Cost: 0.66
# of X drinks: 3
# of Y drinks: 2


# Running Time: 
980 microseconds.