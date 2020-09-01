#include <iostream>
#include <vector>







using namespace std;




class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>&check,int start){
        if(check[start]!=0)
            return check[start]==1;
        check[start]=2;
        for(int i=0;i<graph[start].size();i++){
            if(!dfs(graph,check,graph[start][i]))
                return false;
        }
        check[start]=1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>check(graph.size(),0);
        vector<int>ans;
        for(int i=0;i<graph.size();i++){
            if(dfs(graph,check,i)) ans.push_back(i);
        }
        return ans;
    }
};
