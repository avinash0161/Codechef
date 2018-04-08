//https://leetcode.com/contest/weekly-contest-75/problems/all-paths-from-source-to-target/

class Solution {
public:
    
    vector<vector<int>> FindPath(vector<bool> visited, int node, vector<int> path, vector<vector<int>> graph)
    {
        vector<vector<int>> ret;
        if(visited[node] == true)
        {
            return ret;
        }
        else
        {
            visited[node] = true;
            path.push_back(node);
            
            if(node==graph.size() - 1)
            {
                ret.push_back(path);
                return ret;
            }
            else
            {
                for(int i=0; i<graph[node].size(); i++)
                {
                    vector<vector<int>> allPaths = FindPath(visited, graph[node][i], path, graph);
                    for(int j=0; j<allPaths.size(); j++)
                    {
                        ret.push_back(allPaths[j]);
                    }
                }
                
                return ret;
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<bool> visited;
        vector<int> path;
        visited.resize(graph.size());
        
        visited[0] = true;
        path.push_back(0);
        
        vector<vector<int>> allPaths;
        for(int i=0; i<graph[0].size(); i++)
        {
            vector<vector<int>> ret = FindPath(visited, graph[0][i], path, graph);
            for(int j=0; j<ret.size(); j++)
            {
                        allPaths.push_back(ret[j]);
            }
        }
        return allPaths;
    }
};
