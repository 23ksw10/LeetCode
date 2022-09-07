#include <string>

using namespace std;

class Solution {
public:
    int DP[2001][2001];

    bool checkPartitioning(string s) {
        if(s.size()==3)return true;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j)DP[i][j]=1;
                else if(j-i+1==2){
                    DP[i][j]=(s[i]==s[j]);
                }
                else{
                    DP[i][j]=((s[i]==s[j])&(DP[i+1][j-1]));
                }
            }
        }
        for(int i=0;i<=n-3;i++){
            for(int j=i+1;j<n-1;j++){
                if(DP[0][i]&&DP[i+1][j]&&DP[j+1][n-1])return true;
            }
        }
        return false;
    }
};
