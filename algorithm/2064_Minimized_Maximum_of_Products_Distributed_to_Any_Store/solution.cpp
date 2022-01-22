#include <vector>
#include <algorithm>

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=0;
        int r=0;
        for(auto &q:quantities){
            r=max(r,q);
        }
        while(l+1<r){
            int m=l+(r-l)/2;
            int stores=0;
            for(auto &q:quantities){
                if(q%m)stores+=1;
                stores+=q/m;
            }
            if(stores<=n){
                r=m;
            }
            else l=m;
        }
        return r;
    }
};
