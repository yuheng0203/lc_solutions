class Solution {
public:
    vector<vector<int>> graph;
    vector<int> color;

    bool dfs(int node, int c)
    {
        color[node] = c;

        for(int next : graph[node])
        {
            if(color[next] == c)
                return false;

            if(color[next] == 0)
            {
                if(!dfs(next, -c))
                    return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes)
    {
        graph.resize(n + 1);
        color.resize(n + 1, 0);

        for(auto &d : dislikes)
        {
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }

        for(int i = 1; i <= n; i++)
        {
            if(color[i] == 0)
            {
                if(!dfs(i, 1))
                    return false;
            }
        }

        return true;
    }
};