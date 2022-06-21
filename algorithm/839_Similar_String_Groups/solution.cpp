#include <vector>
#include <string>


class Solution {
public:
    int parent[301];
    bool help(string &a,string &b){
        int c=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                c++;
            }
            if(c==3)return false; 
        }
        return true;
    }
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }
    void uni(int a, int b){
        a=find(a);
        b=find(b);
        parent[a]=b;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(help(strs[i],strs[j])){
                    uni(i,j);
                }
            }
                   
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i)ans++;
        }
        return ans;
    }
};
