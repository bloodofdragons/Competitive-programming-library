// UNION-FIND
//n = no. of nodes
//set_size = no. of components
struct UnionFind
{
    int n, set_size, *parent, *rank;

    UnionFind() {}

    // initialize
    UnionFind(int a)
    {
        n = set_size = a;
        parent = new int[n + 1]; // [1,n]
        rank = new int[n + 1];  // [1,n]

        for(int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    // find the parent of node "x"
    int find(int x)
    {
        // if parent of the node is not itself
        // then search for it's parent.
        if(x != parent[x])
        {
            return parent[x] = find(parent[x]);
        }
        return x;
    }

    // merge the two trees having nodes x and y
    // if both belongs to same component then don't merge
    void merge(int x, int y)
    {
        int xroot = find(x), yroot = find(y);

        if(xroot != yroot)
        {
            // smaller to larger technique
            if(rank[xroot] >= rank[yroot])
            {
                parent[yroot] = xroot;
                rank[xroot] += rank[yroot];
            }
            else
            {
                parent[xroot] = yroot;
                rank[yroot] += rank[xroot];
            }
            set_size -= 1;  // merge two trees decrease CC by 1
        }
    }

    void reset()    // re-initialize
    {
        set_size = n;
        for(auto i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
};
