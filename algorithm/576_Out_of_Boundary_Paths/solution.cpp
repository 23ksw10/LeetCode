#include <iostream>

using namespace std;

class Solution {
public:
    long long ans=0;
    int ud[4]={-1,0,1,0};
    int lr[4]={0,1,0,-1};
    long long dp[51][51][51];
    long long mod=10e8+7;
    int dfs(int r, int c, int count, int m, int n){
        if(r==-1||r==m||c==-1||c==n)return 1;
        if(dp[count][r][c]!=-1)return dp[count][r][c]%mod;
        if(!count)return 0;
        dp[count][r][c]=0;

        for(int i=0;i<4;i++){
            int newR=r+ud[i];
            int newC=c+lr[i];
            dp[count][r][c] += (dfs(newR,newC,count-1,m,n)%mod);
        }
        return dp[count][r][c]%mod;

    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        fill_n(&dp[0][0][0],51*51*51,-1);
        return dfs(startRow,startColumn,maxMove,m,n);
    }
};
