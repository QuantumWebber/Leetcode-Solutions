class Solution {

    bool dfs(int node, int col,vector<vector<int>>& graph, vector<int> &color){


        // sabse pehel to node ko color krde 
        color[node]=col;

        for(auto nbr: graph[node]){
            if(color[nbr]==-1){

                if(dfs(nbr,1-col,graph,color)==false) 
                return false;
            }
            else if(color[nbr]==col){
                return false;
            }  // to bhai adjacent samer color
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        

         int n = graph.size();

        vector<int> color(n, -1);

    for(int i=0;i<n;i++){
       if (color[i] == -1) {

                if (dfs(i, 0, graph, color) == false)
                    return false;
            }
        }

        return true;
    }
};