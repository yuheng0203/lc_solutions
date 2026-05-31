class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;

    bool dfs(int node, int destination) {
        if (node == destination)
            return true;

        visited[node] = true;

        for (int next : graph[node]) {
            if (!visited[next]) {
                if (dfs(next, destination))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        graph.resize(n);
        visited.resize(n, false);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        return dfs(source, destination);
    }
};
