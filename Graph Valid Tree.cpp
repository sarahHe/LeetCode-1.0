//Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
//write a function to check whether these edges make up a valid tree.
//For example:
//Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
//Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

bool validTree(int n, vector<pair<int, int>>& edges) {
    vector<int> nodes(n,0);
    for(int i=0; i<n; i++)
        nodes[i] = i; // initially i's parent is i
    for(int i=0; i<edges.size(); i++){
        int f = edges[i].first;
        int s = edges[i].second;
        while(nodes[f]!=f) // means node[f] has a parent
            f = nodes[f]; // find the root parent
        while(nodes[s]!=s)
            s = nodes[s];
        if(nodes[f] == nodes[s])
            return false;
        nodes[s] = f; // update its parent
    }
    return edges.size() == n-1; // make sure each node is visted,this has to be a connected graph
}
