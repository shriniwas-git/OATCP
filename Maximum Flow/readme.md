Input:
The input consists of a flow network represented as a graph with vertices and directed edges.
Each edge has a capacity representing the maximum flow it can carry.
Initialization:
Initialize the residual graph to be the same as the given graph. The residual graph will be used to keep track of remaining capacity in each edge after flow is sent through it.
Initialize the flow to 0.
Augmenting Paths:
Find an augmenting path from the source to the sink in the residual graph. An augmenting path is a simple path from source to sink such that all edges on the path have residual capacity greater than 0.
If no augmenting path exists, terminate. The flow is now at its maximum.
Update Flow:
Determine the maximum flow that can be sent along the augmenting path. This is the minimum residual capacity of the edges on the path.
Update the flow along the augmenting path by adding the maximum flow determined in the previous step.
Update the residual capacities of the edges on the augmenting path: subtract the flow from forward edges and add the flow to backward edges.
Repeat:
Repeat steps Augmenting Path and Update Flow until no augmenting path exists.
Output:
The value of the maximum flow is equal to the total flow leaving the source node.
The Ford-Fulkerson algorithm guarantees that each iteration increases the flow until no more augmenting paths can be found, at which point the maximum flow is achieved.

It's worth noting that the choice of method for finding augmenting paths can affect the efficiency and correctness of the algorithm. In the provided code, a Breadth-First Search (BFS) algorithm is used to find augmenting paths.