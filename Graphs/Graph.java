class Graph {
    public Node[] nodes;
}

class Node {
    public String name;
    // Neighbours
    public Node[] children; 
}


// An Adjacency list can also be used
// but it's usually more clean 
// to make a class

// DFS is preferred when you need to 
// visit every node in the graph.

// It's a bit simplert than BFS, but
// both could work.

// For finding shortest (or any) path
// a BFS is generally preferred.

